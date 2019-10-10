#include <iostream>
#include "Metodos.h"

using namespace std;
int main() 
{
    int iteracoes = 30; // hardcoded
    float erro = 0.000001f; // hardcoded
    float ajuste = 0.7; // ajuste
    float casasdecimais = 7; // hardcoded
    bool AoT = 1; // hardcoded
    
    Metodos metodos(iteracoes); // instancia a classe principal
    // setando os parametros comuns a todos os métodos
    metodos.setA(1.0f); // hardcoded inicio do intervalo (testes)
    metodos.setB(5.0f); // hardcoded fim do intervalo (teste)
    metodos.setErro(erro);

    metodos.newton(ajuste, casasdecimais, iteracoes, AoT);
    metodos.Bissecao(ajuste, casasdecimais, iteracoes, AoT);
    metodos.posicao_falsa(ajuste, casasdecimais, iteracoes, AoT);
    // mostrar dados armazenados
    for (int i = 0; i < iteracoes; i++){ // loop entre os valore guardados
        float tmpErrPosFalsa = metodos.dataposfalsa.erro[i];
        float tmpDeslocPosFalsa = metodos.dataposfalsa.deslocamento[1];

        float tmpErrNewton = metodos.datanewton.erro[i];
        float tmpDeslocNewton = metodos.datanewton.deslocamento[i];
        
        float tmpErrBissecao = metodos.databissecao.erro[i];
        float tmpDeslocBissecao = metodos.databissecao.deslocamento[i];
        string  tab = "             ";
        if(i == 0){
            cout<<"ITERACAO"<<tab<<tab;
            cout<<"POSFALSA"<<tab<<tab;
            cout<<"NEWTON"<<tab<<tab;
            cout<<"BISSECAO" << endl;
        }
           
            cout<<i<<tab<<tab;
            cout<<"E: "<<tmpErrPosFalsa;
            cout<<"/d: "<<tmpDeslocPosFalsa<<tab<<tab;
            cout<<"E: "<<tmpErrNewton;
            cout<<"/d: "<<tmpDeslocNewton<<tab<<tab;
            cout<<"E: "<<tmpErrBissecao;
            cout<<"/d: "<<tmpDeslocBissecao<<endl;
    }
    return 0;
}