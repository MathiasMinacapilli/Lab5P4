//Librerias de C
using namespace std;

//Archivos
#include "../include/Mesa.hpp"

//Constructor
Mesa::Mesa(int numero, Mozo *miMozo, VentaLocal *ventaActual, map<int, VentaLocal *> ventasPasadas) {
  this -> numero = numero;
  this -> miMozo = miMozo;
  this -> ventaActual = ventaActual;
  this -> ventasPasadas = ventasPasadas;
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

void Mesa::setVentaActual(VentaLocal *v) {
  this -> ventaActual = v;
}

Venta Mesa::*getVentaActual() {
  return this -> ventaActual;
}

void Mesa::agregarAVentasPasadas(VentaLocal *v) {
  ventasPasadas.insert(pair<int, VentaLocal>(v -> getNumero(), v));
}

map<int, VentaLocal *> getVentasPasadas() {
  return this -> ventasPasadas;
}

//Operaciones
bool Mesa::noTieneVentas() {
  return (ventaActual == nullptr);
}

bool Mesa::esDelMozo(int numMozo) {
  return ((this -> miMozo).getNumero() == numMozo);
}

void Mesa::terminarVenta() {
  ventasPasadas.insert(pair<int, VentaLocal>((this -> ventaActual).getNum(), this -> ventaActual));
  this -> ventaActual = nullptr;
}
