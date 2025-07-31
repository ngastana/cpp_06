#include <iostream>
#include "Serialize.hpp"

int main() {
    // Creamos una instancia de Data
    Data myData;
    myData.id = 123;
    myData.name = "Prueba";

    // Serializamos el puntero a myData
    uintptr_t raw = Serialize::serialize(&myData);

    // Deserializamos el valor entero de vuelta a puntero
    Data* recovered = Serialize::deserialize(raw);

    // Mostramos resultados
    std::cout << "Puntero original : " << &myData << std::endl;
    std::cout << "Puntero recuperado: " << recovered << std::endl;

    // Comprobamos si apunta al mismo sitio
    if (recovered == &myData) {
        std::cout << "✅ Éxito: ¡El puntero deserializado coincide con el original!" << std::endl;
        std::cout << "Contenido recuperado -> ID: " << recovered->id 
                  << ", Name: " << recovered->name << std::endl;
    } else {
        std::cout << "❌ Falla: El puntero no coincide." << std::endl;
    }

    return 0;
}
