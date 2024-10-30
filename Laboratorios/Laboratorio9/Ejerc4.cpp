#include <iostream>
#include <thread>
#include<mutex> //incluyendo biblioteca para utilizar mutex

int contador = 0;
std::mutex mtx;

void incrementar() {
   std::lock_guard<std::mutex> lock(mtx);
    for (int i = 0; i < 100000; i++) {
        contador++;
    }
}

int main() {
    std::thread hilo1(incrementar);
    std::thread hilo2(incrementar);

    hilo1.join();
    hilo2.join();

    std::cout << "Valor final del contador: " << contador << std::endl;
    return 0;
}
