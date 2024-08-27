#include <iostream>

using namespace std;

class Fraccion{
    int numerador, denominador;
    public:
    Fraccion(int n, int d) : numerador(n), denominador(d){}

    Fraccion operator+ (const Fraccion &f){
        Fraccion resultado(
            numerador*f.denominador + f.numerador* denominador,
            denominador*f.denominador

        );

        return resultado;
    }


    void imprimir(){
        cout << numerador << "/" << denominador << endl;
    }
};

int main(){
    Fraccion f1(1,2);
    Fraccion f2(3,4);

    Fraccion f3 = f1 + f2;

    f3.imprimir();
    return 0; 

}