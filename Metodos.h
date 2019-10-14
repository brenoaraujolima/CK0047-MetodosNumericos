#include <string>
#include <vector>
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
    float ajuste;
    /*
    Armazenaremos dados calculados por cada metodo para serem utilizados posteriormente
    erros: array com o historico dos erros calculados em cada iteracao do metodo em busca da raiz
    deslocamento: array com o historico do deslocamento, pode ser util pra montar um grafico
    erro: erro final calculado (ultimo erro inserido no array erros)
    raiz: caso encontre uma raiz, sera armazenada aqui 
    (posteriormente pode-se pensar em usar um array para o caso de funcoes com multiplas raizes)
    iter: quantidade de iteracoes necessarias ate encontrar a raiz aproximada
    converge: registra se o metodo converge ou nao
    */
    struct dataMetodos{
        std::string nome;
        float * erros;
        float * deslocamento;
        float erro;
        float raiz;
        int iter;
        bool converge;
    };
    vector<dataMetodos> datametodos;
    
    Metodos(int maxIter){ // construtor
        datametodos.push_back({"Bissecao", new float[maxIter], new float[maxIter]});
        datametodos.push_back({"Newton", new float[maxIter], new float[maxIter]});
        datametodos.push_back({"Pos Falsa", new float[maxIter], new float[maxIter]});
      }
    ~Metodos(){ // destrutor
        datametodos.clear();
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
    float getA();
    void setB(float interf);//atribuir valor para o fim do intervalo
    float getB();
    void setErro(float e);
    // Salva os dados em um arquivo para relatorio
    void setGravaDados(int foguete, int iteracoes);
 };
 
#endif