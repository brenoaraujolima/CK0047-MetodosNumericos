#include<iostream>
#include<cstdio>
//#include<locale.h>
#include<stdlib.h>
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
    system("clear");
    header();
    inicioCarro();
    cout << "\t Você está avaliando "<< *foguetes << " foguetes."<<endl<<endl;

}

void Interface::loopParametros(int *foguetes, int *iteracoes, float *E, float *casasdecimais, bool *AoT, vector<Metodos>& vetor_metodos) {
    // para cada foguete, instaciamos uma classe com os métodos e armazenamos no vetor
    for (int i = 0; i< *foguetes; i++)
    {
        float a;
        inicioCarro();
        cout << "\tInforme o parametro de ajuste para o foguete "<<i+1<<":  ";
        resetarFonte();
        cin >> a;
        fonteVerde();
        Metodos metodos = Metodos(*iteracoes);
        // setando os parametros comuns a todos os métodos
        metodos.setA(0.0001f); // hardcoded inicio do intervalo (testes)
        metodos.setB(1000.0f); // hardcoded fim do intervalo (teste)
        metodos.setErro(*E); // Setando o erro permitido
        metodos.ajuste = a; // Setando o ajuste
        metodos.newton(a, *casasdecimais, *iteracoes, *AoT); // Acha a raiz e guarda os valores
        metodos.Bissecao(a, *casasdecimais, *iteracoes, *AoT); // idem
        metodos.posicao_falsa(a, *casasdecimais, *iteracoes, *AoT); // idem
        vetor_metodos.push_back(metodos); // armazena no vetor
    }
}

void Interface::decisaoFinal(bool *decisao) {
    fonteVerde();
    cout << endl;
    cout << "Digite 1 para uma novo cálculo" << endl;
    cout << "Digite 0 para sair"<< endl;
    cin >> *decisao;
}
