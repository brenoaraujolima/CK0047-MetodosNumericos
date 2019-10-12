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

    bool decisao = 1;

    do {
        // monta tela inicial
        interface.header();
        interface.descricao();
        interface.menuInicial(&foguetes, &E);
        interface.loopParametros(&foguetes, &iteracoes, &E, &casasdecimais, &AoT, vetor_metodos);
        
        cout<<endl<<endl;
        
        // mostrar dados armazenados
        int espaco = 15; // tabulacao
        // primeiro quadro de respostas, apenas a raiz encontrada, se encontrada
        bool raizencontrada = false; // assumindo que nao temos raiz em nenhum metodo
        for(int i = 0; i < foguetes; i++){
            if(i == 0){ // cabecalho
                cout<<"Fuguete"<<setw(10);
                cout<<"Ajuste"<<setw(20);
                cout<<"Raiz Encontrada"<<setw(15);
                cout<<"Método Usado"<<endl;
            }
            interface.resetarFonte();
            cout<<i+1<<setw(espaco);
            cout<<setprecision(casasdecimais)<<fixed;
            // pega a menor erro e identifica o metodo usado
            float x;
            float raiz;
            string metodousado;
            if(vetor_metodos[i].datametodos[0].converge){
                x = vetor_metodos[i].datametodos[0].erro;
                raiz = vetor_metodos[i].datametodos[0].raiz;
                metodousado = vetor_metodos[i].datametodos[0].nome;
                raizencontrada = true;
            }
            for(int k = 1; k<3; k++){
                if(vetor_metodos[i].datametodos[0].converge){
                    float x1 = vetor_metodos[i].datametodos[k].erro;
                    if(x1 < x){ // x assume a menor raiz
                        x = x1;
                        raiz = vetor_metodos[i].datametodos[k].raiz;
                        metodousado = vetor_metodos[i].datametodos[k].nome;
                    }
                }
            }
            cout<<vetor_metodos[i].ajuste<<setw(espaco);
            if(raizencontrada){
                cout<<raiz<<setw(espaco);
                cout<<metodousado<<endl;
            }else{
                cout<<"Nao converge"<<setw(espaco);
                cout<<"-"<<endl;
            }
            raizencontrada = false;
        }
        cout<<endl;
        // Segundo quadro de respostas, com os métodos e seus dados
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
            interface.resetarFonte();
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
        interface.decisaoFinal(&decisao);

    }while(decisao == 1);
    return 0;
    
}