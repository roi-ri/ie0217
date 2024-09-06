#include"Tienda.hpp" 


void Tienda::agregarProducto(Producto* producto){
    /**
     * @brief Agrega un producto a la tienda.
     * @param producto Puntero al objeto `Producto` que se desea agregar.
     *
     * Este método añade el puntero al objeto `Producto` al vector `productosDisponibles`.
     */
    productosDisponibles.push_back(producto);
}

void Tienda::agregarCliente(Cliente* cliente){
     /**
     * @brief Agrega un cliente a la tienda.
     * @param cliente Puntero al objeto `Cliente` que se desea agregar.
     *
     * Este método añade el puntero al objeto `Cliente` al vector `clientes`.
     */
    clientes.push_back(cliente);
}

void Tienda::procesarCompra(const string &nombreCliente){
    /**
     * @brief Procesa la compra realizada por un cliente.
     * @param nombreCliente Nombre del cliente que realiza la compra.
     *
     * Este método busca al cliente en el vector `clientes` utilizando el nombre proporcionado.
     * Si el cliente es encontrado, calcula el total a pagar aplicando un descuento y lo muestra en la consola.
     */
    for (const auto& cliente : clientes) {
        if (cliente -> getNombre() == nombreCliente){
            double total = cliente->aplicarDescuento();
            cout<<"Total a pagar: " <<  total << endl;
            break; 
        }
    }
}