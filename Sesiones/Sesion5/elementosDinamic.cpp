#include <iostream>
#include<cstdlib>

using namespace std;

// Uso de malloc

int main(){
    // Alocar memoria de un tamano entero a un puntero entero
    int* ptr = (int*) malloc(sizeof(int));

    // asignar valor 
    *ptr = 5;

    cout << *ptr << endl;

    free(ptr);//Liberar la memoria asignada, evitar memory leak
    return 0; 

}

// ejemplo con uso de calloc


int main(){
    int *ptr;
    ptr = (int *)calloc(5, sizeof(int));
    if(!ptr){
        cout << "Memory allocation failed" << endl;
        exit(1);
    }
    cout << "Initializing values" << endl;
    for (int i = 0; i < 5; i++){
        cout << *(ptr + i) << endl;

    }

    free(ptr);//Liberar la memoria asignada
    return 0;
}

// uso con realloc


int main(){
    float *ptr, *new_ptr;
    ptr = (float*)malloc(5*sizeof(float));
    if(ptr == NULL){
        cout << 'Memory allocation failed' << endl;
        exit(1);
    }
    //iniciar bloquie de memoria 
    for (int i = 0; i < 5; i++){
        ptr[i] = i * 1.5; 
    }

    //realocar memoria
    new_ptr = (float*)realloc(ptr, 10*sizeof(float));
    if(new_ptr == NULL){
        cout << "Memory reallocation failed" << endl;
        exit(1);
    }
    ptr = new_ptr;

    //Inicializar realocacion del bloque de memoria
    for (int i = 5; i < 10; i++){
        new_ptr[i] = i * 2.5; 
    }
    cout << "Printing Values" << endl;

    //mostrar valores realesocados
    for (int i = 0; i < 10; i++){
        cout << new_ptr[i] << endl;
    }

    free(new_ptr); //liberar la memoria reservada
    return 0;

}