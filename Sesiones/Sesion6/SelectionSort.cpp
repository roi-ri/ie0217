#include<iostream> 

using namespace std; 

//Funcion para intrercambiar la posicion de dos elelementos

void swap(int *a, int *b){
    int temp = *a;
    *a = *b; 
    *b = temp; 
}

//Funcion para imprimir el array

void printArray(int array[], int size){
    for (int i = 0; i < size; i++){
        cout << array[i] << " " ;

    }

    cout << endl; 
}

void selectionSort(int array[], int size){
    for (int step = 0; step < size -1; step++){
        int min_idx  = step;
        for (int i = step + 1; i < size; i++){
            //acomodar en orden descendente, cambiar > a < en esta linea
            //Selecciona el elemento mas pequeno del arreglo
            if(array[i] < array[min_idx]){
                min_idx = i;
            }
        }
        //Poner el minimo en la posicion correcta
        swap(&array[min_idx], &array[step]);
    }
}

int main(){
    int data[] = {20, 12, 10, 15, 2};
    int size = sizeof(data) / sizeof(data[0]);
    selectionSort(data, size);
    cout << "Arreglo ordenado en orden ascendente:\n";
    printArray(data, size);
}
