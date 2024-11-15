#include <iostream>
#include <stdexcept>
#include "Inventario.hpp"
#include "Circuito.hpp"

void mostrarMenu() {
    std::cout << "\n=== Inventario de Componentes Electrónicos ===\n";
    std::cout << "1. Agregar Componente\n";
    std::cout << "2. Reducir Componente\n";
    std::cout << "3. Listar Componentes\n";
    std::cout << "4. Buscar Componente\n";
    std::cout << "5. Calcular Circuitos\n";
    std::cout << "6. Salir\n";
    std::cout << "Seleccione una opción: ";
}

void calcularCircuitos() {
    try {
        int tipo;
        std::cout << "Seleccione el tipo de cálculo:\n";
        std::cout << "1. Resistencias en Serie\n";
        std::cout << "2. Resistencias en Paralelo\n";
        std::cout << "3. Capacitancias en Serie\n";
        std::cout << "4. Capacitancias en Paralelo\n";
        std::cout << "5. Inductancias en Serie\n";
        std::cout << "6. Inductancias en Paralelo\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> tipo;

        if (tipo < 1 || tipo > 6) {
            throw std::invalid_argument("Opción no válida.");
        }

        int n;
        std::cout << "Ingrese la cantidad de valores: ";
        std::cin >> n;

        if (n <= 0) {
            throw std::invalid_argument("El número de valores debe ser mayor que cero.");
        }

        std::vector<double> valores(n);
        std::cout << "Ingrese los valores separados por espacio: ";
        for (int i = 0; i < n; ++i) {
            std::cin >> valores[i];
            if (valores[i] <= 0) {
                throw std::invalid_argument("Todos los valores deben ser positivos.");
            }
        }

        switch (tipo) {
            case 1:
                std::cout << "Resistencia en Serie: " << Circuitos::resistenciaSerie(valores) << " ohms\n";
                break;
            case 2:
                std::cout << "Resistencia en Paralelo: " << Circuitos::resistenciaParalelo(valores) << " ohms\n";
                break;
            case 3:
                std::cout << "Capacitancia en Serie: " << Circuitos::capacitanciaSerie(valores) << " F\n";
                break;
            case 4:
                std::cout << "Capacitancia en Paralelo: " << Circuitos::capacitanciaParalelo(valores) << " F\n";
                break;
            case 5:
                std::cout << "Inductancia en Serie: " << Circuitos::inductanciaSerie(valores) << " H\n";
                break;
            case 6:
                std::cout << "Inductancia en Paralelo: " << Circuitos::inductanciaParalelo(valores) << " H\n";
                break;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

int main() {
    Inventario inventario;

    int opcion;
    while (true) {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::string nombre, tipo, descripcion;
                int cantidad;
                std::cout << "Ingrese el nombre del componente: ";
                std::cin >> nombre;
                std::cout << "Ingrese el tipo del componente: ";
                std::cin >> tipo;
                std::cout << "Ingrese la cantidad: ";
                std::cin >> cantidad;
                std::cout << "Ingrese la descripción: ";
                std::cin >> descripcion;

                inventario.agregarComponente(nombre, tipo, cantidad, descripcion);
                std::cout << "Componente agregado.\n";
                break;
            }
            case 2: {
                std::string nombre;
                int cantidad;
                std::cout << "Ingrese el nombre del componente: ";
                std::cin >> nombre;
                std::cout << "Ingrese la cantidad a reducir: ";
                std::cin >> cantidad;

                try {
                    inventario.reducirComponente(nombre, cantidad);
                    std::cout << "Componente reducido.\n";
                } catch (const std::exception& e) {
                    std::cerr << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 3: {
                auto componentes = inventario.listarComponentes();
                std::cout << "Componentes en inventario:\n";
                for (const auto& c : componentes) {
                    std::cout << "Nombre: " << c.nombre << ", Tipo: " << c.tipo << ", Cantidad: " << c.cantidad << ", Descripción: " << c.descripcion << "\n";
                }
                break;
            }
            case 4: {
                std::string nombre;
                std::cout << "Ingrese el nombre del componente a buscar: ";
                std::cin >> nombre;

                try {
                    const Componente& c = inventario.buscarComponente(nombre);
                    std::cout << "Componente encontrado: " << c.nombre << ", " << c.tipo << ", " << c.cantidad << ", " << c.descripcion << "\n";
                } catch (const std::exception& e) {
                    std::cerr << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 5:
                calcularCircuitos();
                break;
            case 6:
                std::cout << "Saliendo...\n";
                return 0;
            default:
                std::cout << "Opción no válida.\n";
        }
    }
}
