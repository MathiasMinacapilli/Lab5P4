//Librerias de C
using namespace std

//Archivos
#include "../include/Mozo.hpp"

Mozo::Mozo(int numero, string nombre, map<int, *Mesa> mesasMozo) {
    this -> numero = numero;
    this -> nombre = nombre;
    this -> mesasMozo = mesasMozo;
}

map<int, *Mesa> Mesa::getMesasMozo() {
  return this -> mesasMozo;
}

Mozo::~Mozo() {
}
