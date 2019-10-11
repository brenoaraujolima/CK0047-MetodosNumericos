#include<iostream>
#include<cstdio>
//#include<locale.h>
#include<stdlib.h>
using namespace std;


void fonteVerde() {
    cout << "\033[0;32m";
}

void resetarFonte() {
    cout<<"\033[1;0m";
}

void inicioCarro() {
    cout << "\t   ";
}

void molduraHorizontal() {
    for(int i=0; i<80; i++) {cout <<"═";}
}

void percorrerLinha() {
    fonteVerde();
    for(int i=0; i<80; i++) {cout <<" ";}
}

void header() {
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

void descricao() {
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

void menuInicial() {
    int foguetes;
    int parametro;
    float E;
    fonteVerde();
    inicioCarro();
    cout<<"\t"<<"Insira o nº de foguetes: ";
    cin >> foguetes;
    inicioCarro();
    cout<<"\t"<<"Informe a precisão desejada: ";
    cin >> E;
    system("clear");
    header();
    inicioCarro();
    cout << "\t Você está avaliando "<< foguetes << " foguetes."<<endl<<endl;

    for (int i = 0; i< foguetes; i++)
    {
        float a;
        inicioCarro();
        cout << "\t Informe o parametro de ajuste para o foguete "<<i+1<<":";
        cin >> a;
        /*Metodos metodos = Metodos(iteracoes);
        // setando os parametros comuns a todos os métodos
        metodos.setA(1.0f); // hardcoded inicio do intervalo (testes)
        metodos.setB(5.0f); // hardcoded fim do intervalo (teste)
        metodos.setErro(E); // Setando o erro permitido
        metodos.newton(a, casasdecimais, iteracoes, AoT); // Acha a raiz e guarda os valores
        metodos.Bissecao(a, casasdecimais, iteracoes, AoT); // idem
        metodos.posicao_falsa(a, casasdecimais, iteracoes, AoT); // idem
        vetor_metodos.push_back(metodos); // armazena no vetor*/
    }
}


int main() {
    //setlocale(LC_ALL, "");
    header();
    descricao();
    menuInicial();

    return 0;
}