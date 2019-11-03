
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Metodos {
    protected:
    int tam;        //Numero de deslocamentos
    vector<vector<float>> A;    //Matriz de coeficientes
    vector<float> f;    //Vetor de teromos independentes.

    public:
    Metodos(vector<vector<float>> A, vector<float> f, int tam);
    void setA(vector<vector<float>> matriz);
    vector<vector<float>> getA();
    void setTam(int tam);
    int getTam();
    vector<vector<float>> iniciarMatrizL();
    vector<float> pivoteamento(vector<float> linhaPivo, vector<float> linhaOperanda, float multiplicador);
    void printarMatriz(vector<vector<float>> matriz);
    //Funçoes de calculo dos metodos;
    vector<float> fatoracaoLuNormal();
};

Metodos::Metodos(vector<vector<float>> A, vector<float> f, int tam) {
    this->A = A;
    this->f = f;
    this->tam = tam;
}

void Metodos::setA(vector<vector<float>> matriz) {
    this->A = matriz;
}

vector<vector<float>> Metodos::getA() {
    return this->A;
}

void Metodos::setTam(int tam) {
    this->tam = tam;
}

int Metodos::getTam() {
    return this->tam;
}

vector<vector<float>> Metodos::iniciarMatrizL() {
    vector<vector<float>> matriz(this->getTam(), vector<float>(this->getTam()));

    for(int i=0; i<matriz.size(); i++) {
        for(int j=0; j<matriz.size(); j++) {
            if(i == j)  matriz[i][j] = 1;
            else        matriz[i][j] = 0;
        }
    }
    return matriz;
}

vector<float> Metodos::fatoracaoLuNormal() {
    vector<vector<float>> matrizU{this->A};    //Matriz a ser aplicada a eliminação gauss
    vector<vector<float>> matrizL{iniciarMatrizL()};
    int iteracao = 0;
    float pivo;
    float multiplicador;

    for(int j=0; j<matrizU.size(); j++) {
        pivo = matrizU[j][j];
        for(int i=j+1; i<matrizU.size(); i++) {
            multiplicador = matrizU[i][j]/pivo;
            matrizL[i][j] = multiplicador;
            matrizU[i] = pivoteamento(matrizU[iteracao],matrizU[i],multiplicador);
            multiplicador = matrizU[i][j]/pivo;
        }
        iteracao++;
    }
}

vector<float> Metodos::pivoteamento(vector<float> linhaPivo, vector<float> linhaOperanda, float multiplicador) {
    for(int j=0;j<this->A.size(); j++) {
        linhaOperanda[j] = linhaOperanda[j] - multiplicador*linhaPivo[j];
    }
    return linhaOperanda;
}

void Metodos::printarMatriz(vector<vector<float>> matriz) {
    cout << "teste5" << endl;
    for(int i=0;i<matriz.size(); i++) {
        for(int j=0; j<matriz.size(); j++) {
            cout << matriz[i][j] <<"  ";
        }
        cout << endl;
    }
}