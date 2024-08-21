#include <iostream>

using namespace std;

int main(){
    char oper; 
    float num1, num2;
    cout << "Enter an operation (+, -, *, /):\n";
    cin >> oper;
    cout << "Enterr two numbers:\n";
    cin >> num1 >> num2;

    switch(oper){
        case '+':
            cout << num1 << "+" << num2 << "="<< num1 + num2;
            break; 
        case '-':
            cout << num1 << "-" << num2 << "=" << num1 - num2;
            break;
        case '*':
            cout << num1 << "*" << num2 << "=" << num1 * num2;
            break; 
        case '/': 
            cout << num1 << "/" << num2 << "='" << num1 / num2; 
        break;
        default:
        //operador no matchea las opciones preestablecidas
        cout << "Error! Te operator is not correct";
        break; 
    }

return 0;

}


