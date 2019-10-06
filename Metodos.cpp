#include <iostream>
#include <cmath>
#include "Metodos.h"

using namespace std;

void Metodos::setA(float interc){
    this->A = interc;
}

void Metodos::setB(float interf){
    this->B = interf;
}

void Metodos::setErro(float erro){
    this->E = erro;
}

//AoT = Arredondamento ou Truncamento
float Metodos::AoT(float x, float nd, float aot){
    if(aot == 0) return trunc(nd*x)/nd;
    else return round(pow(10,nd)*x)/pow(10,nd);

}

//funcao que o professor deu
float Metodos::f(float d, float a){
    return (a*d - d*log(d));
}

//funcao que o professor deu
float Metodos::f2(float d){
    return (A*d - d*log(d));
}

//calcula derivada da função dada pelo professor no ponto x.
float Metodos::derivadaF(float d) {
    return A - log(d)-1;
}

//Teste de convergencia da funcao.
bool Metodos::testeSinal(float a, float b) {
    if((this->f2(a) * this->f2(b)) > 0) {
        return false;
    }
    else {
        return true;
    }      
}

//@parametros (parametro de ajuste, numero de decimais, máximo de iterações, escolha de arredondamento ou truncamento)
float Metodos::Bissecao(float ajuste, int nd, int kmax, int aot){
    float intervX, d , Fd;
    int k = 0;
    
    float A1 = Metodos::AoT(A, nd, aot); //arrendondando ou truncando inicio do intervalo
    float B1 = Metodos::AoT(B, nd, aot); //arrendondando ou truncando fim do intervalo
    
    float FA1 = Metodos::AoT(f(A,ajuste), nd, aot); //FA1 com arredondamento ou truncamento
    float FB1 = Metodos::AoT(f(B,ajuste),nd, aot);   //FB1 com arredondamento ou truncamento
    
    if(FA1 * FB1 > 0) cout << "Funcao nao converge no intervalo ["<< A1 << ";" << B1 <<"]" << endl;
    intervX = abs(A1-B1); //tamanho do intervalo
    
    do{
        d = Metodos::AoT((A1+B1)/2, nd, aot );
        Fd = Metodos::AoT(f(d,ajuste), nd, aot);

        if (FA1 * Fd > 0){
            A1 = d;
            FA1 = Fd;
        }else{
            B1 = d;
            FB1 = Fd;
        }
        intervX = Metodos::AoT(intervX/2, nd, aot);
        k++;
    } while(abs(Fd) > E && intervX > E && k <= kmax);
    Metodos::databissecao.erro[k] = d;
    return d;
}

//parametro foguete, numero de casas decimais, maximo de iteracoes, escolha de arrend. ou trunc.
float Metodos::newton(float a, int nd, int kmax, bool escolha) {
    cout<<A<<endl;
    int iter = 0; //iteração corrente.
    float xAtual, xAnterior; //Variaveis que receberao o isolamento inicial.
    float inicio = this->AoT(A,nd,escolha);
    float final = this->AoT(B,nd,escolha);

    if(testeSinal(inicio,final) == false) {
        cout << "O Intervalo ["<<inicio<<","<<final<<"] não converge"<< endl;
    }

    xAnterior = (inicio + final)/2;

    if(abs(f2(xAnterior)) < this->E) {
        Metodos::datanewton.erro[iter] = xAtual;
        return xAnterior;
    }

    while(iter<=kmax) {
        xAtual = xAnterior - (f2(xAnterior)/derivadaF(xAnterior));
        if(abs(f2(xAtual)) < this->E || abs(xAtual - xAnterior) < this->E) {
            Metodos::datanewton.erro[iter] = xAtual;
            return xAtual;
        }
        xAnterior = xAtual;
        iter++;
    }
    Metodos::datanewton.erro[iter] = xAtual;
    return xAtual;
}

// Método da PosicaoFalsa
float Metodos::posicao_falsa(float a, int nd, int kmax, bool escolha){
    
    int iter = 0; //iteração corrente.
    float xAtual, xAnterior; //Variaveis que receberao o isolamento inicial.
    float inicio = this->AoT(A,nd,escolha);
    float final = this->AoT(B,nd,escolha);
   
    if(testeSinal(inicio,final) == false) {
        cout << "O Intervalo ["<<inicio<<","<<final<<"] não converge"<< endl;
    }
    float xp = (inicio * this->f2(final)-final * this->f2(inicio)) / (this->f2(final)-this->f2(inicio));
     cout<<this->f2(inicio)<<endl; 
    float tmpErr = min(abs(this->f2(xp)),(final-inicio));

    while (tmpErr > this->E && iter <= kmax) {
        if (this->f2(inicio) * f2(xp) > 0) { 
            inicio = xp;
        }else{
            final = xp;
        }
        xp = (inicio * f2(final) - final * f2(inicio)) / (f2(final) - f2(inicio));
        tmpErr = min(abs(this->f2(xp)),(final-inicio));
        Metodos::dataposfalsa.erro[iter] = tmpErr;
        iter++;
    }
    return tmpErr;

}