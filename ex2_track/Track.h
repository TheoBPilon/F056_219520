#include <limits>
# include <cmath>
# pragma once
using namespace std;

class Track{
public:
    Track(double E, double Px, double Py, double Pz);
    ~Track();

    double E() const;
    double Px() const;
    double Py() const;
    double Pz() const;

    double Pt() const;
    double Eta() const;
  

private:
    double e_;
    double px_;
    double py_;
    double pz_;
};