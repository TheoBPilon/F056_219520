
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
        if (pz_ == 0.0) return 0; // particula esta em repouso
        //      (condicao) ? (valor se verdadeiro (pz>0)) : (valor se falso(pz<0))
        return (pz_ > 0 ) ? numeric_limits<double>::infinity():-numeric_limits<double>::infinity();
    }
    else{
        double p_mod = sqrt(px_ * px_ + py_ * py_ + pz_ * pz_);
        double theta = acos(pz_/p_mod);
        return -log(tan(theta/2));
    }
}