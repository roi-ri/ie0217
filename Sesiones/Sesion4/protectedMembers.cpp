#include<iostream>
#include<string>
using namespace std; 

class Animal {
    private:
    string color;

    protected:
    string type;


    public:
    void run() {cout << "I can run --BASE!"<<endl;}
    void eat() {cout << "I can eat!"<<endl;}
    void sleep() {cout << "I can sleep!"<<endl;}
    void setColor(string clr) {color = clr;}
    //Se corrige el void de esta fuincion pq debe de tener un tipo string para que retorne lo solicitado (el color)
    string getColor(){ return color;}
};

class Dog : public Animal {
    public:
        void run() {cout << "I can run -- Derived!" << endl;}
        void setType(string tp) {type = tp;}
        void displayInfo(string c) {
            cout << "I am a " <<type << endl;

            cout << "My color is " << c << endl; 
            };

        void bark(){cout << "I can bark! Woff WOff!!" << endl;}

    
};


int main(){
    Dog dog1;
    dog1.run();
    dog1.eat();
    dog1.sleep();
    dog1.setColor("black");

    dog1.bark();
    dog1.setType("Doberman");
    dog1.displayInfo(dog1.getColor());
    return 0;
}