//Librerias de C
using namespace std;
#include <string>

//Archivos
#include "../include/FacturaDomicilio.hpp"

FacturaDomicilio::FacturaDomicilio(int codigo, DtFechaYHora fechaYHora, set<DtProductoCantidad> productos, float iva, float descuento, float precioSubTotal, float precioTotal, string nombreRepartidor, Transporte transporte) : Factura(codigo, fechaYHora, productosCantidad, iva, descuento, precioSubTotal, precioTotal) {
  this -> nombreRepartidor = nombreRepartidor;
  this -> transporte = transporte;
}

FacturaDomicilio::~FacturaDomicilio() {
}
