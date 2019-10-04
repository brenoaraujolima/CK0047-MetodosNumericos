using namespace std;

class MetodoBissecao{
    private:
        float A;//var de inicio de intervalo [a;b]
        float B;//var de fim de intervalo[a;b]
        float E;//erro minimo
        float nd;//numero de casas decimais
        float a; //parametro de ajuste do foguete
        float AoT(float x, float nd, float );//retorna numero truncado ou arredondado
        float f(float d, float a);//metodo da funcao que o professor deu
    public:
        float Bissecao(float a, int nd, int kmax, int aot );//(descricao detalhada no metodo)
        void setA(float interc);//atribuir valo para a inicio do intervalo
        void setB(float interf);//atribuir valor para o fim do intervalo
        void setErro(float erro);//atribuir valor para o erro minimo do calculo

}


void MetodoBissecao::setA(float interc){
    this->A = interc;
}

void MetodoBissecao::setB(float interf){
    this->B = interf;
}

void MetodoBissecao::setErro(float erro){
    this->E = erro;
}


//AoT = Arredondamento ou Truncamento
float MetodoBissecao::AoT(float x, float nd, float aot){
    if(aot == 0) return trunc(nd*x)/nd;
    else return round(pow(10,nd)*x)/pow(10,nd);

}

//funcao que o professor deu
float MetodoBissecao::f(float d, float a){
    return (a*d - d*log(d));
}

//@parametros (parametro de ajuste, numero de decimais, máximo de iterações, escolha de arredondamento ou truncamento)
float MetodoBissecao::Bissecao(float ajuste, int nd, int kmax, int aot){
    float intervX, d , Fd;
    int k = 0;

    float A1 = AoT(A, nd, aot); //arrendondando ou truncando inicio do intervalo
    float B1 = AoT(B, nd, aot); //arrendondando ou truncando fim do intervalo
    
    float FA1 = AoT(f(A,ajuste), nd, aot); //FA1 com arredondamento ou truncamento
    float FB1 = AoT(f(B,ajuste),nd, aot);   //FB1 com arredondamento ou truncamento
    
    if(FA1 *FB1 > 0) cout << "Funcao nao converge no intervalo ["<< A1 << ";" << B2 <<"]" << endl;
    intervX = abs(A1-B1); //tamanho do intervalo
    
    do{
        d = AoT((A1+B1)/2, nd, aot );
        Fd = AoT(f(d,ajuste), nd, aot);

        if (FA1 * Fd > 0){
            A1 = d;
            FA1 = Fd;
        }else{
            B1 = d;
            FB1 = Fd;
        }
        intervX = AoT(intervX/2, nd, aot);
        k++;
        
    }while(abs(Fd) > E && intervX > E && k <= kmax);
    return d;
    
}
