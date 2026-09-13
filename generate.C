#include <TFile.h>
#include <TTree.h>
#include <TRandom3.h>

void generate() {
    TFile *file = TFile::Open("dados.root", "RECREATE");
    TTree *tree = new TTree("tree", "gausian_numbers");

    const int N = 1000;
    double mean = 3.0;
    double sigma =0.5;

    double x;
    tree->Branch("x",&x,"x/D");

    TRandom3 rnd(0);
    for(int i=0;i<N;i++){
        x = rnd.Gaus(mean,sigma);
        tree->Fill();
    }

    file->cd();
    file->Write();
    file->Close();
    
}
