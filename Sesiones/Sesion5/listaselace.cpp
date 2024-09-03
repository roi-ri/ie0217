#include<iostream>
using namespace std;
//Creando un nodo
class Node{
    public : 
    int value;
    Node* next;
};

int main(){
    Node* head;
    Node* one = NULL;
    Node* two = NULL;
    Node* three = NULL;

    // asignas valores

    one->value=1;
    two->value=2;
    three->value=3;

    // conectando nodos
    one->next = two;
    two->next = three;
    three->next = NULL;

    //imprimir los valores linkeados
    head = one;
    while(head != NULL){
        cout << head->value;
        head = head->next;
    }
}

