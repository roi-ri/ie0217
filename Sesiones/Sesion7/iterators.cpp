#include <iostream>
#include <vector>
#include <forward_list>
using namespace std;

int main() {
    // Crea un vector como string
    vector<string> languages = {"Python", "C++", "Java"};
    
    // Crea un iterador para el vecetor string
    vector<string>::iterator itr;

    // Itera por todos los elementos del vector string
    for (itr = languages.begin(); itr != languages.end(); itr++) {
        cout << *itr << " ";  // print cada elemento del vector
    }


    // Crear una forward_list de enteros
    forward_list<int> nums{1, 2, 3, 4};

    // Inicializar un iterador al inicio de la forward_list
    forward_list<int>::iterator itr = nums.begin();

    // Iterar a través de la lista
    while (itr != nums.end()) {
        // Acceder al valor en la posición del iterador y guardarlo en original_value
        int original_value = *itr;

        // Duplicar el valor en la posición actual del iterador
        *itr = original_value * 2;

        // Mover el iterador a la siguiente posición
        itr++;
    }

    // Mostrar los contenidos de la lista
    for (int num : nums) {
        cout << num << " ";  // Imprimir los elementos actualizados
    }


    //Crear un vector
    vector<int> vec{1 ,2 ,3 ,4};

    //Crear iteradores del primer y ultimo elelemtno de los vectores

    vector<int>::iterator itr_first = vec.begin();
    vector<int>::iterator itr_last = vec.end() -1;

    //Mostrar el vector de elementos

    cout << "Primer elemento: " << *itr_first << endl; 
    cout << "Segundo elemento: " << itr_last[1] << endl; 

    cout << "Segundo ultimo elelemto" << *(itr_last-1) << endl; 
    cout << "Ultimo elemento: " << *(itr_last) << endl; 




    return 0;
}
