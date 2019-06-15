//Librerias de C
using namespace std;

//Archivos
#include "../include/Mozo.hpp"

Mozo::Mozo(): Empleado() {}

Mozo::Mozo(int numero, string nombre) : Empleado(numero, nombre){}

Mozo::~Mozo() {}
