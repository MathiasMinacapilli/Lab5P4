//Archivos
#include "../include/Repartidor.hpp"

Repartidor::Repartidor(int numero, string nombre, Transporte medioTransporte) : Empleado(numero, nombre) {
  this -> medioTransporte = medioTransporte;
  this -> ventas.clear();
}

Repartidor::~Repartidor() {
}
Transporte Repartidor::getTransporte() {
    return this -> medioTransporte;
}

map<int, VentaADomicilio*> Repartidor::getVentas(){
	return this->ventas;
}