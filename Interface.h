/*
Arquivo de prototipos da classe Interface.cpp
*/
#ifndef INTERFACE_H
#define INTERFACE_H

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
};
#endif