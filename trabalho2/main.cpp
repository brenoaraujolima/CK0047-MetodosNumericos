#include "Interface.cpp"
#include "Metodos.cpp"
#include<vector>
#include<iostream>
using namespace std;

int main() {
    /*Interface interface = Interface();
    interface.gerarInterface();*/

    vector<vector<float>> minhamatriz{  {3,-2,1},
                                        {1,-3,4},
                                        {9,4,-5}    };
    vector<float> independente{8,6,11};
    Metodos metodos = Metodos(minhamatriz, independente, 3);
    vector<float> teste = metodos.fatoracaoLuNormal();
    vector<float> teste2 = metodos.fatoracaoLDP();
    return 0;
}