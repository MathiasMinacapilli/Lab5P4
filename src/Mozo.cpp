//Librerias de C
using namespace std;

//Archivos
#include "../include/Mozo.hpp"

Mozo::Mozo(): Empleado() {}

Mozo::Mozo(int numero, string nombre) : Empleado(numero, nombre){}

/* Agrega la mesa a la coleccion de mesas del mozo */
void Mozo::agregarMesaAColleccion(Mesa* mesa) {
    this->mesas_mozo[mesa->getNum()] = mesa;
}

Mozo::~Mozo() {}
