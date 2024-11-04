#include <gtest/gtest.h>
#include "calculator.h" 



//Definicion de la testFixture 
class CalculatorTest : public::testing::Test{
    protected:
        Calculator calc; 

        void SetUp() override {
            //Esta configuracion comin se necesita antes de cada test

        }

        void TearDown() override{
            //Limpieza común que se necesita antes de cada test
        }

};
//Funcion para el metodo Add usando Test Fixture
TEST_F(CalculatorTest, AddTest){
    EXPECT_EQ(calc.Add(1, 1), 2);
    EXPECT_EQ(calc.Add(-1, 1), 0);
    EXPECT_EQ(calc.Add(-1, -1), -2);
}


TEST_F(CalculatorTest, SubtractTest){
    EXPECT_EQ(calc.Subtract(2,1), 1 );
    EXPECT_EQ(calc.Subtract(-1,1), -2 );
    EXPECT_EQ(calc.Subtract(-1,-1), 0 );
}

// Funcion Priincipal para ejecutar los tests
int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}