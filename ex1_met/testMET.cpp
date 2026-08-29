#include "SimpleMET.h"

using namespace std;
int main(){
    SimpleMET met(20.0,10.0); // cria objeto simplemet inicialmnente nulo

    // printando met inicialmente
    cout << "--- MET INICIAL ---" << endl;
    cout << "Ex = " << met.Ex() << endl;
    cout << "Ey = " << met.Ey() << endl;
    cout << "MET = " << met.Value() << endl;
    cout << "Phi = " << met.Phi() << endl;
    cout << "\n" << endl;

    // adicionando um primeiro objeto
    double px1 = 1.0;
    double py1 = 2.0; 

    met.Add(px1,py1);
    // Valores esperados
    double expectedEx1 = 19.0;
    double expectedEy1 = 8.0;
    double expectedMET1 = sqrt(19.0 * 19.0 + 8.0 * 8.0);

    // printando met depois do primeiro objeto
    cout << "--- MET INICIAL ---" << endl;
    cout << "Ex = " << met.Ex() << endl;
    cout << "Ey = " << met.Ey() << endl;
    cout << "MET = " << met.Value() << endl;
    cout << "Phi = " << met.Phi() << endl;
    cout << "\n" << endl;


    // Check  ( nao fiz exatanebte 0 pra nao dar problema de precisao)
    if (abs(met.Ex() - expectedEx1) < 1e-10 &&
        abs(met.Ey() - expectedEy1) < 1e-10 &&
        abs(met.Value() - expectedMET1) < 1e-10)
    {
        cout << "TESTE 1: PASS" << endl;
    }
    else
    {
        cout << "TESTE 1: FAIL" << endl;
    }

    cout << endl;

    // adicionando um segundo objeto
    double px2 = 3.00;
    double py2 = 20;

    // Valores esperados
    double expectedEx2 = 16.0;
    double expectedEy2 = -12.0;
    double expectedMET2 = 20.0;

    // printando met depois do primeiro objeto
    cout << "--- MET INICIAL ---" << endl;
    cout << "Ex = " << met.Ex() << endl;
    cout << "Ey = " << met.Ey() << endl;
    cout << "MET = " << met.Value() << endl;
    cout << "Phi = " << met.Phi() << endl;
    cout << "\n" << endl;

    // Check 2 
    if (abs(met.Ex() - expectedEx2) < 1e-10 &&
        abs(met.Ey() - expectedEy2) < 1e-10 &&
        abs(met.Value() - expectedMET2) < 1e-10)
    {
        cout << "TESTE 2: PASS" << endl;
    }
    else
    {
        cout << "TESTE 2: FAIL" << endl;
    }

    return 0;

}