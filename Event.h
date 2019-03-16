//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Mar 16 13:56:43 2019 by ROOT version 5.26/00e
// from TTree Event/Analysis Tree
// found on file: Output/GdLS/out_Gd_1000001.root
//////////////////////////////////////////////////////////

#ifndef Event_h
#define Event_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

class Event : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   Int_t           Run;
   Int_t           Det;
   Double_t        T2PrevMu;
   Double_t        T2PrevPlMu;
   Double_t        T2PrevAdMu;
   Double_t        T2PrevShMu;
   Double_t        T2PrevNetMu;
   Int_t           Fold;
   Int_t           Volume_IBD;
   Int_t           Volume_nCap;
   Int_t           TrigSec[2];   //[Fold]
   Int_t           TrigNano[2];   //[Fold]
   Double_t        E[2];   //[Fold]
   Double_t        X[2];   //[Fold]
   Double_t        Y[2];   //[Fold]
   Double_t        Z[2];   //[Fold]
   Double_t        D2First[2];   //[Fold]
   Double_t        T2PrevSubEvt[2];   //[Fold]
   Int_t           TrigSecT[2];   //[Fold]
   Int_t           TrigNanoT[2];   //[Fold]
   Double_t        ET[2];   //[Fold]
   Double_t        XT[2];   //[Fold]
   Double_t        YT[2];   //[Fold]
   Double_t        ZT[2];   //[Fold]
   Double_t        D2FirstT[2];   //[Fold]
   Double_t        T2PrevSubEvtT[2];   //[Fold]
   Double_t        XDepC[2];   //[Fold]
   Double_t        YDepC[2];   //[Fold]
   Double_t        ZDepC[2];   //[Fold]
   Double_t        CapTarget;

   // List of branches
   TBranch        *b_Run;   //!
   TBranch        *b_Det;   //!
   TBranch        *b_T2PrevMu;   //!
   TBranch        *b_T2PrevPlMu;   //!
   TBranch        *b_T2PrevAdMu;   //!
   TBranch        *b_T2PrevShMu;   //!
   TBranch        *b_T2PrevNetMu;   //!
   TBranch        *b_Fold;   //!
   TBranch        *b_Volume_IBD;   //!
   TBranch        *b_Volume_nCap;   //!
   TBranch        *b_TrigSec;   //!
   TBranch        *b_TrigNano;   //!
   TBranch        *b_E;   //!
   TBranch        *b_X;   //!
   TBranch        *b_Y;   //!
   TBranch        *b_Z;   //!
   TBranch        *b_D2First;   //!
   TBranch        *b_T2PrevSubEvt;   //!
   TBranch        *b_TrigSecT;   //!
   TBranch        *b_TrigNanoT;   //!
   TBranch        *b_ET;   //!
   TBranch        *b_XT;   //!
   TBranch        *b_YT;   //!
   TBranch        *b_ZT;   //!
   TBranch        *b_D2FirstT;   //!
   TBranch        *b_T2PrevSubEvtT;   //!
   TBranch        *b_XDepC;   //!
   TBranch        *b_YDepC;   //!
   TBranch        *b_ZDepC;   //!
   TBranch        *b_CapTarget;   //!

   Event(TTree * /*tree*/ =0) { }
   virtual ~Event() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(Event,0);
};

#endif

#ifdef Event_cxx
void Event::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Run", &Run, &b_Run);
   fChain->SetBranchAddress("Det", &Det, &b_Det);
   fChain->SetBranchAddress("T2PrevMu", &T2PrevMu, &b_T2PrevMu);
   fChain->SetBranchAddress("T2PrevPlMu", &T2PrevPlMu, &b_T2PrevPlMu);
   fChain->SetBranchAddress("T2PrevAdMu", &T2PrevAdMu, &b_T2PrevAdMu);
   fChain->SetBranchAddress("T2PrevShMu", &T2PrevShMu, &b_T2PrevShMu);
   fChain->SetBranchAddress("T2PrevNetMu", &T2PrevNetMu, &b_T2PrevNetMu);
   fChain->SetBranchAddress("Fold", &Fold, &b_Fold);
   fChain->SetBranchAddress("Volume_IBD", &Volume_IBD, &b_Volume_IBD);
   fChain->SetBranchAddress("Volume_nCap", &Volume_nCap, &b_Volume_nCap);
   fChain->SetBranchAddress("TrigSec", TrigSec, &b_TrigSec);
   fChain->SetBranchAddress("TrigNano", TrigNano, &b_TrigNano);
   fChain->SetBranchAddress("E", E, &b_E);
   fChain->SetBranchAddress("X", X, &b_X);
   fChain->SetBranchAddress("Y", Y, &b_Y);
   fChain->SetBranchAddress("Z", Z, &b_Z);
   fChain->SetBranchAddress("D2First", D2First, &b_D2First);
   fChain->SetBranchAddress("T2PrevSubEvt", T2PrevSubEvt, &b_T2PrevSubEvt);
   fChain->SetBranchAddress("TrigSecT", TrigSecT, &b_TrigSecT);
   fChain->SetBranchAddress("TrigNanoT", TrigNanoT, &b_TrigNanoT);
   fChain->SetBranchAddress("ET", ET, &b_ET);
   fChain->SetBranchAddress("XT", XT, &b_XT);
   fChain->SetBranchAddress("YT", YT, &b_YT);
   fChain->SetBranchAddress("ZT", ZT, &b_ZT);
   fChain->SetBranchAddress("D2FirstT", D2FirstT, &b_D2FirstT);
   fChain->SetBranchAddress("T2PrevSubEvtT", T2PrevSubEvtT, &b_T2PrevSubEvtT);
   fChain->SetBranchAddress("XDepC", XDepC, &b_XDepC);
   fChain->SetBranchAddress("YDepC", YDepC, &b_YDepC);
   fChain->SetBranchAddress("ZDepC", ZDepC, &b_ZDepC);
   fChain->SetBranchAddress("CapTarget", &CapTarget, &b_CapTarget);
}

Bool_t Event::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef Event_cxx
