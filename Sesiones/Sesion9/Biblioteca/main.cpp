#include"biblioteca.hpp"

int main(){
    Biblioteca biblioteca; 

    biblioteca.agregarLibro("El Gran Gatsby ", "F. Scott Fitsgerald");
    biblioteca.agregarLibro("1984", "George Orwell");

    biblioteca.mostrarCatalogo();

    return 0; 
}