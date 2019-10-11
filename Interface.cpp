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
    percorrerLinha();
    cout<<"│"<<endl;
    inicioCarro();
    resetarFonte();
    cout<<"\tPara utilizar, preencha os parametros abaixo."<<endl;
     
    cout<<endl;
    cout<<endl;
}

void Interface::menuInicial(int * foguetes, float * E) {
    fonteVerde();
    inicioCarro();
    cout<<"\t"<<"Insira o nº de foguetes: ";
    cin >> *foguetes;
    inicioCarro();
    cout<<"\t"<<"Informe a precisão desejada: ";
    cin >> *E;
    system("clear");
    header();
    inicioCarro();
    cout << "\t Você está avaliando "<< *foguetes << " foguetes."<<endl<<endl;

}