#include <gtest/gtest.h>
#include "../src/Inventario.hpp"
#include "../src/Circuito.hpp"

// Test para la clase Inventario
TEST(InventarioTest, AgregarYBuscarComponente) {
    Inventario inventario;
    inventario.agregarComponente("Resistencia", "Componente Electrónico", 10, "1k Ohms");
    
    // Verificar si el componente está en el inventario
    const Componente& resistencia = inventario.buscarComponente("Resistencia");
    EXPECT_EQ(resistencia.nombre, "Resistencia");
    EXPECT_EQ(resistencia.cantidad, 10);
}

TEST(InventarioTest, ReducirComponente) {
    Inventario inventario;
    inventario.agregarComponente("Capacitor", "Componente Electrónico", 10, "100uF");
    
    // Reducir cantidad de componente
    inventario.reducirComponente("Capacitor", 3);
    const Componente& capacitor = inventario.buscarComponente("Capacitor");
    EXPECT_EQ(capacitor.cantidad, 7);
}

TEST(InventarioTest, ReducirComponenteSinSuficienteCantidad) {
    Inventario inventario;
    inventario.agregarComponente("Capacitor", "Componente Electrónico", 10, "100uF");
    
    // Intentar reducir más cantidad de la disponible
    EXPECT_THROW(inventario.reducirComponente("Capacitor", 15), std::invalid_argument);
}

TEST(InventarioTest, AgregarComponenteDuplicado) {
    Inventario inventario;
    inventario.agregarComponente("Resistencia", "Componente Electrónico", 10, "1k Ohms");
    
    // Intentar agregar el mismo componente con una cantidad diferente
    inventario.agregarComponente("Resistencia", "Componente Electrónico", 5, "1k Ohms");
    
    const Componente& resistencia = inventario.buscarComponente("Resistencia");
    EXPECT_EQ(resistencia.cantidad, 15);  // La cantidad debe haberse sumado
}

TEST(InventarioTest, BuscarComponenteInexistente) {
    Inventario inventario;
    inventario.agregarComponente("Resistencia", "Componente Electrónico", 10, "1k Ohms");
    
    // Intentar buscar un componente que no existe
    EXPECT_THROW(inventario.buscarComponente("Capacitor"), std::out_of_range);
}

TEST(InventarioTest, AgregarComponenteConCantidadCero) {
    Inventario inventario;
    inventario.agregarComponente("Resistencia", "Componente Electrónico", 0, "1k Ohms");
    
    const Componente& resistencia = inventario.buscarComponente("Resistencia");
    EXPECT_EQ(resistencia.cantidad, 0);  // La cantidad debe ser cero
}

// Test para la clase Circuitos
TEST(CircuitosTest, ResistenciaSerieValida) {
    Circuitos circuito;
    std::vector<double> resistencias = {5.0, 10.0, 15.0};
    
    double resultado = circuito.resistenciaSerie(resistencias);
    EXPECT_EQ(resultado, 30.0);  // La resistencia total en serie es la suma de las resistencias
}

TEST(CircuitosTest, ResistenciaSerieInvalida) {
    Circuitos circuito;
    std::vector<double> resistencias = {-5.0, 10.0, 15.0};  // Valor negativo no válido
    
    EXPECT_THROW(circuito.resistenciaSerie(resistencias), std::invalid_argument);
}

TEST(CircuitosTest, ResistenciaParaleloValida) {
    Circuitos circuito;
    std::vector<double> resistencias = {5.0, 10.0, 15.0};
    
    double resultado = circuito.resistenciaParalelo(resistencias);
    double expected = 2.727272;  // Calculado como 1 / (1/5 + 1/10 + 1/15)
    EXPECT_NEAR(resultado, expected, 0.0001);  // Comparar con tolerancia
}

TEST(CircuitosTest, ResistenciaParaleloInvalida) {
    Circuitos circuito;
    std::vector<double> resistencias = {-5.0, 10.0, 15.0};  // Valor negativo no válido
    
    EXPECT_THROW(circuito.resistenciaParalelo(resistencias), std::invalid_argument);
}

