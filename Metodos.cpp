#include <iostream>
#include <cmath>
#include <iostream>
#include <fstream>
#include <ctime>
#include "Metodos.h"

using namespace std;

void Metodos::setA(float interc){
    A = interc;
}
float Metodos::getA(){return A;}

void Metodos::setB(float interf){
    B = interf;
}
float Metodos::getB(){return B;}

void Metodos::setErro(float e){
    E = e;
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
    float intervX, d , Fd;
    int k = 0;
    
    float A1 = AoT(A, nd, escolha); //arrendondando ou truncando inicio do intervalo
    float B1 = AoT(B, nd, escolha); //arrendondando ou truncando fim do intervalo
    
    float FA1 = AoT(f(A,ajuste), nd, escolha); //FA1 com arredondamento ou truncamento
    float FB1 = AoT(f(B,ajuste),nd, escolha);   //FB1 com arredondamento ou truncamento

    if(FA1 * FB1 > 0){
        datametodos[0].converge = false;
        return 0;
    } 
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
        datametodos[0].erros[k] = AoT(intervX, nd, escolha);
        datametodos[0].deslocamento[k] = AoT(d, nd, escolha);
        datametodos[0].Fa[k] = FA1;
        datametodos[0].Fb[k] = FB1;
        datametodos[0].a[k] = A1;
        datametodos[0].b[k] = B1;
        if(d > 2 + E){
            datametodos[0].fogueteexplode = true;
        }
        if(intervX < E){
            // valor aproximado encontrado, retornando
            datametodos[0].converge = true;
            datametodos[0].raiz = d;
            datametodos[0].iter = k;
            datametodos[0].erro = datametodos[0].erros[k];
            return d;
        }
        k++;
    } while(intervX > E && k <= kmax);
    
    
    datametodos[0].converge = false;
    datametodos[0].iter = k-1;
    return 0;
}

//parametro foguete, numero de casas decimais, maximo de iteracoes, escolha de arrend. ou trunc.
float Metodos::newton(float a, int nd, int kmax, bool escolha) {
    int iter = 0; //iteração corrente.
    float xAnterior = AoT(A,nd,escolha);
    float xAtual = AoT(B,nd,escolha);

    if(testeSinal(f(xAnterior, a),f(xAtual, a), a) == false) {
        datametodos[1].converge = false;
        return 0;
    }
    datametodos[1].deslocamento[iter] = AoT(xAtual, nd, escolha);
    datametodos[1].erros[iter] = AoT(abs(xAtual - xAnterior), nd, escolha);
    datametodos[1].Fa[iter] = AoT(f(xAnterior, a), nd, escolha);
    datametodos[1].Fb[iter] = AoT(f(xAtual, a), nd, escolha);
    datametodos[1].a[iter] = xAnterior;
    datametodos[1].b[iter] = xAtual;
    xAnterior = (xAnterior + xAtual)/2;
    if(abs(f(xAnterior, a))<E) {
        datametodos[1].deslocamento[iter] = AoT(xAnterior, nd, escolha);
        datametodos[1].erros[iter] = AoT(abs(f(xAnterior, a)), nd, escolha);
        datametodos[1].erro = datametodos[1].erros[iter];
        datametodos[1].raiz = xAnterior;
          
        return xAnterior;
    }

    while(iter<=kmax) {
        xAtual = xAnterior - (f(xAnterior, a)/derivadaF(xAnterior, a));
        if(abs(xAtual - xAnterior)<E) {
            datametodos[1].deslocamento[iter] = AoT(xAtual, nd, escolha);
            datametodos[1].erros[iter] = AoT(min(abs(f(xAtual, a)), abs(xAtual - xAnterior)), nd, escolha);
            datametodos[1].iter = iter;
            datametodos[1].erro = datametodos[1].erros[iter];
            datametodos[1].raiz = xAtual;
            datametodos[1].converge = true;
            return xAtual;
        }
        datametodos[1].deslocamento[iter] = AoT(xAtual, nd, escolha);
        datametodos[1].erros[iter] = AoT(abs(xAtual - xAnterior), nd, escolha);
        datametodos[1].Fa[iter] = AoT(f(xAnterior, a), nd, escolha);
        datametodos[1].Fb[iter] = AoT(f(xAtual, a), nd, escolha);
        datametodos[1].a[iter] = xAnterior;
        datametodos[1].b[iter] = xAtual;
        cout<<xAtual<<",";
        if(xAtual > 2 + E){
            datametodos[1].fogueteexplode = true;
        }
        
        xAnterior = xAtual;
        iter++;
    }
    datametodos[1].erro = datametodos[1].erros[iter-1];
    datametodos[1].converge = false;
    return xAtual;
}

