{
	TFile* file=new TFile("result.root","READ");
	TH1D* hly_p=(TH1D*)file->Get("hly_p");
	TH1D* hfee_p=(TH1D*)file->Get("hfee_p");
	TH1D* hres_p=(TH1D*)file->Get("hres_p");
	TH1D* hly_d=(TH1D*)file->Get("hly_d");
	TH1D* hfee_d=(TH1D*)file->Get("hfee_d");
	TH1D* hres_d=(TH1D*)file->Get("hres_d");

	new TCanvas();
	TLegend* lg1=new TLegend();
	hly_p->Draw();
	hfee_p->Draw("same");
	hres_p->Draw("same");
	lg1->AddEntry(hly_p,"Visible energy (E_{vis})","l");
	lg1->AddEntry(hfee_p,"After FEE non-linearity","l");
	lg1->AddEntry(hres_p,"After energy resolution (E_{rec})","l");
	lg1->Draw();
	hfee_p->SetLineColor(4);
	hres_p->SetLineColor(2);
	
	new TCanvas();
	TLegend* lg2=new TLegend();
	hly_d->Draw();
	hfee_d->Draw("same");
	hres_d->Draw("same");
	lg2->AddEntry(hly_d,"Visible energy (E_{vis})","l");
	lg2->AddEntry(hfee_d,"After FEE non-linearity","l");
	lg2->AddEntry(hres_d,"After energy resolution (E_{rec})","l");
	lg2->Draw();
	hfee_d->SetLineColor(4);
	hres_d->SetLineColor(2);
}
