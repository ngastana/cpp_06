#include "Serialize.hpp"

int main() {
    Data myData;
    myData.id = 123;
    myData.name = "ngastana";

    uintptr_t raw = Serialize::serialize(&myData);

    Data* recovered = Serialize::deserialize(raw);

    std::cout << "Puntero original : " << &myData << std::endl;
    std::cout << "uintptr raw : " << raw << std::endl;
    std::cout << "Puntero recuperado: " << recovered << std::endl;

    if (recovered == &myData) 
    {
        std::cout << "Contenido recuperado -> ID: " << recovered->id 
                  << ", Name: " << recovered->name << std::endl;
    } 
    else 
    {
        std::cout << "❌ Falla: El puntero no coincide." << std::endl;
    }

    return 0;
}
