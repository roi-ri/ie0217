#include"Tienda.hpp"
#include"ProductoDigital.hpp"
#include"ProductoFisico.hpp"
#include"ClienteRegular.hpp"
#include"ClientePremium.hpp"
#include"Function.hpp"



/**
 * @brief Función principal que ejecuta el menú de la tienda virtual.
 *
 * Esta función muestra un menú interactivo que permite al usuario seleccionar entre 
 * agregar productos, registrar clientes, agregar productos al carrito, procesar compras 
 * y salir del programa. Dependiendo de la opción seleccionada, se llama al método 
 * correspondiente de la clase `Function`.
 * 
 * El programa continuará ejecutándose hasta que el usuario seleccione la opción de salir.
 * 
 * @return Código de estado de salida (0 para éxito).
 */
int main(){
    Function funcion; ///< Objeto de la clase `Function` para gestionar las operaciones de la tienda.
    int opcion = 0; ///< Variable para almacenar la opción seleccionada por el usuario.


    do{
        // Muestra el menú de opciones al usuario.
        cout<<"Bienvenido\nA continuacion se le presenta el menu de la tienda virtual.\n";
        cout<< "1. Agregar producto.\n";
        cout<< "2. Registrar cliente.\n";
        cout<< "3. Agregar producto al carrito.\n";
        cout<< "4. Procesar la compra.\n";
        cout<< "5. Salir.\n";

        // Lee la opción seleccionada por el usuario.
        cin >> opcion; 

        // Ejecuta la acción correspondiente según la opción seleccionada.
        switch (opcion){
            case 1: 
                funcion.agregarProducto(); ///< Llama al método para agregar un producto a la tienda.
                break;
            
            case 2:
                funcion.registrarCliente(); ///< Llama al método para registrar un nuevo cliente.
                break;
            case 3:
                funcion.agregarProductoAlCarrito(); ///< Llama al método para agregar un producto al carrito de un cliente.
                break;
            case 4:     
                funcion.procesarCompra(); ///< Llama al método para procesar la compra de un cliente.
                break;
            case 5: 
                cout << "Saliendo del programa...\n"; ///< Mensaje de salida cuando el usuario decide terminar el programa.
                break;
        } 
     }while (opcion != 5); ///< Continúa mostrando el menú hasta que el usuario seleccione la opción de salir.

      return 0; ///< Retorna 0 indicando que el programa terminó correctamente.
}












