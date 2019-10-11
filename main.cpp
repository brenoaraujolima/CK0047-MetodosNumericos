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