TEST(CircuitosTest, CapacitanciaSerieValida) {
    Circuitos circuito;
    std::vector<double> capacitancias = {10.0, 20.0, 30.0};
    
    double resultado = circuito.capacitanciaSerie(capacitancias);
    double expected = 5.4545;  // Calculado como 1 / (1/10 + 1/20 + 1/30)
    EXPECT_NEAR(resultado, expected, 0.0001);
}

TEST(CircuitosTest, CapacitanciaSerieInvalida) {
    Circuitos circuito;
    std::vector<double> capacitancias = {-10.0, 20.0, 30.0};  // Valor negativo no válido
    
    EXPECT_THROW(circuito.capacitanciaSerie(capacitancias), std::invalid_argument);
}

// Test para circuitos con una sola resistencia en paralelo
TEST(CircuitosTest, ResistenciaParaleloUnica) {
    Circuitos circuito;
    std::vector<double> resistencias = {10.0};
    
    double resultado = circuito.resistenciaParalelo(resistencias);
    EXPECT_EQ(resultado, 10.0);  // Con una sola resistencia, el valor debe ser igual
}

// Probar capacitancia en paralelo con una sola capacitancia
TEST(CircuitosTest, CapacitanciaParaleloUnica) {
    Circuitos circuito;
    std::vector<double> capacitancias = {20.0};
    
    double resultado = circuito.capacitanciaParalelo(capacitancias);
    EXPECT_EQ(resultado, 20.0);  // Con una sola capacitancia, el valor debe ser igual
}

// Probar con vectores vacíos (comportamiento de error esperado)
TEST(CircuitosTest, ResistenciaSerieVacia) {
    Circuitos circuito;
    std::vector<double> resistencias = {};
    
    EXPECT_THROW(circuito.resistenciaSerie(resistencias), std::invalid_argument);
}

TEST(CircuitosTest, CapacitanciaSerieVacia) {
    Circuitos circuito;
    std::vector<double> capacitancias = {};
    
    EXPECT_THROW(circuito.capacitanciaSerie(capacitancias), std::invalid_argument);
}

TEST(CircuitosTest, ResistenciaParaleloValoresExtremos) {
    Circuitos circuito;
    
    // Resistencia muy pequeña (casi 0) y muy grande
    std::vector<double> resistencias = {0.0001, 1000000.0};
    
    double resultado = circuito.resistenciaParalelo(resistencias);
    double expected = 0.0001;  // La resistencia total debería ser muy pequeña
    EXPECT_NEAR(resultado, expected, 0.0001);
}

TEST(CircuitosTest, CapacitanciaParaleloValoresExtremos) {
    Circuitos circuito;
    
    // Capacitancia muy pequeña (casi 0) y muy grande
    std::vector<double> capacitancias = {0.0001, 1000000.0};
    
    double resultado = circuito.capacitanciaParalelo(capacitancias);
    double expected = 1000000.0001;  // La capacitancia total debería ser muy grande
    EXPECT_NEAR(resultado, expected, 0.0001);
}

TEST(CircuitosTest, ResistenciaSerieConResistenciaNegativa) {
    Circuitos circuito;
    std::vector<double> resistencias = {-5.0};  // Resistencia negativa no válida
    
    EXPECT_THROW(circuito.resistenciaSerie(resistencias), std::invalid_argument);
}

TEST(CircuitosTest, CapacitanciaSerieConCapacitanciaNegativa) {
    Circuitos circuito;
    std::vector<double> capacitancias = {-5.0};  // Capacitancia negativa no válida
    
    EXPECT_THROW(circuito.capacitanciaSerie(capacitancias), std::invalid_argument);
}
// Test para inductancia en serie
TEST(CircuitosTest, InductanciaSerieValida) {
    Circuitos circuito;
    std::vector<double> inductancias = {5.0, 10.0, 15.0};
    
    double resultado = circuito.inductanciaSerie(inductancias);
    EXPECT_EQ(resultado, 30.0);  // La inductancia total en serie es la suma de las inductancias
}

