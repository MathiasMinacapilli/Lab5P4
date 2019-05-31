//Librerias de C
using namespace std;

//Archivos
#include "../include/Repartidor.hpp"

Repartidor::Repartidor(int numero, string nombre, Transporte medioTransporte) : Empleado(numero, nombre) {
  this -> medioTransporte = medioTransporte;
}

Repartidor::~Repartidor() {
}
