//Librerias de C
using namespace std;

//Archivos
#include "../include/VentaADomicilio.hpp"

VentaADomicilio::VentaADomicilio(int numero, float descuento, map<int, CantidadProducto*> cant_producto, Factura* factura, Etapa* etapa) : Venta (numero, descuento, cant_producto, factura) {
  this -> etapa = etapa;
}

VentaADomicilio::~VentaADomicilio() {
}

void VentaADomicilio::avanzarEtapaVenta() {
  Etapa *aux = etapa -> avanzarEtapa();
  delete etapa;
  etapa = aux;
}

void VentaADomicilio::cancelarVenta() {
  Etapa *aux = etapa -> cancelar();
  delete etapa;
  etapa = aux;
}
