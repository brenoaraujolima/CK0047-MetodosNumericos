#include <iostream>
#include <cmath>
#include "Metodos.h"

using namespace std;

void Metodos::setA(float interc){
    A = interc;
}

void Metodos::setB(float interf){
    B = interf;
}

void Metodos::setErro(float erro){
    E = erro;
}


//retorna numero truncado ou arredondado
float Metodos::AoT(float x, float nd, bool escolha) {
    if(escolha == true)     return round(pow(10,nd)*x)/pow(10,nd);
    else                    return trunc(pow(10,nd)*x)/pow(10,nd);
}

//funcao que o professor deu
float Metodos::f(float d, float a){
    return (a*d - d*log(d));
}


//calcula derivada da função dada pelo professor no ponto x.
float Metodos::derivadaF(float d, float a) {
    return a - log(d)-1;
}

//Teste de convergencia da funcao.
bool Metodos::testeSinal(float a, float b, float ajuste) {
    if((f(a, ajuste) * f(b, ajuste)) > 0) {
        return false;
    }
    else {
        return true;
    }      
}

//@parametros (parametro de ajuste, numero de decimais, máximo de iterações, escolha de arredondamento ou truncamento)
float Metodos::Bissecao(float ajuste, int nd, int kmax, bool escolha){
    float tmpagora = time(0);
    float intervX, d , Fd;
    int k = 0;
    
    float A1 = AoT(A, nd, escolha); //arrendondando ou truncando inicio do intervalo
    float B1 = AoT(B, nd, escolha); //arrendondando ou truncando fim do intervalo
    
    float FA1 = AoT(f(A,ajuste), nd, escolha); //FA1 com arredondamento ou truncamento
    float FB1 = AoT(f(B,ajuste),nd, escolha);   //FB1 com arredondamento ou truncamento

    if(FA1 * FB1 > 0) cout << "Funcao nao converge no intervalo ["<< A1 << ";" << B1 <<"]" << endl;
    intervX = abs(A1-B1); //tamanho do intervalo
    
    do{
        d = AoT((A1+B1)/2, nd, escolha );
        Fd = AoT(f(d,ajuste), nd, escolha);
        if (FA1 * Fd > 0){
            A1 = d;
            FA1 = Fd;
        }else{
            B1 = d;
            FB1 = Fd;
        }
        intervX = abs(A1-B1);
        datametodos[0].erro[k] = AoT(intervX, nd, escolha);
        datametodos[0].deslocamento[k] = AoT(d, nd, escolha);
        k++;
    } while(abs(Fd) > E && intervX > E && k <= kmax);
    if(intervX > abs(Fd)){
        datametodos[0].erro[k] = AoT(abs(Fd), nd, escolha);
    }else{
        datametodos[0].erro[k] = AoT(intervX, nd, escolha);
    }
    
    datametodos[0].deslocamento[k] = AoT(d, nd, escolha);
    datametodos[0].iter = k;
    return d;
}

//parametro foguete, numero de casas decimais, maximo de iteracoes, escolha de arrend. ou trunc.
float Metodos::newton(float a, int nd, int kmax, bool escolha) {
    int iter = 0; //iteração corrente.
    float xAnterior = AoT(A,nd,escolha);
    float xAtual = AoT(B,nd,escolha);

    if(testeSinal(f(xAnterior, a),f(xAtual, a), a) == false) {
        cout << "O Intervalo ["<<xAnterior<<","<<xAtual<<"] não converge"<< endl;
    }

    xAnterior = (xAnterior + xAtual)/2;
    if(abs(f(xAnterior, a))<E) {
        return xAnterior;
        datametodos[1].deslocamento[iter] = AoT(xAnterior, nd, escolha);
        datametodos[1].erro[iter] = AoT(abs(f(xAnterior, a)), nd, escolha);
    }

    while(iter<=kmax) {
        xAtual = xAnterior - (f(xAnterior, a)/derivadaF(xAnterior, a));
        if(abs(f(xAtual, a))<E || abs(xAtual - xAnterior)<E) {
            return xAtual;
            datametodos[1].deslocamento[iter] = AoT(xAtual, nd, escolha);
            datametodos[1].erro[iter] = AoT(min(abs(f(xAtual, a)), abs(xAtual - xAnterior)), nd, escolha);
            datametodos[1].iter = iter;
        }
        datametodos[1].deslocamento[iter] = AoT(xAtual, nd, escolha);
        datametodos[1].erro[iter] = AoT(min(abs(f(xAtual, a)), abs(xAtual - xAnterior)), nd, escolha);
        xAnterior = xAtual;
        iter++;
    }
    cout << "nao convergiu apos "<<iter<<" iteracoes"<< endl;
    return xAtual;
}

// Método da PosicaoFalsa
float Metodos::posicao_falsa(float a, int nd, int kmax, bool escolha){
    
    return 0;

}