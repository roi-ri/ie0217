#ifndef TEXTPROCESSOR_HPP
#define TEXTPROCESSOR_HPP

#include <functional>


// Función processText:
// Esta función recibe un contenedor y una función de procesamiento.
// Itera sobre cada elemento del contenedor y aplica la función de procesamiento a cada uno.
// El contenedor puede ser cualquier tipo que soporte iteración, y la función puede ser un lambda
// o cualquier objeto que pueda ser llamado como función.
template <typename Container, typename Func>
void processText(Container& container, Func processFunc) {
    for (auto& element : container) {
        processFunc(element);
    }
}

#endif // TEXTPROCESSOR_HPP
