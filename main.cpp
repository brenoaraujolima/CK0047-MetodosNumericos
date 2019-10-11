#include <vector>
#include <iostream>
#include "Metodos.h"

using namespace std;
int main() 
{
    vector<Metodos> vetor_metodos; // armazena n objetos Metodos de acordo com a entrada do usuario
    int foguetes = 0; // quantidade de foguetes
    float E; // Erro márimo permitido
    int iteracoes = 10; // hardcoded
    float casasdecimais = 5; // hardcoded
    bool AoT = 1; // hardcoded, escolha entre truncamento e arredontamento nos calculos

    // dados de entrada pelo usuario
    cout << "Informe a quantidade de foguetes: ";
    cin >> foguetes;
    cout << "Informe a precisao desejada: ";
    cin >> E;
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
        metodos.newton(a, casasdecimais, iteracoes, AoT); // Acha a raiz e guarda os valores
        metodos.Bissecao(a, casasdecimais, iteracoes, AoT); // idem
        metodos.posicao_falsa(a, casasdecimais, iteracoes, AoT); // idem
        vetor_metodos.push_back(metodos); // armazena no vetor
    }
    // mostrar dados armazenados
    for (int j = 0; j<foguetes; j++){ // loop na quantidade de foguetes
        for (int i = 0; i < iteracoes; i++){ // loop entre os valore guardados
            float tmpErrPosFalsa = vetor_metodos[j].datametodos[2].erro[i];
            float tmpDeslocPosFalsa = vetor_metodos[j].datametodos[2].deslocamento[1];

            float tmpErrNewton = vetor_metodos[j].datametodos[1].erro[i];
            float tmpDeslocNewton = vetor_metodos[j].datametodos[1].deslocamento[i];
            
            float tmpErrBissecao = vetor_metodos[j].datametodos[0].erro[i];
            float tmpDeslocBissecao = vetor_metodos[j].datametodos[0].deslocamento[i];
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
    }
    return 0;
}