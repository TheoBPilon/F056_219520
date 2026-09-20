#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TF1.h>
#include <TColor.h>
#include <iostream>

int main() {
    gROOT->SetBatch(kTRUE);

    // abrir ROOT que geramos em generate
    TFile *file = new TFile("dados.root", "READ");
    if (!file || file->IsZombie()) {
        std::cerr << "Erro ao abrir o arquivo dados.root" << std::endl;
        return 1;
    }

    TTree *tree = (TTree *)file->Get("tree");
    if (!tree) {
        std::cerr << "TTree 'tree' nao encontrada no arquivo." << std::endl;
        file->Close();
        delete file;
        return 1;
    }

    double x_hist;
    tree->SetBranchAddress("x", &x_hist);

    TH1F *h_gauss = new TH1F("h_gaus", "histograma gausiano", 100, -5, 9);
    h_gauss->SetDirectory(nullptr); 

    Long64_t nentries = tree->GetEntries();
    for (Long64_t i = 0; i < nentries; i++) {
        tree->GetEntry(i);
        h_gauss->Fill(x_hist);
    }

    // Estilização do histograma
    h_gauss->SetLineColor(kBlack);
    h_gauss->SetLineStyle(1);
    h_gauss->SetLineWidth(2);
    h_gauss->SetFillColor(kYellow);

    h_gauss->SetXTitle("Valor Gerado");
    h_gauss->SetYTitle("Entradas");

    // Criar o canvas com fundo branco
    TCanvas *c = new TCanvas("c", "distribuicao gausiana", 800, 600);
    c->SetFillColor(kWhite);

    // Fazer o ajuste gaussian
    h_gauss->Fit("gaus");
    h_gauss->Draw();

    c->SaveAs("fit_cpp.png");

    file->Close();
    delete file;
    delete c;
    delete h_gauss;

    return 0;
}

