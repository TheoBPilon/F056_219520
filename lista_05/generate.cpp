#include <TFile.h>
#include <TTree.h>
#include <TRandom3.h>
#include <iostream>

int main() {
    TFile *file = TFile::Open("dados.root", "RECREATE");
    if (!file || file->IsZombie()) {
        std::cerr << "Erro ao criar o arquivo dados.root" << std::endl;
        return 1;
    }

    TTree *tree = new TTree("tree", "gausian_numbers");

    const int N = 1000;
    double mean = 2.0;
    double sigma = 1.0;

    double x;
    tree->Branch("x", &x, "x/D");

    TRandom3 rnd(0);
    for (int i = 0; i < N; i++) {
        x = rnd.Gaus(mean, sigma);
        tree->Fill();
    }

    file->cd();
    file->Write();
    file->Close();

    delete file;
    return 0;
}

