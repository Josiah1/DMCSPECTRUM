#include <iostream>
#include <vector>
#include "TH1D.h"
#include "TAxis.h"
#include "TH2D.h"
#include "TTree.h"
#include "TFile.h"
#include "TF1.h"
#include "TChain.h"
#include <math.h>
#include "TSystem.h"
#include "Event.h"

using namespace std;

Event* tr;
int main(int argc, char** argv){
	Int_t mode;
	if(argc!=2){
		cout<<"Usage: ./pro modeNo"<<endl;
		return 1;
	}else{
		TString modeNo=argv[1];
		mode=modeNo.Atoi();
	}
	TChain* tree=new TChain("Event");
	TChain GenHeader("/Event/Gen/GenHeader");

	TString roodir="/dybfs2/users/lijj/FullChain/Project_m14a_mc/TWin/Vertex/ExamTruth/aileron/Output/";
	for(int i=1000001;i<=1001000;i++){
		TString file;
		if(mode==0) file=TString::Format(roodir+"/GdLS/out_Gd_%d.root",i);
		if(mode==1) file=TString::Format(roodir+"/LS/out_LS_%d.root",i);

		Bool_t ifexit=!(gSystem->AccessPathName(file));
		if(ifexit) {
			tree->Add(file);
			TString mcfiledir="/dybfs2/users/lijj/FullChain/Project_m14a_mc/Production/M14A/python/M14A/Output/";
			TString mcfile;
  			if(mode==0) mcfile=TString::Format(mcfiledir+"GdLS/toy_%d.root",i);
  			if(mode==1) mcfile=TString::Format(mcfiledir+"LS/toy_%d.root",i);
			GenHeader.Add(mcfile);
		}
	}

	int TotalEntries=tree->GetEntries();
	tr=new Event;
	tr->Init(tree);

	TFile* result;
	if(mode==0) result=new TFile("result_GdLS.root","RECREATE");
	if(mode==1) result=new TFile("result_LS.root","RECREATE");

	TH1D* hEp=new TH1D("hEp","",1000,0,15);
	hEp->SetXTitle("Prompt Energy [MeV]");
	hEp->SetYTitle("Entries");
	TH1D* hEd=new TH1D("hEd","",1000,0,15);
	hEd->SetXTitle("Delayed Energy [MeV]");
	hEd->SetYTitle("Entries");

	TH1D* hEdfit=new TH1D("hEdfit","",100,1,3);
	//first loop to calculate sigma
	for(int i=0;i<TotalEntries;i++){
		unsigned int localentry=tree->LoadTree(i);
		int ret=tr->GetEntry(localentry);
		if(ret==0) cout<<"Load Tree Failed."<<endl;
		
		if(tr->Fold==2) hEdfit->Fill(tr->E[1]);
	}

	TF1* fgaus=new TF1("fgaus","gaus(0)",1,3);
	fgaus->SetParNames("A","#mu","#sigma");
	//set initial values for fit
	fgaus->SetParameter(1,2.2);
	fgaus->SetParameter(2,0.2);
	fgaus->SetParameter(0,hEdfit->GetMaximum());

	//derive value of sigma
	hEdfit->Fit("fgaus","","",1.6,3);
	const double sigma=fgaus->GetParameter(2);
	const double mu=fgaus->GetParameter(1);

	//second loop to collect spectrums and values for effiency calculation
	cout<<"Total Entries: "<<TotalEntries<<endl;

	int eventOrigin=GenHeader.GetEntries();
	int eventNumber_Ep=0;
	int eventNumber_Tc=0;
	int eventNumber_Ed=0;
	int eventNumber_D=0;
	for(int i=0;i<TotalEntries;i++){
		unsigned int localentry=tree->LoadTree(i);
		int ret=tr->GetEntry(localentry);
		if(ret==0) cout<<"Load Tree Failed."<<endl;
		
		Double_t Ep=tr->E[0];
		if(Ep>1.5) eventNumber_Ep++;

		if(tr->Fold!=2) continue;
		//Fill energy spectrum
		Double_t Tc=tr->T2PrevSubEvt[1];
		Double_t Ed=tr->E[1];
		Double_t Dpd=tr->D2First[1];

		hEp->Fill(Ep);
		hEd->Fill(Ed);

		//derive event number after cuts
		if(Ep>1.5 && Tc>1.e-6 && Tc<400.e-6) eventNumber_Tc++;
		if(Ep>1.5 && Tc>1.e-6 && Tc<400.e-6 && Ed>(mu-3*sigma) && Ed<(mu+3*sigma)) eventNumber_Ed++;
		if(Ep>1.5 && Tc>1.e-6 && Tc<400.e-6 && Ed>(mu-3*sigma) && Ed<(mu+3*sigma) && Dpd<50) eventNumber_D++;
		
	}

	hEp->Write();
	hEd->Write();
	result->Write();
	
	return 0;
}
