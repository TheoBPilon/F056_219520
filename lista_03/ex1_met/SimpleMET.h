# pragma once
#include <iostream>
# include <math.h>

using namespace std;

class SimpleMET{
public:
    SimpleMET();
    SimpleMET(double Ex, double Ey);
    ~SimpleMET();

    double Value() const; // funcao que ira retornar o modulo
    double Ex() const; // retornara componente Ex
    double Ey() const; // retornara componente Ey
    double Phi() const; // retornara angulo entre o vetor MET e o eixo x

    void Add(double px, double py); // add px a mE_x e py a mE_y


private:
    double mE_x;
    double mE_y;
    
};
