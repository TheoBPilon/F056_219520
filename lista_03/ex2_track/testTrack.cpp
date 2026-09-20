#include "SimTrack.h"

#include <iostream>
#include <cmath>
#include <limits>

using namespace std;
int main(){
    // criando o primeiro track de tamanho normal
    SimTrack track1(10.0,3.0,4.0,5.0,11,23);
    // criando o segundo track com pT = 0
    SimTrack track2(10.0,0.0,0.0,10.0,211,111);


    // ==== TRACK 1 ======
    cout << "TRACK 1" << endl;
    cout << "E = " << track1.E()<< endl;
    cout << "px = " << track1.Px()<< endl;
    cout << "py = " << track1.Py()<< endl;
    cout << "py = " << track1.Pz()<< endl;
    cout << "pT = " << track1.Pt()<< endl;
    cout << "eta = " << track1.Eta()<< endl;
    cout << "Particle ID = " << track1.ParticleId()<< endl;
    cout << "Parent ID = " << track1.ParentId()<< endl;
    cout << endl;

    // ==== TRACK 1 ======
    cout << "TRACK 2" << endl;
    cout << "E = " << track2.E()<< endl;
    cout << "px = " << track2.Px()<< endl;
    cout << "py = " << track2.Py()<< endl;
    cout << "py = " << track2.Pz()<< endl;
    cout << "pT = " << track2.Pt()<< endl;
    cout << "eta = " << track2.Eta()<< endl;
    cout << "Particle ID = " << track2.ParticleId()<< endl;
    cout << "Parent ID = " << track2.ParentId()<< endl;
    cout << endl;


    // CHECK DO CASO DE pT = 0 (ve se de fato o segundo caso da infinito o eta)
    if(isinf(track2.Eta()) && track2.Eta() > 0){
        cout << "pT = 0 de fato -> passed test" << endl;
    }else{
        cout << "pT != 0 -> failed test" << endl;
    }
    return 0;
}