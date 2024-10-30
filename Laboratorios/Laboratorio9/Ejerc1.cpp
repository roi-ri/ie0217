#include <iostream>
#include <vector>
#include <algorithm>

double calcularMedia(const std::vector<int>& numeros) {
    double suma = 0;
    for (int i = 0; i < numeros.size(); i++) {
        suma += numeros[i];
    }
    
    return suma/numeros.size(); 
}

double calcularMediana(std::vector<int> numeros) {
    std::sort(numeros.begin(), numeros.end());

    int tam = numeros.size();
    if (tam % 2 == 0) {
        return (numeros[tam/2 - 1] + numeros[tam/2]) / 2.0;
    } else {
        return numeros[tam/2];
    }
}

int main() {
    std::vector<int> numeros = {1, 4, 8, 110, 33, 49};

    double media = calcularMedia(numeros);
    double mediana = calcularMediana(numeros);

    std::cout << "Media: " << media << std::endl;
    std::cout << "Mediana: " << mediana << std::endl;

    return 0;
}



