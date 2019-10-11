/*
Arquivo de prototipos da classe Interface.cpp
*/
#ifndef INTERFACE_H
#define INTERFACE_H
#include "Metodos.h"
using namespace std;
class Interface{
    private:

    public:
        Interface(){ // construtor
        }
        ~Interface(){ // destrutor
        }
        void fonteVerde();
        void resetarFonte();
        void inicioCarro();
        void molduraHorizontal();
        void percorrerLinha();
        void header();
        void descricao();
        void menuInicial(int * foguetes, float * E);
        void loopParametros(int *foguetes, int *iteracoes, float *E, float *casasdecimais, bool *AoT, vector<Metodos>& vetor_metodos);
        void decisaoFinal(bool *decisao);
};
#endif