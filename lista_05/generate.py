import array
import ROOT

def main():
    file_out = ROOT.TFile("dados.root", "RECREATE")
    tree = ROOT.TTree("tree", "gausian_numbers")

    N = 1000
    mean = 2.0
    sigma = 1.0

    x = array.array('d', [0.0])
    tree.Branch("x", x, "x/D")

    rnd = ROOT.TRandom3(0)
    for _ in range(N):
        x[0] = rnd.Gaus(mean, sigma)
        tree.Fill()


    file_out.cd()
    file_out.Write()
    file_out.Close()

if __name__ == "__main__":
    main()

