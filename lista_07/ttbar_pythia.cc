#include "Pythia8/Pythia.h"
#include <iostream>

using namespace Pythia8;

int main(){
    Pythia pythia;

    // beam
    pythia.readString("Beams:eCM = 13000.");
    pythia.readString("Top:qqbar2ttbar = on"); 

    pythia.init();

    int n_events = 10000;
    for (int event_i = 0; event_i < n_events; ++event_i) {
        if(!pythia.next()) continue;
    }

    pythia.stat();

    // printando o sigmaGen e sigmaErr em pb (mbe9)
    std::cout << std::scientific;
    std::cout << "sigma = " << pythia.info.sigmaGen() * 1e9 << " +- "
              << pythia.info.sigmaErr() * 1e9 << " pb" << std::endl;

    return 0;
}
