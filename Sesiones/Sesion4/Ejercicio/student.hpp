#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>

using namespace std;

class Student{

    public: 
        double marks;   
        Student(double m);

}; 

// Declaración funcion calculo promedio
void calculateAverage(Student s1, Student s2);

#endif //STUDENT_H