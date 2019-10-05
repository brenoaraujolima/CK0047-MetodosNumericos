#include<cmath>
#include<iostream>

using namespace std;

class MetodoNewton {
    private:
        float A;//var de inicio de intervalo [a;b]
        float B;//var de fim de intervalo[a;b]
        float E;//erro minimo
        float nd;//numero de casas decimais
        float a; //parametro de ajuste do foguete
        float AoT(float x, float nd, bool escolha);//retorna numero truncado ou arredondado
        float f(float d, float a);//metodo da funcao que o professor deu
    public:
        MetodoNewton(float a, float E);
        float newton(float a, int nd, int kmax, bool aot );//(descricao detalhada no metodo)
        void setA(float interc);//atribuir valo para a inicio do intervalo
        void setB(float interf);//atribuir valor para o fim do intervalo
        void setErro(float erro);//atribuir valor para o erro minimo do calculo
        float getA();
        float getB();
        float getE();
        bool testeSinal(float a, float b);
        float f(float x);
        float derivadaF(float d); //calcula derivada da funcao no ponto x.

};

//Metodo construtor de calibraçao do sistema
    MetodoNewton::MetodoNewton(float a, float E) {
        this->a = a;
        this->E = E;
        this->nd = 6;
        this->A = 2;
        this->B = 3;
    }

//atribuir valor para o inicio do intervalo
void MetodoNewton::setA(float interc) {
    this->A = interc;
}

//atribuir valor para o fim do intervalo
void MetodoNewton::setB(float interf) {
    this->B = interf;
}

//atribuir valor para o erro minimo do calculo
void MetodoNewton::setErro(float erro) {
    this->E = erro;
}

float MetodoNewton::getA() {
    return this->A;
}

float MetodoNewton::getB() {
    return this->B;
}

//retorna numero truncado ou arredondado
float MetodoNewton::AoT(float x, float nd, bool escolha) {
    if(escolha == true)     return round(pow(10,nd)*x)/pow(10,nd);
    else                    return trunc(nd*x)/nd;
}

float MetodoNewton::f(float d) {
    return getA()*d - d*log(d);
}

//Teste de convergencia da funcao.
bool MetodoNewton::testeSinal(float a, float b) {
    if((this->f(a) * this->f(b)) > 0) {
        return false;
    }
    else {
        return true;
    }      
}

//calcula derivada da função dada pelo professor no ponto x.
float MetodoNewton::derivadaF(float d) {
    return getA()-log(d)-1;
}

//parametro foguete, numero de casas decimais, maximo de iteracoes, escolha de arrend. ou trunc.
float MetodoNewton::newton(float a, int nd, int kmax, bool escolha) {
    int iter = 0; //iteração corrente.
    float xAtual, xAnterior; //Variaveis que receberao o isolamento inicial.
    float inicio = this->AoT(getA(),nd,escolha);
    float final = this->AoT(getB(),nd,escolha);

    if(testeSinal(inicio,final) == false) {
        cout << "O Intervalo ["<<inicio<<","<<final<<"] não converge"<< endl;
    }

    xAnterior = (inicio + final)/2;

    if(abs(f(xAnterior)) < this->E) {
        return xAnterior;
    }

    while(iter<=kmax) {
        xAtual = xAnterior - (f(xAnterior)/derivadaF(xAnterior));
        if(f(xAtual) < this->E || abs(xAtual - xAnterior) < this->E) {
            return xAtual;
        }
        iter++;
    }
    return xAtual;
}