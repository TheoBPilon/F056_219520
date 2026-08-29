#pragma once
#include "Track.h"


class SimTrack : public Track{
public:
    SimTrack(double E, double Px, double Py, double Pz, int PDGID, int PARENTPDGID);
    ~SimTrack();

    int ParticleId() const;
    int ParentId() const;
private:
    int pdgId_;
    int parentPdgId_;
};