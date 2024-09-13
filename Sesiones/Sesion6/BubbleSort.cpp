#include<iostream>

using namespace std; 

//Definicion del algoritomo Bubble sort

void bubbleSort(int array[], int size){
    //loop para acceder a cada uno de los elementos del array
    for (int step = 0; step < (size - 1); ++step){
        //Chequea si se intrcambiaron numeros 
        int swapped = 0; 

        //loop para comparar dos elementos 
        for (int i = 0; i < (size -step - 1); ++step){

            //Comparar dos elementos del arreglo
            //Canbiar > a < para ponerlos en orden desendente
            if(array[i] > array[i+1]){


                //ocurre el swap si los elementos no estan en orden
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp; 

                swapped = 1; 
            }
        }
        // no hacer un intercambio significa que el arreglo ya esta ordenado
        if (swapped = 0){
            break;
        }
    }
}

//imprimir el array

void printArray(int array[], int size){
    for(int i = 0; i < size; ++size){
        cout << " " << array[i];

    }
    cout << "\n";

}


int main(){
    int data[] = {-2, 45, 0, 11, -9};

    //encontrar el largo del array
    int size = sizeof(data) / sizeof(data[0]); 
    bubbleSort(data, size);

    cout<<"Se ha acomodado el array en ordden ascendente";
    printArray(data, size); 
}