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
    int iteracoes = 20; // hardcoded
    float casasdecimais = 7; // hardcoded
    bool AoT = 1; // hardcoded, escolha entre truncamento e arredontamento nos calculos

    int decisao = 1;

    do {
        switch (decisao)
        {
        case 1:
            // monta tela inicial
            interface.header();
            interface.menu();
            interface.descricao();
            interface.menuInicial(&foguetes, &E);
            interface.loopParametros(&foguetes, &iteracoes, &E, &casasdecimais, &AoT, vetor_metodos);
            vetor_metodos[0].setGravaDados(foguetes, iteracoes);
            cout<<"Os dados foram calculados! tecle 2 para mostrar os dados"<<endl;
            break;
        case 2:
            // monta tela inicial
            interface.header();
            interface.menu();
            interface.printparametros(foguetes, iteracoes, E, casasdecimais, AoT);
            cout<<endl<<endl;
            interface.mostradados(vetor_metodos, foguetes, casasdecimais);
            break;
        case 3:
            // monta tela inicial
            interface.header();
            interface.menu();
            interface.printparametros(foguetes, iteracoes, E, casasdecimais, AoT);
            interface.allParametros(&foguetes, &iteracoes, &E, &casasdecimais, &AoT, vetor_metodos);
            vetor_metodos[0].setGravaDados(foguetes, iteracoes);
            cout<<"Os dados foram calculados! tecle 2 para mostrar"<<endl;
            
            break;
        default:
            // monta tela inicial
            interface.header();
            interface.menu();
            interface.descricao();
            interface.menuInicial(&foguetes, &E);
            interface.loopParametros(&foguetes, &iteracoes, &E, &casasdecimais, &AoT, vetor_metodos);
            vetor_metodos[0].setGravaDados(foguetes, iteracoes);
            break;
        }
        cin >> decisao;
        

    }while(decisao != 0);
    return 0;
    
}