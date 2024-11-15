#include "Circuito.hpp"
#include <iostream>
#include <stdexcept>  // Para las excepciones

// Función para calcular la resistencia total en serie
double Circuitos::resistenciaSerie(const std::vector<double>& resistencias) {
    if (resistencias.empty()) {
        throw std::invalid_argument("El vector de resistencias no puede estar vacío");
    }
    
    double resistenciaTotal = 0.0;
    for (double resistencia : resistencias) {
        if (resistencia < 0) {
            throw std::invalid_argument("Resistencia negativa no permitida");
        }
        resistenciaTotal += resistencia;
    }
    return resistenciaTotal;
}

// Función para calcular la inductancia total en serie
double Circuitos::inductanciaSerie(const std::vector<double>& inductancias) {
    if (inductancias.empty()) {
        throw std::invalid_argument("El vector de inductancias no puede estar vacío");
    }

    double inductanciaTotal = 0.0;
    for (double inductancia : inductancias) {
        if (inductancia < 0) {
            throw std::invalid_argument("Inductancia negativa no permitida");
        }
        inductanciaTotal += inductancia;
    }
    return inductanciaTotal;
}

// Función para calcular la capacitancia total en serie
double Circuitos::capacitanciaSerie(const std::vector<double>& capacitancias) {
    if (capacitancias.empty()) {
        throw std::invalid_argument("El vector de capacitancias no puede estar vacío");
    }

    double inversoTotal = 0.0;
    for (double capacitancia : capacitancias) {
        if (capacitancia <= 0) {
            throw std::invalid_argument("Capacitancia negativa o cero no permitida");
        }
        inversoTotal += 1.0 / capacitancia;
    }
    if (inversoTotal == 0) {
        throw std::invalid_argument("Suma de inversos de capacitancias no puede ser cero");
    }
    return 1.0 / inversoTotal;
}

// Función para calcular la resistencia total en paralelo
double Circuitos::resistenciaParalelo(const std::vector<double>& resistencias) {
    if (resistencias.empty()) {
        throw std::invalid_argument("El vector de resistencias no puede estar vacío");
    }

    double inversoTotal = 0.0;
    for (double resistencia : resistencias) {
        if (resistencia <= 0) {
            throw std::invalid_argument("Resistencia negativa o cero no permitida");
        }
        inversoTotal += 1.0 / resistencia;
    }
    if (inversoTotal == 0) {
        throw std::invalid_argument("Suma de inversos de resistencias no puede ser cero");
    }
    return 1.0 / inversoTotal;
}

// Función para calcular la inductancia total en paralelo
double Circuitos::inductanciaParalelo(const std::vector<double>& inductancias) {
    if (inductancias.empty()) {
        throw std::invalid_argument("El vector de inductancias no puede estar vacío");
    }

    double inversoTotal = 0.0;
    for (double inductancia : inductancias) {
        if (inductancia <= 0) {
            throw std::invalid_argument("Inductancia negativa o cero no permitida");
        }
        inversoTotal += 1.0 / inductancia;
    }
    if (inversoTotal == 0) {
        throw std::invalid_argument("Suma de inversos de inductancias no puede ser cero");
    }
    return 1.0 / inversoTotal;
}

// Función para calcular la capacitancia total en paralelo
double Circuitos::capacitanciaParalelo(const std::vector<double>& capacitancias) {
    if (capacitancias.empty()) {
        throw std::invalid_argument("El vector de capacitancias no puede estar vacío");
    }

    double total = 0.0;
    for (double capacitancia : capacitancias) {
        if (capacitancia < 0) {
            throw std::invalid_argument("Capacitancia negativa no permitida");
        }
        total += capacitancia;
    }
    return total;
}
