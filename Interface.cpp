#include<iostream>
#include<iomanip>
#include<cstdio>
#include<vector>
//#include<locale.h>
#include<stdlib.h>
#include "Metodos.h"
#include "Interface.h"

using namespace std;


void Interface::fonteVerde() {
    cout << "\033[0;32m";
}

void Interface::resetarFonte() {
    cout<<"\033[1;0m";
}

void Interface::inicioCarro() {
    cout << "\t   ";
}

void Interface::molduraHorizontal() {
    for(int i=0; i<80; i++) {cout <<"═";}
}

void Interface::percorrerLinha() {
    fonteVerde();
    for(int i=0; i<80; i++) {cout <<" ";}
}

void Interface::header() {
    fonteVerde();  
    inicioCarro();
    cout << "╔";
    molduraHorizontal();
    cout<<"╗"<<endl<<"\r";

    inicioCarro();
    cout<<"║";
    percorrerLinha();
    cout<<"║";
    cout<<endl;
    inicioCarro();
    cout<<"║";
    percorrerLinha();
    cout<<"║";
    cout<<endl;
    inicioCarro();
    cout <<"║"<< "\t\t\t"<<"#####   ####   ####  #    # ###### #####"<<"\t\t    ║"<<endl;
    inicioCarro();
    cout <<"║"<< "\t\t\t"<<"#    # #    # #    # #   #  #        #  "<<"\t\t    ║" << endl;
    inicioCarro();
    cout <<"║"<<"\t\t\t"<<"#    # #    # #      ####   #####    #"<<"\t\t\t    ║"<<endl;
    inicioCarro();
    cout <<"║"<<"\t\t\t"<<"#####  #    # #      #  #   #        #  "<<"\t\t    ║"<<endl;
    inicioCarro();
    cout <<"║"<<"\t\t\t"<<"#   #  #    # #    # #   #  #        #   "<<"\t\t    ║"<<endl;
    inicioCarro();
    cout <<"║"<<"\t\t\t"<<"#    #  ####   ####  #    # ######   #   "<<"\t\t    ║"<<endl;
    inicioCarro();
    cout <<"║"<<"\t\t\t"<<"                                         "<<"\t\t    ║"<<endl;
    inicioCarro();
    cout <<"║"<<"\t\t\t"<<"                                         "<<"\t\t    ║"<<endl;
    inicioCarro();
    cout <<"║"<<"\t\t\t"<<" ####  #   #  ####  ##### ###### #    # "<<"\t\t    ║"<<endl;
    inicioCarro();
    cout <<"║"<<"\t\t\t"<<"#       # #  #        #   #      ##  ## "<<"\t\t    ║"<<endl;
    inicioCarro();
    cout <<"║"<<"\t\t\t"<<" ####    #    ####    #   #####  # ## # "<<"\t\t    ║"<<endl;
    inicioCarro();
    cout <<"║"<<"\t\t\t"<<"     #   #        #   #   #      #    # "<<"\t\t    ║"<<endl;
    inicioCarro();
    cout <<"║"<<"\t\t\t"<<"######   #   ######   #   #####  #    #    # "<<"\t\t    ║"<<endl;
    inicioCarro();
    cout<<"║";
    percorrerLinha();
    cout<<"║";
    cout << endl;
    inicioCarro();
    cout<<"╚";
    molduraHorizontal();
    cout<<"╝"<<endl;
}

void Interface::descricao() {
    fonteVerde();
    inicioCarro();
    cout<<"│";
    percorrerLinha();
    cout<<"│"<<endl;
    inicioCarro();
    cout<<"│";
    resetarFonte();
    cout << "\t" <<"Rocket System é um software que calcula o deslocamento da extremidade";
    fonteVerde();
    cout <<"\t    │"<<endl;
    inicioCarro();
    fonteVerde();
    cout<<"│";
    resetarFonte();
    cout<<"\tde um foguete espacial com o intuito de garantir a eficiência no lançamento";
    fonteVerde();
    cout<<" │"<<endl;
    inicioCarro();
    fonteVerde();
    cout<<"│";
    resetarFonte();
    cout<<"\te a segurança de seus tripulantes.";
    fonteVerde();
    cout << "\t\t\t\t\t    │"<<endl;
    inicioCarro();
    cout<<"│";
    resetarFonte();
    cout<<"\tPara utilizar, preencha os parametros abaixo.";
    fonteVerde();
    cout<<"\t\t\t\t    │"<<endl;
    inicioCarro();
    cout<<"│";
    percorrerLinha();
    cout<<"│"<<endl;
    inicioCarro();
    cout<<"│";
    percorrerLinha();
    cout<<"│"<<endl;
}

