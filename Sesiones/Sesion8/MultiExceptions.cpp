#include<iostream> 

using namespace std; 

int main(){

    double numerator, denominator , arr[4] = {0.0, 0.0, 0.0, 0.0};
    int index; 

    cout << "Ingrese el indice del array: " << endl; 
    cin >> index; 

    try {

        //trhow exception si el array esta fuera de indice
        if(index >=4 ) throw "Error: Arrar fuera de indice ";

        cout << "Ingrese el numerador: " ;
        cin >> numerator; 

        cout << "Ingrese el denominador: " ;
        cin >> denominator; 

        // Tira excepcion si el denominador es 0
        if (denominator == 0) throw 0;


        //Si el denominador es cero esto no se ejecuta
        arr[index] = numerator / denominator;
        cout << arr[index] << endl; 
    }

    //Agarra la excepcion de "Array fuera de bounds" 
    catch (const char* msg){
        cout << msg << endl; 
    }

    //Agarrar la excepcion de division por cero
    catch(int num){
        cout << "Error: no se puede dividir por " << num << endl; 
    }



    //Agarrar cualquier otra excepcion 

    catch(...){
        cout << "Error inesperado" << endl; 
    }

    return 0; 
}