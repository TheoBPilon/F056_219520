#include "Pythia8/Pythia.h"
#include "TFile.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace Pythia8;

int main(int argc, char *argv[])
{
    // Exige que o usuário informe o tipo de background no terminal
    if (argc < 2)
    {
        std::cout << "\n=======================================================" << std::endl;
        std::cout << "Uso: " << argv[0] << " <tipo_bkg>" << std::endl;
        std::cout << "Opcoes validas: qcd | z | ttbar" << std::endl;
        std::cout << "Exemplo: " << argv[0] << " qcd" << std::endl;
        std::cout << "=======================================================\n"
                  << std::endl;
        return 1;
    }

    std::string mode = argv[1];
    std::string rootFileName = "root_files/" + mode + "_bbar_mass.root";

    Pythia pythia;


    // coloca as regras de física dinamicamente conforme a opção escolhida
    if (mode == "qcd")
    {
        std::cout << "--> Configurando Background: QCD bbbar..." << std::endl;
        pythia.readString("HardQCD:hardbbbar = on");
        pythia.readString("PhaseSpace:pTHatMin = 20.");
    }
    else if (mode == "z")
    {
        std::cout << "--> Configurando Background: Z0 -> bbbar..." << std::endl;
        pythia.readString("WeakZ0:gmZmode = 2");
        pythia.readString("WeakSingleBoson:ffbar2gmZ = on");
        pythia.readString("23:onMode = off");
        pythia.readString("23:onIfMatch = 5 -5");
    }
    else if (mode == "ttbar")
    {
        std::cout << "--> Configurando Background: ttbar..." << std::endl;
        pythia.readString("Top:gg2ttbar = on");
        pythia.readString("Top:qqbar2ttbar = on");
        pythia.readString("24:onMode = off");
        pythia.readString("24:onIfAny = 1 2 3 4 11 13 15");
    }
    else
    {
        std::cerr << "Modo invalido! Use 'qcd', 'z' ou 'ttbar'." << std::endl;
        return 1;
    }

    // Inicializa o PYTHIA8 com as regras injetadas
    if (!pythia.init())
    {
        std::cerr << "Erro na inicializacao do PYTHIA8!" << std::endl;
        return 1;
    }

    // daqui pra frente, o programa vai gerar os eventos conforme a opção escolhida

    // cria o arquivo de saída
    TFile outputFile(rootFileName.c_str(), "RECREATE");
    TTree tree("events", "Eventos de Background do Modelo Padrao");

    float mbb = 0.0;
    int eventNumber = 0;

    tree.Branch("mbb", &mbb, "mbb/F");
    tree.Branch("eventNumber", &eventNumber, "eventNumber/I");

    int nEvents = pythia.mode("Main:numberOfEvents");

    for (eventNumber = 0; eventNumber < nEvents; ++eventNumber)
    {
        if (!pythia.next())
            continue;

        std::vector<TLorentzVector> bQuarks;

        // Varre todas as partículas geradas no evento
        for (int i = 0; i < pythia.event.size(); ++i)
        {
            const Particle &p = pythia.event[i];

            if (p.idAbs() == 5 && p.pT() > 20.0)
            {
                TLorentzVector p4(p.px(), p.py(), p.pz(), p.e());
                bQuarks.push_back(p4);
            }
        }

        // Ordena ow quarks b por pt
        std::sort(bQuarks.begin(), bQuarks.end(), [](const TLorentzVector &a, const TLorentzVector &b)
                  { return a.Pt() > b.Pt(); });

        // Se encontrou pelo menos 2 quarks b no evento, calcula a massa e preenche a TTree
        if (bQuarks.size() >= 2)
        {
            mbb = (bQuarks[0] + bQuarks[1]).M();
            tree.Fill(); // Grava os dados na TTree
        }
    }

    outputFile.cd();
    tree.Write();
    outputFile.Close();

    pythia.stat();
    std::cout << "\n Arquivo " << rootFileName << " gerado.\n"
              << std::endl;

    return 0;
}