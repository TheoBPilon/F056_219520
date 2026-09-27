#include "Pythia8/Pythia.h"
#include "TFile.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include <iostream>

using namespace Pythia8;

int main() {
    Pythia pythia; // cria o objeto do Pythia

    if(!pythia.readFile("main_higgs.cmnd")){
        std::cerr << "Erro ao ler o arquivo main_higgs.cmnd" << std::endl;
        return 1;
    }
    if(!pythia.init()){
        std::cerr << "Erro ao inicializar o Pythia" << std::endl;
        return 1;
    }

    TFile outputFile("root_files/higgs_mass.root", "RECREATE");
    TTree tree("events","Eventos de Produção do Higgs");

    float mH = 0.0;
    int eventNumber = 0;

    tree.Branch("mH", &mH, "mH/F");
    tree.Branch("eventNumber", &eventNumber, "eventNumber/I");

    int nEvents = pythia.mode("Main:numberOfEvents"); // pega o numero de eventos que definimos

    for(int iEvent = 0; iEvent < nEvents; iEvent++){
        if(!pythia.next()) continue; // vaza do loop se nao tiver mais evento

        TLorentzVector bQuarkPlus; // quadrimomento do quark+
        TLorentzVector bQuarkMinus; // quadrimomento do quark-

        bool foundB = false; // se o bottom e encontrado
        bool foungAntiB = false; // se o antibotom e encontrado

        for(int i = 0; i < pythia.event.size(); i++){ // percorre todos os partons do evento
            const Particle& particle = pythia.event[i]; // cria um ponteiro para o parton
            if(particle.mother1()>0 && pythia.event[particle.mother1()].idAbs()==25){ // se a mae do parton for o higgs
                TLorentzVector mom(particle.px(), particle.py(), particle.pz(), particle.e()); // cria um vetor de lorentz para o parton

                if(particle.id()==5){
                    bQuarkPlus = mom; // se for o quark+ entao atribui o vetor ao quark+
                    foundB = true; // se o quark+ for encontrado entao marca como encontrado
                }
                else if(particle.id()==-5){
                    bQuarkMinus = mom; // se for o quark- entao atribui o vetor ao quark-
                    foungAntiB = true; // se o antiquark- for encontrado entao marca como encontrado
                }
            }
        }

        if(foundB && foungAntiB){ // se o quark+ e o antiquark- for encontrado entao
            eventNumber = iEvent; // atribui o numero do evento
            mH = (bQuarkPlus + bQuarkMinus).M(); // calcula a massa do Higgs
            tree.Fill(); // preenche o tree
        }

    }
    outputFile.cd();    // entra no diretorio corrente
    tree.Write();       // escreve o tree
    outputFile.Close(); // fecha o arquivo

    pythia.stat();

    return 0;
}
