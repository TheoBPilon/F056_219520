import array
import ROOT

def main():
    # Executar em modo batch (sem interface gráfica)
    ROOT.gROOT.SetBatch(True)
    ROOT.gStyle.SetCanvasColor(ROOT.kWhite)
    ROOT.gStyle.SetFrameFillColor(ROOT.kWhite)

    # Abrir o arquivo ROOT gerado
    file_in = ROOT.TFile("dados.root", "READ")
    tree = file_in.Get("tree")

    # Buffer para leitura do Branch
    x_hist = array.array('d', [0.0])
    tree.SetBranchAddress("x", x_hist)

    h_gauss = ROOT.TH1F("h_gaus", "histograma gausiano", 100, -5, 9)
    h_gauss.SetDirectory(0)

    nentries = tree.GetEntries()
    for i in range(nentries):
        tree.GetEntry(i)
        h_gauss.Fill(x_hist[0])

    h_gauss.SetLineColor(ROOT.kBlack)
    h_gauss.SetLineStyle(1)
    h_gauss.SetLineWidth(2)
    h_gauss.SetFillColor(ROOT.kYellow)

    h_gauss.SetXTitle("Valor Gerado")
    h_gauss.SetYTitle("Entradas")

    c = ROOT.TCanvas("c", "distribuicao gausiana", 800, 600)
    c.SetFillColor(ROOT.kWhite)

    h_gauss.Fit("gaus")
    h_gauss.Draw()

    c.SaveAs("fit_pyroot.png")
    file_in.Close()

if __name__ == "__main__":
    main()