void Interface::menuInicial(int *foguetes, float *E) {
    fonteVerde();
    inicioCarro();
    cout<<"│";
    //cout<<"\t"<<"Insira o nº de foguetes: ";
    cout<<"\t\t\t\t\t\t\t\t\t\t    │";
    cout<<"\r\t\tInsira o nº de foguetes:  ";
    resetarFonte();
    cin >> *foguetes;
    
    inicioCarro();
    fonteVerde();
    cout<<"│";
    cout<<"\t\t\t\t\t\t\t\t\t\t    │";
    cout<<"\r\t\tInforme a precisão desejada: ";
    resetarFonte();
    cin >> *E;
    
}

void Interface::loopParametros(int *foguetes, int *iteracoes, float *E, float *casasdecimais, bool *AoT, vector<Metodos>& vetor_metodos) {
    // para cada foguete, instaciamos uma classe com os métodos e armazenamos no vetor
    for (int i = 0; i< *foguetes; i++)
    {
        float a;
        cout << "\tInforme o parametro de ajuste para o foguete "<<i+1<<":  ";
        //resetarFonte();
        cin >> a;
        //fonteVerde();
        Metodos metodos = Metodos(*iteracoes);
        // setando os parametros comuns a todos os métodos
        metodos.setA(1.0f); // hardcoded inicio do intervalo (testes)
        metodos.setB(4.0f); // hardcoded fim do intervalo (teste)
        metodos.setErro(*E); // Setando o erro permitido
        metodos.ajuste = a; // Setando o ajuste
        metodos.newton(a, *casasdecimais, *iteracoes, *AoT); // Acha a raiz e guarda os valores
        metodos.Bissecao(a, *casasdecimais, *iteracoes, *AoT); // idem
        metodos.posicao_falsa(a, *casasdecimais, *iteracoes, *AoT); // idem
        vetor_metodos.push_back(metodos); // armazena no vetor
    }
}

void Interface::allParametros(int *foguetes, int *iteracoes, float *E, float *casasdecimais, bool *AoT, vector<Metodos>& vetor_metodos) {
    // para cada foguete, instaciamos uma classe com os métodos e armazenamos no vetor
    float isolamentoA;
    float isolamentoB;
    fonteVerde();
    cout << "\tIsolamento(a):  ";
    resetarFonte();
    cin >> isolamentoA;
    fonteVerde();
    cout << "\tIsolamento (b):  ";
    resetarFonte();
    cin >> isolamentoB;
    fonteVerde();
    cout << "\tErro permitido: ";
    resetarFonte();
    cin >> *E;
    fonteVerde();
    cout << "\tCasas decimais:  ";
    resetarFonte();
    cin >> *casasdecimais;
    fonteVerde();
    cout << "\tLimite Iteracoes: ";
    resetarFonte();
    cin >> *iteracoes;
    fonteVerde();
    cout << "\tArred. ou trunc (0 = arred, 1 trunc)"<<":  ";
    resetarFonte();
    cin >> *AoT;
    for (int i = 0; i< *foguetes; i++)
    {
        float a;
        cout << "\tInforme o parametro de ajuste para o foguete "<<i+1<<":  ";
        resetarFonte();
        cin >> a;
        fonteVerde();
        Metodos metodos = Metodos(*iteracoes);
        // setando os parametros comuns a todos os métodos
        metodos.setA(isolamentoA); // hardcoded inicio do intervalo (testes)
        metodos.setB(isolamentoB); // hardcoded fim do intervalo (teste)
        metodos.setErro(*E); // Setando o erro permitido
        metodos.ajuste = a; // Setando o ajuste
        metodos.newton(a, *casasdecimais, *iteracoes, *AoT); // Acha a raiz e guarda os valores
        metodos.Bissecao(a, *casasdecimais, *iteracoes, *AoT); // idem
        metodos.posicao_falsa(a, *casasdecimais, *iteracoes, *AoT); // idem
        vetor_metodos.push_back(metodos); // armazena no vetor
    }
}
void Interface::mostradados(vector<Metodos> vetor_metodos, int foguetes, int casasdecimais){
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
            resetarFonte();
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
            resetarFonte();
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
}
void Interface::printparametros(int foguetes, int iteracoes, float E, float casasdecimais, bool AoT){
    fonteVerde();
    inicioCarro();
    cout<<"│";
    cout << "\tFoguetes:"<<foguetes<<" Iteracoes: "<<iteracoes<<" Erro: "<<E <<" Casas Dec.:"<<casasdecimais;
    cout<<"\t\t\t\t    │"<<endl;
}
void Interface::menu() {
    fonteVerde();
    inicioCarro();
    cout<<"│";
    cout << "\tMENU -> [1 = RECALCULAR] [2 = DADOS] [3 = RECALIBRAR] [0 = SAIR]";
    cout<<"\t    │"<<endl;
}
