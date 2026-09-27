#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TStyle.h"
#include <iostream>

void plot_higgs_vs_bkg()
{
    gStyle->SetOptStat(0);

    // Abre os arquivos ROOT do sinal e dos 3 backgrounds
    TFile *fSignal = TFile::Open("root_files/higgs_mass.root");
    TFile *fQCD = TFile::Open("root_files/qcd_bbar_mass.root");
    TFile *fZ0 = TFile::Open("root_files/z_bbar_mass.root");
    TFile *fTTbar = TFile::Open("root_files/ttbar_bbar_mass.root");


    TTree *tSignal = (TTree *)fSignal->Get("events");
    TTree *tQCD = (TTree *)fQCD->Get("events");
    TTree *tZ0 = (TTree *)fZ0->Get("events");
    TTree *tTTbar = (TTree *)fTTbar->Get("events");

    TH1F *hSignal = new TH1F("hSignal", "Reconstrucao de Massa Invariante m_{bb};Massa m_{bb} [GeV];Eventos Normalizados", 100, 0, 140);
    TH1F *hQCD = new TH1F("hQCD", "QCD bbbar", 100, 0, 140.1);
    TH1F *hZ0 = new TH1F("hZ0", "Z -> bbbar", 100, 0, 140.1);
    TH1F *hTTbar = new TH1F("hTTbar", "ttbar", 100, 0, 140.1);

    tSignal->Draw("mH >> hSignal", "", "goff");
    tQCD->Draw("mbb >> hQCD", "", "goff");
    tZ0->Draw("mbb >> hZ0", "", "goff");
    tTTbar->Draw("mbb >> hTTbar", "", "goff");


    TCanvas *c1 = new TCanvas("c1", "Sinal do Higgs vs Backgrounds", 800, 600);


    // Encontra a altura máxima necessária para o eixo Y não cortar nenhum pico
    double maxY = hSignal->GetMaximum();
    if (hQCD->GetMaximum() > maxY)
        maxY = hQCD->GetMaximum();
    if (hZ0->GetMaximum() > maxY)
        maxY = hZ0->GetMaximum();
    if (hTTbar->GetMaximum() > maxY)
        maxY = hTTbar->GetMaximum();
    hQCD->SetMaximum(maxY * 1.25);

    // 7. Estilização dos Histogramas
    // QCD (Fundo contínuo - Vermelho)
    hQCD->SetLineColor(kRed);
    hQCD->SetLineWidth(2);
    hQCD->GetXaxis()->SetTitle("Massa [GeV]");
    hQCD->GetYaxis()->SetTitle("# Eventos");
    hQCD->Draw("HIST");

    // Z0 -> bbbar (Pico em ~91 GeV - Verde)
    hZ0->SetLineColor(kGreen + 2);
    hZ0->SetLineWidth(2);
    hZ0->Draw("HIST SAME");

    // Top-Antitop (Lilás/Magenta)
    hTTbar->SetLineColor(kMagenta + 1);
    hTTbar->SetLineWidth(2);
    hTTbar->Draw("HIST SAME");

    // Sinal H -> bbbar 
    hSignal->SetLineColor(kBlue);
    hSignal->SetLineWidth(2);
    hSignal->Draw("HIST SAME");

    // Legenda do Gráfico
    TLegend *leg = new TLegend(0.32, 0.62, 0.58, 0.88);
    leg->SetBorderSize(1);
    leg->SetTextSize(0.035);
    leg->AddEntry(hSignal, "Sinal: H -> bb", "l");
    leg->AddEntry(hQCD, "Bkg: QCD bb", "l");
    leg->AddEntry(hZ0, "Bkg: Z -> bb", "l");
    leg->AddEntry(hTTbar, "Bkg: ttbar", "l");
    leg->Draw();

    

    c1->SaveAs("images/higgs_vs_backgrounds.png");

}

// Permitir compilação direta via g++
#ifndef __CINT__
int main(int argc, char **argv)
{
    plot_higgs_vs_bkg();
    return 0;
}
#endif