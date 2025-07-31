#include "Base.hpp"
#include <iostream>

// Prototipos
Base* generate();
void identify(Base* p);
void identify(Base& p);

int main() {
    Base* ptr = generate();  // Crea una instancia aleatoria
    identify(ptr);           // Identifica usando puntero
    identify(*ptr);          // Identifica usando referencia

    delete ptr;              // No olvides liberar memoria
    return 0;
}
