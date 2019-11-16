#include "Interface.cpp"
#include "Metodos.cpp"
#include<vector>
#include<iostream>
using namespace std;

int main() {
    /*Interface interface = Interface();
    interface.gerarInterface();*/

    vector<vector<float>> minhamatriz{  {2,1,1},
                                        {1,2,0},
                                        {3,-1,-3}    };
    vector<float> independente{-2,1,1};
    Metodos metodos = Metodos(minhamatriz, independente, 3);
    vector<float> teste = metodos.fatoracaoLuNormal();
    return 0;
}