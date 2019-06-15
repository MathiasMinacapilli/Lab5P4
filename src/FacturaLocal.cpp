//Librerias de C
#include <string>
using namespace std;

//Archivos
#include "../include/FacturaLocal.hpp"

FacturaLocal::FacturaLocal(int codigo, DtFechaYHora fechaYHora, map<int, DtProductoCantidad> productosCantidad, float iva, float descuento, float precioSubTotal, float precioTotal, string nombreMozo) : Factura(codigo, fechaYHora, productosCantidad, iva, descuento, precioSubTotal, precioTotal) {
  this -> nombreMozo = nombreMozo;
}

string FacturaLocal::getNombreMozo() {
  return this->nombreMozo;
}

FacturaLocal::~FacturaLocal() {
}
