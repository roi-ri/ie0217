#ifndef CIRCUITO_HPP
#define CIRCUITO_HPP

#include <vector>
#include <stdexcept>  // Para las excepciones

class Circuitos {
public:
    static double resistenciaSerie(const std::vector<double>& valores);
    static double resistenciaParalelo(const std::vector<double>& valores);
    static double capacitanciaSerie(const std::vector<double>& valores);
    static double capacitanciaParalelo(const std::vector<double>& valores);
    static double inductanciaSerie(const std::vector<double>& valores);
    static double inductanciaParalelo(const std::vector<double>& valores);
};

#endif // CIRCUITO_HPP