// Método da PosicaoFalsa
float Metodos::posicao_falsa(float a, int nd, int kmax, bool escolha){
    float intervX, d , Fd;
    int k = 0;
    
    float A1 = AoT(A, nd, escolha); //arrendondando ou truncando inicio do intervalo
    float B1 = AoT(B, nd, escolha); //arrendondando ou truncando fim do intervalo
    
    float FA1 = AoT(f(A,ajuste), nd, escolha); //FA1 com arredondamento ou truncamento
    float FB1 = AoT(f(B,ajuste),nd, escolha);   //FB1 com arredondamento ou truncamento
    
    while(k <= kmax){
        d = AoT(B1 - (FB1 * (B1 - A1))/(FB1 - FA1), nd, escolha );
        Fd = AoT(f(d,ajuste), nd, escolha);
        if(abs(d - B1) < E || abs(Fd) < E){
            //achou a aproximacao
            datametodos[2].erros[k] = AoT(intervX, nd, escolha);
            datametodos[2].deslocamento[k] = AoT(d, nd, escolha);
            datametodos[2].iter = k;
            datametodos[2].raiz = d;
            datametodos[2].erro = abs(Fd);
            datametodos[2].converge = true;
            return min(abs(d - B1), abs(f(d,ajuste)));
        }
        datametodos[2].erros[k] = abs(Fd);
        datametodos[2].deslocamento[k] = d;
        datametodos[2].Fa[k] = FA1;
        datametodos[2].Fb[k] = FB1;
        datametodos[2].a[k] = A1;
        datametodos[2].b[k] = B1;
        if (FA1 * Fd > 0){
            A1 = d;
            FA1 = Fd;
        }else{
            B1 = d;
            FB1 = Fd;
        }   
        if(d > 2 + E){
            datametodos[0].fogueteexplode = true;
        }
        k++;
    };
    datametodos[2].iter = k-1;
    datametodos[2].converge = false;
    
}

void Metodos::setGravaDados(int foguete, int iteracoes){
    ofstream arquivoerro;
    //ofstream arquivodesl;
    arquivoerro.open ("erros.txt");
    // grafico de comparacao dos metodos (erro versus iteracoes)
    for(int j = 0; j<iteracoes; j++){
        arquivoerro << j+1;
        arquivoerro << "\t";
        
        arquivoerro << datametodos[0].erros[j];
        arquivoerro << "\t";
        arquivoerro << datametodos[1].erros[j];
        arquivoerro << "\t";
        arquivoerro << datametodos[2].erros[j];
        arquivoerro << "\t";
        arquivoerro<<"\n";
    }
    arquivoerro.close();

    // grafico de evolucao da secante
    arquivoerro.open ("dados_secante.txt");
    for(int j = 0; j<iteracoes; j++){
        arquivoerro << datametodos[2].a[j];
        arquivoerro << "\t";
        arquivoerro << datametodos[2].Fa[j];
        arquivoerro << "\t";
        arquivoerro<<"\n";
        arquivoerro << datametodos[2].b[j];
        arquivoerro << "\t";
        arquivoerro << datametodos[2].Fb[j];
        arquivoerro<<"\n";
        arquivoerro<<"\n";
    }
    arquivoerro.close();
}