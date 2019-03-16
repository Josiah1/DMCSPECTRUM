{
	TString component="GdLS";
	//TString component="LS";
	//TString component="Ac";
	
	//Nuwa Full Chain Result
	TFile* file_Nuwa=new TFile("result_"+component+".root","READ");

	TString file_THU_dir="/dybfs2/users/lijj/ToyNote/TWin_Edep/Vertex/ExamTruth/aileron/Result/ResultFile/Normal/Model/";
	TFile* file_THU=new TFile(file_THU_dir+"result_"+component+".root","READ");
	TH1D* h_Nuwa=(TH1D*)file_Nuwa->Get("hEp");
	TH1D* h_THU=(TH1D*)file_THU->Get("hres_p");
	//Compare these two spectras
	new TCanvas();
	h_Nuwa->Draw();

	double h_Nuwa_Max=h_Nuwa->GetMaximum();
	double h_THU_Max=h_THU->GetMaximum();
	h_THU->Scale(h_Nuwa_Max/h_THU_Max);
	h_THU->Draw("same+hist");
	h_Nuwa->SetLineColor(2);
	h_THU->SetLineColor(4);
	TLegend* lg1=new TLegend();
	lg1->AddEntry(h_THU,"THU Toy","l");
	lg1->AddEntry(h_Nuwa,"NuWa MC","l");
	lg1->Draw("same");

	//Draw the ratio of these two spectra
	h_Nuwa->Rebin(10);
	h_THU->Rebin(10);
	TH1D* hratio=new TH1D("hratio","",100,0,15);
	hratio->GetXaxis()->SetTitle("Prompt Energy [MeV]");
	hratio->GetYaxis()->SetTitle("MC/Toy");
	for(int i=0;i<100;i++){
		double b1=h_Nuwa->GetBinContent(i+1);
		double b2=h_THU->GetBinContent(i+1);
		double a=1.;
		if(!(b1==0 || b2==0)) a=b2/b1;
		cout<<"a: "<<a<<" :: "<<b1<<" : "<<b2<<endl;
		hratio->SetBinContent(i+1,a);
	}
	TF1* fbase=new TF1("fbase","1",0,15);
	fbase->SetLineColor(2);
	fbase->SetLineStyle(2);
	new TCanvas();
	hratio->Draw();
	hratio->GetYaxis()->SetRangeUser(0.6,1.4);
	fbase->Draw("same");
}
