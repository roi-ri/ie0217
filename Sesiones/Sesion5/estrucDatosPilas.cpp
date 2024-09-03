#include <iostream>
#include <stdlib.h>
using namespace std;

#define MAX 10

int size = 0;

// Creando stack
struct Stack {
    int items[MAX];
    int top;
};

typedef struct Stack st;

void createEmptyStack(st *s) {
    s->top = -1;
}

// Revisar si el stack está lleno
int isfull(st *s) {
    return s->top == MAX - 1;
}

// Revisar si el stack está vacío
int isempty(st *s) {
    return s->top == -1;
}

// Agregar elementos al stack
void push(st *s, int newitem) {
    if (isfull(s)) {
        cout << "Stack full" << endl;
    } else {
        s->items[++(s->top)] = newitem;
        size++;
    }
}

// Remover elemento del stack
void pop(st *s) {
    if (isempty(s)) {
        cout << "Stack empty" << endl;
    } else {
        cout << "Popped item is " << s->items[(s->top)--] << endl;
        size--;
    }
}

// Imprimir elementos del stack
void printStack(st *s) {
    cout << "Stack: ";
    for (int i = 0; i <= s->top; i++) {
        cout << s->items[i] << " ";
    }
    cout << endl;
}

// main
int main() {
    st *s = (st *)malloc(sizeof(st));
    createEmptyStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    printStack(s);

    pop(s);

    cout << "\nAfter popping out\n";
    printStack(s);

    // Liberar memoria
    free(s);

    return 0;
}
