//Librerias de C
#include <string>
#include <set>
using namespace std;

//Archivos
#include "../include/FacturaDomicilio.hpp"

FacturaDomicilio::FacturaDomicilio(int codigo, DtFechaYHora fechaYHora, map<int, DtProductoCantidad> productosCantidad, float iva, float descuento, float precioSubTotal, float precioTotal, string nombreRepartidor, Transporte transporte) : Factura(codigo, fechaYHora, productosCantidad, iva, descuento, precioSubTotal, precioTotal) {
  this -> nombreRepartidor = nombreRepartidor;
  this -> transporte = transporte;
}

FacturaDomicilio::~FacturaDomicilio() {
}
