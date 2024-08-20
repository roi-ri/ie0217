#include <iostream>
#include <cstring>

using namespace std; 


struct Books {

    char title[50];
    char author[50];
    char subject[50];
    int book_id;


};

int main(){
    //declarar libro 1 y libro 2 del tipo Book
    struct Books Book1;
    struct Books Book2; 

    //especificaciones del libro 1

    strcpy(Book1.title, "Learn C++ Programming");
    strcpy(Book1.author, "Chand Miyan");
    strcpy(Book1.subject, "C++ Programming");
    Book1.book_id = 6495407;

    //especificaciones del libro 2


    strcpy(Book2.title, "Telecom Billing");
    strcpy(Book2.author, "Yakit Singha");
    strcpy(Book2.subject, "Telecom");
    Book2.book_id = 6495700;


    //mostrar datos del libro 1
    cout << "Book 1 title: " << Book1.title << endl;
    cout << "Book 1 author: " << Book1.author << endl;
    cout << "Book 1 subject: " << Book1.subject << endl;
    cout << "Book 1 book_id: " << Book1.book_id << endl;

    //mostrar datos del libro 2
    cout << "Book 2 title: " << Book2.title << endl;
    cout << "Book 2 author: " << Book2.author << endl;
    cout << "Book 2 subject: " << Book2.subject << endl;
    cout << "Book 2 book_id: " << Book2.book_id << endl;

    return 0;



}


