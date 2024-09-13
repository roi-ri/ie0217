#include<iostream> 

using namespace std; 

//Funcion para intertcambiar dos elementos 
void swap(int &a, int &b){
    int temp = a; 
    a = b;
    b = temp;
}

//Funcion para partir el arreglo

int partition(int arr[], int low, int high){
    int pivot = arr[high]; // Escoge el ultimo elemento como un pivote 
    int i = low -1; // Indice del elemento mas pequeno

    for(int j = low; j < high; j++){
        // Si el elemento actual es menor o igual al pivote
        if (arr[j] <= pivot){
            i++; 
            swap(arr[i], arr[j]); // Intercambia los elelemtos con esos indices

        }  
    }
    swap(arr[i + 1], arr[high]); // Mover el pivote a su posicion correcta
    return (i + 1); 

}


// Función principal de QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Obtener el índice de partición
        quickSort(arr, low, pi - 1);  // Ordenar los elementos antes del pivote
        quickSort(arr, pi + 1, high);  // Ordenar los elementos después del pivote
    }
}

//Funcino para imprimir el arreglo

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " "; 
    }
    cout << endl; 
}

int main(){
    int arr[] = {30, 40, 33, 10, 69, 43};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "Arreglo original: ";
    printArray(arr, size); 

    cout << "Arreglo ordenado: ";
    quickSort(arr, 0, size -1);
    printArray(arr, size); 
    
}