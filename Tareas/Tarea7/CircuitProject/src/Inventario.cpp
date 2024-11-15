#include "Inventario.hpp"
#include <stdexcept>
#include <algorithm>

Componente::Componente(const std::string& nombre, const std::string& tipo, int cantidad, const std::string& descripcion)
    : nombre(nombre), tipo(tipo), cantidad(cantidad), descripcion(descripcion) {}

void Inventario::agregarComponente(const std::string& nombre, const std::string& tipo, int cantidad, const std::string& descripcion) {
    auto it = std::find_if(componentes.begin(), componentes.end(), [&](const Componente& c) {
        return c.nombre == nombre;
    });

    if (it != componentes.end()) {
        it->cantidad += cantidad;
    } else {
        componentes.push_back(Componente(nombre, tipo, cantidad, descripcion));
    }
}

void Inventario::reducirComponente(const std::string& nombre, int cantidad) {
    auto it = std::find_if(componentes.begin(), componentes.end(), [&](const Componente& c) {
        return c.nombre == nombre;
    });

    if (it == componentes.end() || it->cantidad < cantidad) {
        throw std::invalid_argument("No hay suficiente cantidad o el componente no existe.");
    }

    it->cantidad -= cantidad;
}

const Componente& Inventario::buscarComponente(const std::string& nombre) const {
    auto it = std::find_if(componentes.begin(), componentes.end(), [&](const Componente& c) {
        return c.nombre == nombre;
    });

    if (it == componentes.end()) {
        throw std::out_of_range("Componente no encontrado.");
    }

    return *it;
}

std::vector<Componente> Inventario::listarComponentes() const {
    return componentes;
}

void Inventario::eliminarComponente(const std::string& nombre) {
    auto it = std::remove_if(componentes.begin(), componentes.end(), [&](const Componente& c) {
        return c.nombre == nombre;
    });

    if (it != componentes.end()) {
        componentes.erase(it, componentes.end());
    } else {
        throw std::out_of_range("Componente no encontrado.");
    }
}

