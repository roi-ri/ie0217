#include<iostream> 

using namespace std; 

//Class template con multiples parametros

template <class T, class U, class V = char>
class ClassTemplate{
    private:
        // Se definen tres variables cuyo tipo de dato es totalmente dependiente al que se vaya a dar a la hora de llamar el classTemplate
        T var1; 
        U var2;
        V var3;

    public: 
        ClassTemplate(T v1, U v2, V v3) : var1(v1), var2(v2), var3(v3){}
        //FUncion para imprimir las variables
        void printVar(){
            cout << "var1 = " << var1 << endl; 
            cout << "var2 = " << var2 << endl; 
            cout << "var3 = " << var3 << endl; 
        }
};

int main(){
    //crear un objeto con int, double y char
    ClassTemplate<int, double, char> obj1(7, 7.7, 'c');
    cout << "Valores del objeto 1" << endl;
    obj1.printVar();

    //Crear un objeto con tipos de datos int, char y bool 
    ClassTemplate<double, char, bool> obj2(8.8, 'a', false);
    cout << "\nLos valores de obj2 son: " << endl; 
    obj2.printVar();

    return 0; 
}
