#include <iostream>
#include <vector>
#include "TH1D.h"
#include "TAxis.h"
#include "TH2D.h"
#include "TTree.h"
#include "TFile.h"
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
	TString roodir="/dybfs2/users/lijj/FullChain/Project_m14a_mc/TWin/Vertex/ExamTruth/aileron/Output/";
	for(int i=1000001;i<=1001000;i++){
		if(mode==0) tree->Add(TString::Format(roodir+"/GdLS/out_Gd_%d.root",i));
		if(mode==1) tree->Add(TString::Format(roodir+"/LS/out_LS_%d.root",i));
	}

	int TotalEntries=tree->GetEntries();
	tr=new Event;
	tr->Init(tree);

	TFile* result;
	if(mode==0) result=new TFile("result_GdLS.root","RECREATE");
	if(mode==1) result=new TFile("result_LS.root","RECREATE");

	cout<<"Total Entries: "<<TotalEntries<<endl;
	for(int i=0;i<TotalEntries;i++){
		unsigned int localentry=tree->LoadTree(i);
		int ret=tr->GetEntry(localentry);
		if(ret==0) cout<<"Load Tree Failed."<<endl;
		
	}

	result->Write();
	
	return 0;
}
