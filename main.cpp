#include <vector>
#include <iostream>
#include "Metodos.h"
#include "Interface.h"

using namespace std;
int main() 
{
    vector<Metodos> vetor_metodos; // armazena n objetos Metodos de acordo com a entrada do usuario
    Interface interface;
    int foguetes = 0; // quantidade de foguetes
    float E; // Erro márimo permitido
    interface.menuInicial(&foguetes, &E);
    int iteracoes = 10; // hardcoded
    float casasdecimais = 5; // hardcoded
    bool AoT = 1; // hardcoded, escolha entre truncamento e arredontamento nos calculos

    // para cada foguete, instaciamos uma classe com os métodos e armazenamos no vetor
    for (int i = 0; i< foguetes; i++)
    {
        float a;
        cout << "Informe o parametro de ajuste para o foguete "<<i+1<<":";
        cin >> a;
        Metodos metodos = Metodos(iteracoes);
        // setando os parametros comuns a todos os métodos
        metodos.setA(1.0f); // hardcoded inicio do intervalo (testes)
        metodos.setB(5.0f); // hardcoded fim do intervalo (teste)
        metodos.setErro(E); // Setando o erro permitido
        metodos.ajuste = a; // Setando o ajuste
        metodos.newton(a, casasdecimais, iteracoes, AoT); // Acha a raiz e guarda os valores
        metodos.Bissecao(a, casasdecimais, iteracoes, AoT); // idem
        metodos.posicao_falsa(a, casasdecimais, iteracoes, AoT); // idem
        vetor_metodos.push_back(metodos); // armazena no vetor
    }
    // mostrar dados armazenados
    string  tab = "             "; // para organizar na tela
    for(int i = 0; i<3; i++){ // loop nos metodos implementados
        if(i == 0){ // cabecalho
            cout<<"FOGUETE"<<tab;
            cout<<"METODO"<<tab;
            cout<<"RAIZ"<<tab;
            cout<<"ERRO"<<tab;
            cout<<"AJUSTE"<<tab;
            cout<<"ISOLAMENTO" << endl;
        }
        for (int j = 0; j<foguetes; j++){ // loop na quantidade de foguetes
            cout<<j+1<<tab;
            cout<<vetor_metodos[j].datametodos[i].nome<<tab;
            cout<<vetor_metodos[j].datametodos[i].raiz<<tab;
            cout<<vetor_metodos[j].datametodos[i].erro<<tab;
            cout<<vetor_metodos[j].ajuste<<tab;
            float a = vetor_metodos[j].getA();
            float b = vetor_metodos[j].getB();
            cout<<"["<<a<<","<<b<<"]"<< endl;
        }
    }
    return 0;
}