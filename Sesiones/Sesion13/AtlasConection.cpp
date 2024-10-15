#include <iostream>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>


int main(){
    mongocxx::instance instance{};

    // Se utiliza para ingresar el conection string de atlas 
    mongocxx::client client{mongocxx::uri{"mongodb+srv://rodrisancheza1212:<db_password>@rodrie0217.un2nu.mongodb.net/?retryWrites=true&w=majority&appName=Rodrie0217"}};

    auto db = client["mydatabase"];
    auto collection = db["Users"];

    // Operaciones CRUD

    std::cout << "Conectado a MongoDB Atlas." << std::endl; 
    return 0; 
}
