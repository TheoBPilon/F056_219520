
#include "TH1.h"
#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TRandom3.h>
#include <TCanvas.h>
#include <TROOT.h>


void plot(){
    gROOT->SetBatch(kTRUE);
    
    TFile *file = new TFile("dados.root","READ");
    TTree *tree = (TTree *)file->Get("tree");

    double x_hist;
    tree->SetBranchAddress("x",&x_hist);

    TH1F *h_gauss = new TH1F("h_gaus","histograma gausiano",100,-5,9);


    Long64_t nentries = tree->GetEntries();
    for (Long64_t i = 0; i < nentries; i++){
        tree->GetEntry(i);
        h_gauss->Fill(x_hist); 
    }

    h_gauss->SetLineColor(kBlack);
    h_gauss->SetLineStyle(1);
    h_gauss->SetLineWidth(2);
    h_gauss->SetFillColor(kYellow);

    h_gauss->SetXTitle("Valor Gerado");
    h_gauss->SetYTitle("Entradas");

    TCanvas *c = new TCanvas("c","distribuicao gausiana",800,600);
    h_gauss->Fit("gaus");
    h_gauss->Draw();
    c->SaveAs("histograma.png");
    file->Close();
}