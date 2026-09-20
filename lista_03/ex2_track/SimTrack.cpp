#include "SimTrack.h"

SimTrack::SimTrack(double E, double Px, double Py, double Pz, int PDGID, int PARENTPDGID):Track(E,Px,Py,Pz),pdgId_(PDGID),parentPdgId_(PARENTPDGID){}
SimTrack::~SimTrack(){}

int SimTrack::ParticleId() const{
    return pdgId_;
}
int SimTrack::ParentId() const{
    return parentPdgId_;
}
