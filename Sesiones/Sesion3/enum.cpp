// son como diccionarios

#include <iostream> 
 using namespace std;

enum seasons{ spring = 34, summer = 4, autum = 9, winter = 32};

enum week {sunday, Monday, Tuesday, Wednesday, Thursday, Friday};

enum suit {club = 0, diamonds = 10, hearts = 20, spades = 3} card;

 int main(){
    seasons s;

    s = summer; 
    cout << "Summer = " << s << endl; 

    week today; 
    today = Wednesday; 
    cout << "Day " << today+1 << endl; 

    card = club;
    cout << "Size of enum variable  " << sizeof(card) << "bytes. ";

    return 0;

}