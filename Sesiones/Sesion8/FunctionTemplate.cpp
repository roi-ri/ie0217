#include<iostream> 

using namespace std; 


/*
Sintaxis de un template: 
template<typename T>
T functionName(T parameter1, T parameter2){
}

*/


//Creando el template
template <typename T>
T add(T num1, T num2){
    return (num1 + num2);
}


int main(){

    int result; 
    double result2;
    //llamando con parámetros tipo int 
    result = add<int>(2,3);
    cout << "2 + 3 =" << result << endl;
    //llamando al template con parámetros tipo double
    result2 = add<double>(2.2,3.3);
    cout << "2.2 + 3.3 = "result2 << endl;

    return 0;

}
