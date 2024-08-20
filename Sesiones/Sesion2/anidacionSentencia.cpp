#include <iostream>

using namespace std;

int main(){

    int num;

    cout << "Enter an integer: "; 
    cin >> num;

    // if exterior
    if (num != 0){

        // if interior
        if (num > 0){
            cout << "The number is positive" << endl;
        
        }
        else {
            cout << "The number is negative." << endl;
        }
    } 

    //else exterior
    else {

        cout << "THe number is 0 and it is neither positive nor negative." << endl;
    }

    cout << "This line is always printed." <<endl;

    return 0; 


}