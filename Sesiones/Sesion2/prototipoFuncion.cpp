#include <iostream>

using namespace std; 

//Prototipo funcion
int add(int, int);

int main(){

    int sum;

    sum = add(100, 78);

    cout << "100 + 78 = " << sum << endl;

    return 0;


}

int add(int a, int b){
    return (a + b);
}