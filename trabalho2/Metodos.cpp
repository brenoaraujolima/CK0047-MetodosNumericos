#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Metodos {
    protected:
    int tam;                    //Numero de deslocamentos
    vector<vector<float>> A;    //Matriz de coeficientes
    vector<float> f;            //Vetor de termos independentes.
    vector<vector<float>> matrizL;
    vector<vector<float>> matrizU;
    vector<vector<float>> matrizD;
    vector<vector<float>> matrizP;

    public:
    Metodos(vector<vector<float>> A, vector<float> f, int tam);
    void setA(vector<vector<float>> matriz);
    vector<vector<float>> getA();
    void setTam(int tam);
    int getTam();
    void iniciarMatrizL();
    void iniciarMatrizU();
    vector<float> pivoteamento(vector<float> linhaPivo, vector<float> linhaOperanda, float multiplicador);
    void printarVetor(vector<float> vetor);
    void printarMatriz(vector<vector<float>> matriz);
    vector<float> fatoracaoLuNormal();
    vector<float> fatoracaoLDP();
    vector<float> solucionarSistemaInferior(vector<vector<float>> matrizL, vector<float> f);
    vector<float> solucionarSistemaSuperior(vector<vector<float>> matrizU, vector<float> f);
    void iniciarMatrizD(vector<vector<float>> matrizU);
    void iniciarMatrizP(vector<vector<float>> matrizU);
    vector<vector<float>> getMatrizL();
    vector<vector<float>> getMatrizD();
    vector<vector<float>> getMatrizP();
};

Metodos::Metodos(vector<vector<float>> A, vector<float> f, int tam) {
    this->A = A;
    this->f = f;
    this->tam = tam;
    iniciarMatrizL();
    iniciarMatrizU();
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

void Metodos::iniciarMatrizL() {
    matrizL.resize(this->getTam());
    for(int i=0; i<this->getTam(); i++) {
        matrizL[i].resize(this->getTam());
        for(int j=0; j<this->getTam(); j++) {
            if(i == j)  matrizL[i][j] = 1;
            else        matrizL[i][j] = 0;
        }
    }
}

void Metodos::iniciarMatrizU() {
    matrizU.resize(this->getTam());
    for(int i=0; i<this->getTam(); i++) {
        matrizU[i].resize(this->getTam());
        for(int j=0; j<this->getTam(); j++) {
            matrizU[i][j] = this->getA()[i][j];
        }
    }
}

vector<float> Metodos::fatoracaoLuNormal() {
    int iteracao = 0;
    float pivo;
    float multiplicador;

    for(int j=0; j<this->getTam(); j++) {
        pivo = matrizU[j][j];
        for(int i=j+1; i<matrizU.size(); i++) {
            multiplicador = matrizU[i][j]/pivo;
            matrizL[i][j] = multiplicador;
            matrizU[i] = pivoteamento(matrizU[iteracao],matrizU[i],multiplicador);
            multiplicador = matrizU[i][j]/pivo;
        }
        iteracao++;
    }
    //LY = b
    vector<float> y(this->getTam());
    y = solucionarSistemaInferior(this->matrizL,this->f);

    //Ux=y
    vector<float> x(this->getTam());
    x = solucionarSistemaSuperior(this->matrizU, y);
    for(int i=0; i<x.size(); i++) {
        x[i] = abs(x[i]);
    }
    return x;
}

vector<float> Metodos::pivoteamento(vector<float> linhaPivo, vector<float> linhaOperanda, float multiplicador) {
    for(int j=0;j<this->A.size(); j++) {
        linhaOperanda[j] = linhaOperanda[j] - multiplicador*linhaPivo[j];
    }
    return linhaOperanda;
}

vector<float> Metodos::solucionarSistemaInferior(vector<vector<float>> matriz, vector<float> f) {
    vector<float> x(matriz.size());
    float controlador;
    for(int i=0;i<x.size();i++) {
        controlador = 0;
        for(int j=0; j<i; j++) {
            if(matriz[i][j] != 0) {
                controlador = controlador + matriz[i][j]*x[j];  
            }
        }
        x[i] = (f[i]-controlador)/matriz[i][i];
    }
    return x;
}

vector<float> Metodos::solucionarSistemaSuperior(vector<vector<float>> matriz, vector<float> f) {
    vector<float> x(matriz.size());
    float controlador;
    for(int i=x.size()-1; i>=0; i--) {
        controlador=0;
        for(int j=x.size()-1; j>i; j--) {
            if(matriz[i][j] != 0) {
                controlador = controlador + matriz[i][j]*x[j];  
            }
        }
        x[i] = (f[i]-controlador)/matriz[i][i];
    }
    return x;
}

void Metodos::printarVetor(vector<float> vetor) {
    for(int i=0; i<vetor.size(); i++) {
        cout << vetor[i]<< "  ";
    }
}

void Metodos::printarMatriz(vector<vector<float>> matriz) {
    for(int i=0;i<matriz.size(); i++) {
        for(int j=0; j<matriz.size(); j++) {
            cout << matriz[i][j] <<"  ";
        }
        cout << endl;
    }
}

/******************* Inicio FatoracaoLDP *****************************/

void Metodos::iniciarMatrizD(vector<vector<float>> matrizU) {
    int n = this->matrizU.size();
    matrizD.resize(n);
    for(int i=0; i<n; i++) {
        matrizD.resize(n);
        for(int j=0; j<n; j++) {
            matrizD[i][j] = 0;
        }
    }
    printarMatriz(matrizD);
}

void Metodos::iniciarMatrizP(vector<vector<float>> matrizU) {
    this->matrizP = matrizU;
    for(int i=0; i<matrizU.size(); i++) {
        for(int j=0; j<matrizU.size(); j++) {
            this->matrizP[i][j] = (matrizU[i][j])/matrizU[i][i];
        }
    }
}

vector<float> Metodos::fatoracaoLDP() {
    iniciarMatrizD(this->matrizD);
    //printarMatriz(this->matrizD);

    vector<float> z = solucionarSistemaInferior(this->matrizL,this->f);
    /*vector<float> y = solucionarSistemaSuperior(this->matrizD,z);
    vector<float> x = solucionarSistemaSuperior(this->matrizP,y);*/
    //this->printarVetor(x);
    return z;
}












