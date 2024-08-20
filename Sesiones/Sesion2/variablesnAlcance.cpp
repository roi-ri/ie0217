#include <iostream> 

using namespace std; 


void test(){

    //var is a static variable
    static int var = 0; 

    ++var;

    cout << var << endl; 
}


int main(){

    //le asigna el valor por defecto que va adoptando el elemento var 

    test();
    test();

    return 0;
}


// ejemplo 2

int cuenta; 
extern void write_extern();

main(){
    cuenta = 5; 
    write_extern();
}


extern int count; 

void write_extern(void){
    std::cout << "count is " << cuenta << std::endl;
}


