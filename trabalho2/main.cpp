#include "Interface.cpp"
#include "Metodos.cpp"

#include<vector>
#include<iostream>
using namespace std;

int main() {
    Interface interface;
    Metodos metodos;
    int n; // quantidade de linhas e colunas da matriz

    vector<vector<float>> minhamatriz;
    vector<float> independente;
    vector<float> resposta;
    int decisao = 1;

    do {
        switch (decisao)
        {
        case 1:
            // primeira opcao, onde sao definidos o numero de foquetes e o ajuste
            // monta tela inicial
            interface.header();
            interface.menu();
            interface.descricao();
            interface.menuInicial(minhamatriz, independente, &n);
            metodos.setA(minhamatriz);
            metodos.setF(independente);
            metodos.setTam(n);
            //metodos.printarMatriz(minhamatriz);
            resposta = metodos.fatoracaoLuNormal();
            interface.dadosSaida(resposta);
            //metodos.printarVetor(resposta);
            resposta = metodos.fatoracaoLDP();
            interface.respostaLDP(resposta);
            interface.conclusaoFinal(metodos.conclusao());
            //metodos.printarVetor(resposta);
            decisao = 0;
            //vetor_metodos[0].setGravaDados(foguetes, iteracoes);
            interface.inicioCarro();
            cout << "\t  ";
            cout<<"Os dados foram calculados! tecle 2 para detalhes de implementação"<<endl;
            break;
        case 2:
            // opcao para mostrar as tabelas com os dados calculados
            // monta tela inicial
            interface.header();
            //interface.printparametros(foguetes, iteracoes, E, casasdecimais, AoT);
            cout<<endl<<endl;
            //interface.mostradados(vetor_metodos, foguetes, casasdecimais);
            break;
        case 3:
            // opcao para redefinir os parametros "hardcoded"
            // monta tela inicial
            interface.header();
            interface.menu();
            //interface.printparametros(foguetes, iteracoes, E, casasdecimais, AoT);
            //vetor_metodos.clear();
            //interface.allParametros(&foguetes, &iteracoes, &E, &casasdecimais, &AoT, vetor_metodos);
            //vetor_metodos[0].setGravaDados(foguetes, iteracoes);
            cout<<"Os dados foram calculados! tecle 2 para mostrar"<<endl;
            
            break;
        case 4:
            // opcao para mostrar a analise
            // monta tela inicial
            interface.header();
            interface.menu();
            //interface.printparametros(foguetes, iteracoes, E, casasdecimais, AoT);
            //interface.analisar(vetor_metodos, foguetes, iteracoes);
            
            break;
        default:
            // mesmo que a opcao "1", fica como padrao
            // monta tela inicial
            interface.header();
            //interface.menu();
            //interface.descricao();
            //interface.menuInicial(&foguetes, &E);
            //interface.loopParametros(&foguetes, &iteracoes, &E, &casasdecimais, &AoT, vetor_metodos);
            //vetor_metodos[0].setGravaDados(foguetes, iteracoes);
            break;
        }
        cin >> decisao;
        

    }while(decisao != 0);
    return 0;
}