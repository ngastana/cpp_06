#include "Base.hpp"

Base::~Base(){}

Base *generate(void){
    std::srand(std::time(0));
    int r = std::rand() % 3;
    if (r == 0) {
        std::cout << "[generate()] Created A" << std::endl;
        return new A;
    } else if (r == 1) {
        std::cout << "[generate()] Created B" << std::endl;
        return new B;
    } else {
        std::cout << "[generate()] Created C" << std::endl;
        return new C;
    }
}

void identify(Base* p){
    if (dynamic_cast<A*>(p)) //devuelve NULL si falla
        std::cout << "Identified by pointer: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Identified by pointer: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Identified by pointer: C" << std::endl;
    else
        std::cout << "Unknown type (pointer)" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p); //lanza una exceptción si falla
        std::cout << "Identified by reference: A" << std::endl;
        return;
    } catch (const std::exception&){}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Identified by reference: B" << std::endl;
        return;
    } catch (const std::exception&){}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Identified by reference: C" << std::endl;
        return;
    } catch (const std::exception&){}

    std::cout << "Unknown type (reference)" << std::endl;
}
