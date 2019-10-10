#include <string>
#ifndef METODOS_H
#define METODOS_H

using namespace std;
class Metodos
{
private:
    float A;//var de inicio de intervalo [a;b]
    float B;//var de fim de intervalo[a;b]
    float E;//erro minimo
    float nd;//numero de casas decimais
    float a; //parametro de ajuste do foguete
    float AoT(float x, float nd, bool escolha);//retorna numero truncado ou arredondado
    float f(float d, float a);//metodo da funcao que o professor deu
public:
    struct dataMetodos{
        std::string nome;
        float * erro;
        float * deslocamento;
    };
    dataMetodos databissecao, datanewton, dataposfalsa;
    Metodos(int maxIter){ // construtor
        databissecao = {"bissecao", new float[maxIter], new float[maxIter]};
        datanewton = {"Newton", new float[maxIter], new float[maxIter]};
        dataposfalsa = {"Pos Falsa", new float[maxIter], new float[maxIter]};
    }
    ~Metodos(){ // destrutor
    }
    float Bissecao(float a, int nd, int kmax, bool escolha);
    float newton(float a, int nd, int kmax, bool escolha );//(descricao detalhada no metodo)
    /*
    a = parametro de ajuste, 
    nd = casas decimais, 
    kmax = maximo de iterações, 
    aot = Arredondamento ou truncamento (0 = truncamento, 1 = arredondamento)
     */ 
    float posicao_falsa(float a, int nd, int kmax, bool escolha); // método Posição Falsa
    bool testeSinal(float a, float b, float ajuste);
    float derivadaF(float d, float a);
    void setA(float interc);//atribuir valo para a inicio do intervalo
    void setB(float interf);//atribuir valor para o fim do intervalo
    void setErro(float erro);//atribuir valor para o erro minimo do calculo
 };
 
#endif