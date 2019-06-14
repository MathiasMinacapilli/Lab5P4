//Archivos
#include "../include/Empleado.hpp"

Empleado::Empleado() {}

Empleado::Empleado(int numero, string nombre) {
    this->numero = numero;
    this->nombre = nombre;
}

int Empleado::getNumero() {
  return this -> numero;
}

string Empleado::getNombre() {
  return this -> nombre;
}

Empleado::~Empleado() {
}
