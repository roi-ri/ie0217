#include  <iostream> //input output stream que permite imprimir por pantalla
#include "sum.hpp"


int main(){

    int num1 = 5;
    int num2 = 3; 
    int result = sum(num1, num2);

    std::cout << "El resultado de " << num1 << " + " << num2 << " es igual a: " << result << std::endl;



    return 0; 


}
