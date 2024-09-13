#include <iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>


using namespace std; 
int main(){
    //inicializar un vector de tipo entero
    vector<int> numbers = {1,  100, 10, 70, 100};

    //print vector
    cout << "Los numeros son: ";
    for (auto &num : numbers){
        cout << num << ",";
    }

    //inicializar un set de tipo int
    set<int> numbers = {1,  100, 10, 70, 100};

    //print el set
    cout << "Los numeros son: ";
    for(auto &num: numbers){

        cout << num << ", ";
    }

    //inicializar el set desordenado de tipo entero
    unordered_set<int> numbers = {1,  100, 10, 70, 100};
    
    // Imprimir el set
    cout << "Los numeros son: ";
    for(auto &num: numbers){
        cout << num << ", ";
    }

    //inicializacion del mapa

    map<int, string> student;
    // usar [] para agregar elementos
    student[1] = "Jacqueline"; 
    student[2] = "Blake";

    //udando el metodo insert() para agregar elemenmtos
    student.insert(make_pair(3, "Denise"));
    student.insert(make_pair(4, "Blake"));


    //agregar elememtos con keys duplicadas

    student[5] = "Timothy";
    student[5] = "Aaron";


    //imprimri los estudiantes
    for(int i = 1; 1 <= student.size(); ++i){
        cout << "Studednt[" << i << "]: " << student[i] << endl;
    }

    return 0; 
}