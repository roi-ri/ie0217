#ifndef CIRCUITO_HPP
#define CIRCUITO_HPP

#include <vector>
#include <stdexcept>  // Para las excepciones

class Circuitos {
public:
    // Funciones miembro para el cálculo de resistencias, inductancias y capacitancias
    double resistenciaSerie(const std::vector<double>& resistencias);
    double inductanciaSerie(const std::vector<double>& inductancias);
    double capacitanciaSerie(const std::vector<double>& capacitancias);

    double resistenciaParalelo(const std::vector<double>& resistencias);
    double inductanciaParalelo(const std::vector<double>& inductancias);
    double capacitanciaParalelo(const std::vector<double>& capacitancias);
};

#endif // CIRCUITO_HPP
