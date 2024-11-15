#ifndef INVENTARIO_HPP
#define INVENTARIO_HPP

#include <string>
#include <vector>

class Componente {
public:
    std::string nombre;
    std::string tipo;
    int cantidad;
    std::string descripcion;

    Componente(const std::string& nombre, const std::string& tipo, int cantidad, const std::string& descripcion);
};

class Inventario {
private:
    std::vector<Componente> componentes;

public:
    void agregarComponente(const std::string& nombre, const std::string& tipo, int cantidad, const std::string& descripcion);
    void reducirComponente(const std::string& nombre, int cantidad);
    const Componente& buscarComponente(const std::string& nombre) const;
    std::vector<Componente> listarComponentes() const;
    void eliminarComponente(const std::string& nombre);
};

#endif // INVENTARIO_HPP
