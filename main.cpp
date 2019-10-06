#include <iostream>
#include "Metodos.h"

using namespace std;
int main() 
{
    int iteracoes = 10; // hardcoded
    float erro = 0.00001f; // hardcoded
    float casasdecimais = 5; // hardcoded
    bool AoT = 0; // hardcoded
    
    Metodos metodos(iteracoes); // instancia a classe principal
    // setando os parametros comuns a todos os métodos
    metodos.setA(-2.0f); // hardcoded inicio do intervalo (testes)
    metodos.setB(3.0f); // hardcoded fim do intervalo (teste)
    metodos.setErro(erro);

    float resposta2 = metodos.newton(erro, casasdecimais, iteracoes, AoT);
    // necessario resetar
     metodos.setA(-2.0f); // hardcoded inicio do intervalo (testes)
    metodos.setB(3.0f); // hardcoded fim do intervalo (teste)
   metodos.setErro(erro);

    
    float resposta = metodos.Bissecao(erro, casasdecimais, iteracoes, AoT);
    // necessario resetar
     metodos.setA(-2.0f); // hardcoded inicio do intervalo (testes)
    metodos.setB(3.0f); // hardcoded fim do intervalo (teste)
   metodos.setErro(erro);

    float respostaPosFalsa = metodos.posicao_falsa(erro, casasdecimais, iteracoes, AoT);
    cout << resposta << endl;
    cout << resposta2 << endl;
    cout << respostaPosFalsa << endl;
    // mostrar dados armazenados
    for (int i = 0; i < iteracoes; i++){ // loop entre os valore guardados
        float tmpErrPosFalsa = metodos.dataposfalsa.erro[i];
        float tmpErrNewton = metodos.datanewton.erro[i];
        float tmpErrBissecao = metodos.databissecao.erro[i];
        if(i == 0){
            cout<<"ITERACAO     ERROPOSFALSA    ERRONEWTON      ERROBISSECAO" << endl;
        }
            cout<<i<<"            ";
            cout<<tmpErrPosFalsa<<"               ";
            cout<<tmpErrNewton<<"               ";
            cout<<tmpErrBissecao<<endl;
    }

    return 0;
}