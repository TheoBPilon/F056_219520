
#include "Track.h"

Track::Track(double E, double Px, double Py, double Pz):e_(E),px_(Px),py_(Py),pz_(Pz){}
Track::~Track(){}

double Track::E() const{
    return e_;
}

double Track::Px() const{
    return px_;
}

double Track::Py() const{
    return py_;
}

double Track::Pz() const{
    return pz_;
}

double Track::Pt() const{
    return sqrt(px_ * px_ + py_ * py_);
}

double Track::Eta() const{
    double pt = Pt();    
    if(pt < 1e-12){

        // pseudorrapidez nao definida para particula com momento nulo
        if(abs(pz_) < 1e-12){
            return numeric_limits<double>::quiet_NaN();
        }

        // para o caso de pz nao nulo, retorna +inf e -inf
        //      (condicao) ? (valor se verdadeiro (pz>0)) : (valor se falso(pz<0))
        return (pz_ > 0 ) ? numeric_limits<double>::infinity():-numeric_limits<double>::infinity();
    }
    else{
        double p_mod = sqrt(px_ * px_ + py_ * py_ + pz_ * pz_);
        double theta = acos(pz_/p_mod);
        return -log(tan(theta/2));
    }
}