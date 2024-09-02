#include<iostream>
using namespace std;

int main(){
    // declarar variable puntero entero
    int* pointInt;

    // declarar variable puntero float
    float* pointFloat;

    // Alocar memoria dinamica
    pointInt = new int;
    pointFloat = new float;


    // Asignar valores a las variables
    *pointInt = 45;
    *pointFloat = 45.45f;

    // Mostrar los valores de las variables
    cout << "Valor de la variable int: " << *pointInt << endl;
    cout << "Valor de la variable float: " << *pointFloat << endl;

    // Liberar la memoria dinamica
    delete pointInt;
    delete pointFloat;

    return 0;
}

// Uso con arrays

int main(){

    int num;
    cout << "Enter total number of students"<< endl;
    cin >> num;
    float* ptr;

    // alocar memoria
    ptr = new float[num];

    cout << "Enter GPA of students." << endl;
    for(int i =0; i < num; i++){
        cout << "Student " << i + 1 << ":" << *(ptr + i) << endl;
        cin >> *(ptr + i);
    }

    cout << "\nDisplaying GPA of students." << endl;
    for (int i = 0; i < num; i++){
        cout << "Student" << i + 1<< ":" << *(ptr + i) << endl;
    }

    // liberar memoria de punteros
    delete[] ptr;

    return 0;
}



