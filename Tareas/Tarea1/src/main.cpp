#include "conversiones.hpp"

using namespace std;

int main(){
    int option;
    converDatos data;
    do{
        showMenu();
        cout <<"Elija una opción: " << endl;
        cin >> option;

        switch(option){
            case CONVERTIR_LONGITUD:
                convLongitud(data);
                break;
            case CONVERTIR_PESO:
                convPeso(data);
                break;
            case CONVERTIR_TEMPERATURA:
                convTemperatura(data); 
                break;
        }

    } while(option != SALIR);

    return 0;
} 

