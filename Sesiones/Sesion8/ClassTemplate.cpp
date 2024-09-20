/*
Sintaxis: 


template <class T>
class className{
    private: 
        T var; 
    ...
    public: 
        T functionName(T arg);
}
*/

#include<iostream> 

using namespace std;


template <class T>
class Number{
    private: 
        //Variable que es de tipo T
        T num; 

    public: 
        Number(T n) : num(n) {} // constructor

        T getNum(){
            return num;
        }
};


int main(){

    //Crea un objeto de tipo int
    Number<int> numberInt(7);

    //Crea un objeto de tipo double
    Number<double> numberDouble(7.7);

    cout << "Numero int: " << numberInt.getNum() << endl;
    cout << "Numero Double" << numberDouble.getNum() << endl; 
    
}