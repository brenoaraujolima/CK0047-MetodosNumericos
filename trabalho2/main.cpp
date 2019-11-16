#include "Interface.cpp"
#include "Metodos.cpp"
#include<vector>
#include<iostream>
using namespace std;

int main() {
    /*Interface interface = Interface();
    interface.gerarInterface();*/

    vector<vector<float>> minhamatriz{  {3,2,4},
                                        {1,1,2},
                                        {4,3,-2}    };
    vector<float> independente{1,2,3};
    Metodos metodos = Metodos(minhamatriz, independente, 3);
    vector<float> teste = metodos.fatoracaoLuNormal();
    return 0;
}