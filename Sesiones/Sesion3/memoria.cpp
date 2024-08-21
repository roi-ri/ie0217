#include <iostream> 
 using namespace std;

//Toda variable tiene un lugar fisico donde esta almacenada
 int main(){

    int var1 = 3;
    int var2 = 24;
    int var3 = 17;


    cout << " Adress of var1: " << &var1 << endl; 
    cout << " Adress of var2: " << &var2 << endl; 
    cout << " Adress of var3: " << &var3 << endl;


    return 0; 
 }