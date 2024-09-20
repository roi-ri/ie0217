#include<iostream> 
#include<regex> 

using namespace std; 
int main(){
    //Se le pide al compilador que interprete de manera automatica que tipo de dato es esto
    auto const regex = std::regex("(my|your) regex"); //Esta es mi expresion regular


    //Se crea un texto que contiene el conjuinto "my regex"
    auto const myText = std::string("A piece of text that contains my regex");
    //Le paso myText y regex con la expresion regular que quiero comparar, retorna verdadero o falso
    bool const myTextContainsRegex = std::regex_search(myText, regex);



    auto const yourText = std::string("A piece of text that contains your regex");
    //Le paso yourText y regex con la expresion regular que quiero comparar, retorna verdadero o falso
    bool const yourTextContainsRegex = std::regex_search(yourText, regex);



    auto const theirText = std::string("A piece of text that contains their regex");

    //Le paso theirText y regex con la expresion regular que quiero comparar, retorna verdadero o falso
    bool const theirTextContainsRegex = std::regex_search(theirText, regex);

    cout << std::boolalpha
         << myTextContainsRegex << "\n"
         << yourTextContainsRegex << "\n" 
         << theirTextContainsRegex << endl; 
    
}