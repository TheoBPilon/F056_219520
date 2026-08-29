#include "SimpleMET.h"

SimpleMET::SimpleMET(): mE_x(0.0),mE_y(0.0){}
SimpleMET::SimpleMET(double Ex, double Ey): mE_x(Ex),mE_y(Ey){}

SimpleMET::~SimpleMET(){}

double SimpleMET::Value() const{
    return std::sqrt(mE_x * mE_x + mE_y * mE_y);
}

double SimpleMET::Ex() const{
    return mE_x;
}

double SimpleMET::Ey() const{
    return mE_y;
}

double SimpleMET::Phi() const{
    return std::atan2(mE_y,mE_x);
}

void SimpleMET::Add(double px, double py){
    mE_x -= px;
    mE_y -= py;
}
