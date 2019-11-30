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
    vector<vector<float>> matrizL;
    vector<vector<float>> matrizU;
    vector<vector<float>> matrizD;
    vector<vector<float>> matrizP;
    int decisao = 1;

    do {
        switch(decisao)
        {
        case 1:
            // primeira opcao, onde sao definidos o numero de foquetes e o ajuste
            // monta tela inicial
            system("clear");
            interface.header();
            interface.menu();
            interface.descricao();
            interface.menuInicial(minhamatriz, independente, &n);
            metodos.setA(minhamatriz);
            metodos.setTam(n);
            metodos.setF(independente);
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
            cout<<"Os dados foram calculados! tecle 2 para detalhes de implementação:  ";
            break;
        case 2:
            matrizL = metodos.getMatrizL();
            matrizU = metodos.getMatrizU();
            matrizD = metodos.getMatrizD();
            matrizP = metodos.getMatrizP();
            interface.detalhes(minhamatriz, matrizL, matrizU, matrizD, matrizP);
            cout<<endl<<endl;
            interface.inicioCarro();
            cout << "\t   ";
            cout << "Os detalhes foram mostrados. Tecle 1 para novo cálculo. Tecle 0 para sair: ";
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