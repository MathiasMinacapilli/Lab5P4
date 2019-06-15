//Librerias de C
using namespace std;

//Archivos
#include "../include/Mesa.hpp"

//Constructor
Mesa::Mesa(int numero, Mozo *miMozo, VentaLocal *ventaActual) {
  this -> numero = numero;
  this -> miMozo = miMozo;
  this -> ventaActual = ventaActual;
  this -> ventasPasadas.clear();
}

//Destructor
Mesa::~Mesa() {
}

//Getters y Setters
int Mesa::getNum() {
  return this -> numero;
}

Mozo* Mesa::getMiMozo() {
  return this -> miMozo;
}

void Mesa::setMozo(Mozo *m){
  this->miMozo = m;
}

void Mesa::setVentaActual(VentaLocal *v) {
  this -> ventaActual = v;
}

VentaLocal *Mesa::getVentaActual() {
  return this -> ventaActual;
}

void Mesa::agregarAVentasPasadas(VentaLocal *v) {
  ventasPasadas.insert(pair<int, VentaLocal*>(v -> getNumero(), v));
}

map<int, VentaLocal *> Mesa::getVentasPasadas() {
  return this -> ventasPasadas;
}

//Operaciones
bool Mesa::noTieneVentas() {
  return (ventaActual == nullptr);
}

bool Mesa::esDelMozo(int numMozo) {
    if(this->miMozo != nullptr)
        return ((this -> miMozo) -> getNumero() == numMozo);
    else
        throw new invalid_argument("No existen mozos asignados a mesas.");
}

void Mesa::terminarVenta() {
  ventasPasadas.insert(pair<int, VentaLocal*>((this -> ventaActual) -> getNumero(), this -> ventaActual));
  this -> ventaActual = nullptr;
}
