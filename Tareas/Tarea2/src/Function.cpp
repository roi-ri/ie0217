#include "Function.hpp"
#include "ProductoDigital.hpp"
#include "ProductoFisico.hpp"
#include "ClienteRegular.hpp"
#include "ClientePremium.hpp"
#include <iostream>

void Function::agregarProducto(){
    /**
     * @brief Agrega un producto a la tienda.
     *
     * Este método solicita al usuario el tipo de producto, nombre y precio. 
     * Según el tipo de producto, se solicita información adicional (ID o peso), 
     * se crea un objeto de tipo `ProductoDigital` o `ProductoFisico`, y se agrega a la tienda.
     */
    int tipoProducto;
    string nombre;
    double precio; 

    cout<<"Tipo de producto que va a ingresar: \n1. Digital.\n2. Fisico.\n";
    cin >> tipoProducto;

    cout << "Ingrese el nombre del producto: \n";
    cin >> nombre; 

    cout << "Ingrese el precio del producto: \n";
    cin >> precio; 


    if (tipoProducto == 1){
        string id; 
        cout <<"Ingrerse el ID del producto digital: \n";
        cin >> id; 
        Producto* nuevoProducto = new ProductoDigital(nombre, precio, id);
        tienda.agregarProducto(nuevoProducto);
    } else if (tipoProducto == 2){
        double peso; 
        cout << "Ingrese el peso del producto: \n";
        cin >> peso; 
        Producto* nuevoProducto = new ProductoFisico(nombre, precio, peso);
        tienda.agregarProducto(nuevoProducto);
    } 
}



void Function::registrarCliente(){
    /**
     * @brief Registra un nuevo cliente en la tienda.
     *
     * Este método solicita al usuario el tipo de cliente y el nombre. 
     * Según el tipo de cliente, se solicita información adicional (descuento en el caso de cliente Premium), 
     * se crea un objeto de tipo `ClienteRegular` o `ClientePremium`, y se agrega a la tienda.
     */
    int tipoCliente;
    string nombre; 

    cout<<"Tipo de cliente que desea registrar:\n1. Cliente Regular.\n2. Cliente Premium.\n";
    cin >> tipoCliente; 

    cout <<"Ingrese el nombre del cliente: \n";
    cin>> nombre; 


    if (tipoCliente == 1) {
        Cliente* nuevoCliente = new ClienteRegular(nombre);
        tienda.agregarCliente(nuevoCliente);

    }else if (tipoCliente == 2){
        double descuento; 
        cout << "Ingrese el porcentaje de descuento del cliente Premium: ";
        cin >> descuento; 
        Cliente* nuevoCliente = new ClientePremium(nombre, descuento);
        tienda.agregarCliente(nuevoCliente);
    }
}


void Function::agregarProductoAlCarrito(){
    /**
     * @brief Agrega un producto al carrito de un cliente.
     *
     * Este método solicita al usuario el nombre del cliente y el nombre del producto. 
     * Busca el producto en la tienda y el cliente en la lista de clientes. 
     * Si ambos se encuentran, el producto se añade al carrito del cliente.
     */
    string nombreCliente, nombreProducto; 


    cout << "Ingrese el nombre del cliente: ";
    cin >> nombreCliente;

    cout << "Ingrese el nombre del producto";
    cin >> nombreProducto;

    Producto* productoSeleccionado = nullptr;
    for(Producto* producto : tienda.productosDisponibles){
        if(producto->getNombre() == nombreProducto){
            productoSeleccionado = producto; 
            break;
        }
    }

    if(productoSeleccionado){
        for (Cliente* cliente: tienda.clientes){
            if (cliente->getNombre() == nombreCliente){
                cliente->agregarProducto(productoSeleccionado);
                cout << "Producto agregado al carrito correctamente.\n";
                return;
            }
        }
    }
    cout << "Cliente o producto no encontrados.\n";

}


void Function::procesarCompra(){
    /**
     * @brief Procesa la compra realizada por un cliente.
     *
     * Este método solicita el nombre del cliente, y llama al método `procesarCompra` 
     * de la clase `Tienda` para calcular el total a pagar y mostrarlo en la consola.
     */
    string nombreCliente; 
    
    cout << "Ingresar el nombre del cliente: ";
    cin >> nombreCliente;

    tienda.procesarCompra(nombreCliente);

}