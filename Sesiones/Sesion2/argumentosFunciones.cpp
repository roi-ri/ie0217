#include <iostream>

using namespace std; 

//display a number
void displayNum(int n1, float n2){
    cout << "The int number is " << n1 << '\n';
    cout << "The float number is " << n2; 
}

int main(){
    int num1 = 5; 
    double num2 = 5.5;

    //calling the function 
    displayNum(num1, num2);

    return 0; 
}

//Segunda funcion utilizada con argumentos
int main(int argc, char* argv[]){

    std::cout << "Número de argumentos: " << argc << std::endl;
    std::cout << "Nombre del programa: " << argv[0] << std::endl;

    //Imprimir argumentos aficionales si existen 
    if (argc > 1){
        std::cout << "Argumentos adicionales: " << std::endl;
        for (int i = 1; i < argc; ++i){
            std::cout << "argv[' << i << ' ]: " << argv[i] << std::endl;
        }
    }
    return 0;

}

//Funcion 3

int add(int a, int b){
    return (a + b);
}

int main(){

    int sum; 

    //Llamar a la funcion 
    //el valor del return value in sum 
    sum = add(100, 78);

    cout << "100 + 78 =" << sum << endl;

    return 0; 

}

