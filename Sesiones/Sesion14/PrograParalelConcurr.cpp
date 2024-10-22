#include <iostream> 
#include <thread>
#include<vector>
#include<queue> 
#include<mutex>
#include<condition_variable>
#include<semaphore>
#include<chrono> 


using namespace std; 

constexpr int BUFFER_SIZE = 10; 
queue<int> buffer;
mutex mtx; 
condition_variable cv_producer, cv_consumer; 
counting_semaphore<BUFFER_SIZE> empty_slots(BUFFER_SIZE); // INIICA con buffer-size
counting_semaphore<BUFFER_SIZE> full_slots(0); //inicia con 0

void producer(int id, int num_tasks){
    for (int i = 0; i < num_tasks; i++){
        //produce un item 
        int item = id * 100 + 1;
        empty_slots.acquire(); // Va a ddecrementar el contador de items vacios

        //critical section 
        {
            lock_guard<mutex> lock(mtx);
            buffer.push(item);
            cout << "Producer " << id << "produced item" << item << endl;

        }

        full_slots.release(); //incrementa el contados como si tuviera slots llenos
        cv_consumer.notify_one(); //Notifica al consumidor 

    }


   
}

void consumer(int id) {
    while (true){
        full_slots.acquire(); //Decrementa el contados de slots llenos
        unique_lock<mutex> lock(mtx); 

        //espera hasta que haya un item en el buffer
        cv_consumer.wait(lock, [] {return !buffer.empty();});


        int item = buffer.front(); 
        buffer.pop(); 
        cout<< "Consumer" << id << "consumed item" << item << endl; 


        lock.unlock(); 
        empty_slots.release(); // Incrementa el contador de slots vacios
        cv_producer.notify_one(); // Notifica a un productor

        //Simula procesado del item 
        this_thread::sleep_for(chrono::milliseconds(100)); 

    }
}

int main(){
    const int num_producers = 2; 
    const int num_consumers = 3; 
    const int num_task_per_producer = 10; 


    vector<thread> producers, consumers; 

    //Crea producer trheads
    for (int i = 0; i < num_producers; i ++ ){
        producers.emplace_back(producer, i, num_task_per_producer);
    }
    //crea un consumer
    for(int i = 0; i < num_consumers; i++){
        consumers.emplace_back(consumer, i); 
    }
    //Unir producer threads
    for (auto& producer_thread : producers){
        producer_thread.join(); 
    }
    //Permite a los consumers finalizar el procesado
    this_thread::sleep_for(chrono::seconds(2));

    //identicamente, se puede senalar a los consumers para que paren, pero por simplicidad solo se sale del programa
    cout << "Al producers have finished. " << endl; 
    return 0; 
}