TEST(CircuitosTest, InductanciaSerieInvalida) {
    Circuitos circuito;
    std::vector<double> inductancias = {-5.0, 10.0, 15.0};  // Valor negativo no válido
    
    EXPECT_THROW(circuito.inductanciaSerie(inductancias), std::invalid_argument);
}

// Test para inductancia en paralelo
TEST(CircuitosTest, InductanciaParaleloValida) {
    Circuitos circuito;
    std::vector<double> inductancias = {5.0, 10.0, 15.0};
    
    double resultado = circuito.inductanciaParalelo(inductancias);
    double expected = 2.727272;  // Calculado como 1 / (1/5 + 1/10 + 1/15)
    EXPECT_NEAR(resultado, expected, 0.0001);  // Comparar con tolerancia
}

TEST(CircuitosTest, InductanciaParaleloInvalida) {
    Circuitos circuito;
    std::vector<double> inductancias = {-5.0, 10.0, 15.0};  // Valor negativo no válido
    
    EXPECT_THROW(circuito.inductanciaParalelo(inductancias), std::invalid_argument);
}

// Test para inductancia con una sola inductancia en serie
TEST(CircuitosTest, InductanciaSerieUnica) {
    Circuitos circuito;
    std::vector<double> inductancias = {10.0};
    
    double resultado = circuito.inductanciaSerie(inductancias);
    EXPECT_EQ(resultado, 10.0);  // Con una sola inductancia, el valor debe ser igual
}

// Test para inductancia con una sola inductancia en paralelo
TEST(CircuitosTest, InductanciaParaleloUnica) {
    Circuitos circuito;
    std::vector<double> inductancias = {20.0};
    
    double resultado = circuito.inductanciaParalelo(inductancias);
    EXPECT_EQ(resultado, 20.0);  // Con una sola inductancia, el valor debe ser igual
}

// Test con vectores vacíos (comportamiento de error esperado)
TEST(CircuitosTest, InductanciaSerieVacia) {
    Circuitos circuito;
    std::vector<double> inductancias = {};
    
    EXPECT_THROW(circuito.inductanciaSerie(inductancias), std::invalid_argument);
}

TEST(CircuitosTest, InductanciaParaleloVacia) {
    Circuitos circuito;
    std::vector<double> inductancias = {};
    
    EXPECT_THROW(circuito.inductanciaParalelo(inductancias), std::invalid_argument);
}

// Test de inductancia en paralelo con valores extremos
TEST(CircuitosTest, InductanciaParaleloValoresExtremos) {
    Circuitos circuito;
    
    // Inductancia muy pequeña (casi 0) y muy grande
    std::vector<double> inductancias = {0.0001, 1000000.0};
    
    double resultado = circuito.inductanciaParalelo(inductancias);
    double expected = 0.0001;  // La inductancia total debería ser muy pequeña
    EXPECT_NEAR(resultado, expected, 0.0001);
}

// Test de inductancia en serie con valores extremos
TEST(CircuitosTest, InductanciaSerieValoresExtremos) {
    Circuitos circuito;
    
    // Inductancia muy pequeña (casi 0) y muy grande
    std::vector<double> inductancias = {0.0001, 1000000.0};
    
    double resultado = circuito.inductanciaSerie(inductancias);
    double expected = 1000000.0001;  // La inductancia total debería ser muy grande
    EXPECT_NEAR(resultado, expected, 0.0001);
}

// Test de inductancia en serie con inductancia negativa
TEST(CircuitosTest, InductanciaSerieConInductanciaNegativa) {
    Circuitos circuito;
    std::vector<double> inductancias = {-5.0};  // Inductancia negativa no válida
    
    EXPECT_THROW(circuito.inductanciaSerie(inductancias), std::invalid_argument);
}

// Test de inductancia en paralelo con inductancia negativa
TEST(CircuitosTest, InductanciaParaleloConInductanciaNegativa) {
    Circuitos circuito;
    std::vector<double> inductancias = {-5.0};  // Inductancia negativa no válida
    
    EXPECT_THROW(circuito.inductanciaParalelo(inductancias), std::invalid_argument);
}