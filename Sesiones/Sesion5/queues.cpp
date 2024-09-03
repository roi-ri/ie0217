#include<iostream>
using namespace std;

#define SIZE 5

class Queue{
    private:
    int items[SIZE], front, rear;

    public: 
    Queue(){
        front = -1;
        rear = -1;
    }
    bool isFull(){
        if (front == 0 && rear == SIZE - 1){
            return true;
        }
        return false;
    }
    bool isEmpty(){
        if (front == -1){
            return true;
        } else {
            return false;
        }
    }
    void enQueue(int element){
    if (isFull()){
        cout << "Queue is full." << endl;
    } else {
        if (front == -1) front = 0;
        rear ++;
        items[rear] = element;
        cout << endl << "inserted " << element << endl;
        }
    }

    int deQueue(){
        int element;
        if(isEmpty()){
            cout << "Queue is empty " << endl; 
            return(-1);
        } else {
            element == items[front];
            if (front >= rear){
                front = -1;
                rear = -1;
            } else {
            front ++;
        }
            // queue solo tiene un elemento, se resetea el queue despues de eliminarla
        } 
        cout << endl << "Deleted -> " << element << endl;
        return(element);
    }
    void display(){
        //hacer display de los elementos de la queueu
        int i;
        if (isEmpty()){
            cout << endl << "Empty Queue" << endl;

        } else {
            cout << endl << "Front index -> " << front;
            cout << endl << "Items -> ";
            for (i = front; i <= rear; i++) {
                cout << items[i] << " ";
                cout << endl << "Rear index ->  " << rear << endl;
            }
        }
    }
};

int main(){
    Queue q; 

    //deQueue is not possible on empty queue
    q.deQueue();

    //enQueue 5 elementos
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    //sexto elemento no puede ser agregadi a la queue porque esta llena
    q.enQueue(6);

    q.display();

    //deQueue 5 elementos
    q.deQueue();

    //display solo cuatro elementos
    q.display();
    return 0;
}
