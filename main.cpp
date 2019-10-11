#include <vector>
#include <iostream>
#include <iomanip>
#include "Metodos.h"
#include "Interface.h"

using namespace std;
int main() 
{
    vector<Metodos> vetor_metodos; // armazena n objetos Metodos de acordo com a entrada do usuario
    Interface interface;
    int foguetes = 0; // quantidade de foguetes
    float E; // Erro márimo permitido
    int iteracoes = 100; // hardcoded
    float casasdecimais = 9; // hardcoded
    bool AoT = 1; // hardcoded, escolha entre truncamento e arredontamento nos calculos

    // monta tela inicial
    interface.menuInicial(&foguetes, &E);
    interface.descricao();
    
    // para cada foguete, instaciamos uma classe com os métodos e armazenamos no vetor
    for (int i = 0; i< foguetes; i++)
    {
        float a;
        cout << "Informe o parametro de ajuste para o foguete "<<i+1<<":";
        cin >> a;
        Metodos metodos = Metodos(iteracoes);
        // setando os parametros comuns a todos os métodos
        metodos.setA(0.0001f); // hardcoded inicio do intervalo (testes)
        metodos.setB(1000.0f); // hardcoded fim do intervalo (teste)
        metodos.setErro(E); // Setando o erro permitido
        metodos.ajuste = a; // Setando o ajuste
        metodos.newton(a, casasdecimais, iteracoes, AoT); // Acha a raiz e guarda os valores
        metodos.Bissecao(a, casasdecimais, iteracoes, AoT); // idem
        metodos.posicao_falsa(a, casasdecimais, iteracoes, AoT); // idem
        vetor_metodos.push_back(metodos); // armazena no vetor
    }
    // mostrar dados armazenados
    int espaco = 15; // tabulacao
    for(int i = 0; i<3; i++){ // loop nos metodos implementados
        if(i == 0){ // cabecalho
            cout<<"FOG."<<setw(10);
            cout<<"METODO"<<setw(15);
            cout<<"RAIZ"<<setw(15);
            cout<<"ERRO"<<setw(17);
            cout<<"AJUSTE"<<setw(20);
            cout<<"ISOLAMENTO"<<setw(20);
            cout<<"CONVERGE?" << endl;
        }
        for (int j = 0; j<foguetes; j++){ // loop na quantidade de foguetes
            
            cout<<j+1<<setw(espaco);
            cout<<setprecision(casasdecimais)<<fixed;
            cout<<vetor_metodos[j].datametodos[i].nome<<setw(espaco);
            cout<<vetor_metodos[j].datametodos[i].raiz<<setw(espaco);
            cout<<vetor_metodos[j].datametodos[i].erro<<setw(espaco);
            cout<<vetor_metodos[j].ajuste<<setw(espaco);
            float a = vetor_metodos[j].getA();
            float b = vetor_metodos[j].getB();
            cout<<setprecision(0)<<fixed;
            cout<<"["<<a<<","<<b<<"]"<< setw(espaco);
            if(vetor_metodos[j].datametodos[i].converge){
                cout<<"sim, em "<< vetor_metodos[j].datametodos[i].iter<< endl;
            }else{
                cout<<"nao, em "<< vetor_metodos[j].datametodos[i].iter<< endl;
            }
            
        }
    }
    return 0;
}