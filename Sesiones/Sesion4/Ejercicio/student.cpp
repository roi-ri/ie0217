#include "student.hpp"
#include <iostream>

using namespace std; 

Student::Student(double m) : marks(m){}

void calculateAverage(Student s1,  Student s2){
    double average = (s1.marks + s2.marks) / 2;

    cout << "Average marks: " << average << endl;
}
