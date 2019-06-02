//Librerias de C
using namespace std;
#include <map>
#include <set>

//Archivos
#include "../include/ControladorVenta.hpp"

ControladorVenta::ControladorVenta() {
}

ControladorVenta ControladorVenta::getInstance() {
  if (instance == nullptr)
    instance = new ControladorVenta;
  return instance;
}

void ControladorVenta::agregarProductoAVenta() {
  
}
void ControladorVenta::cancelarEliminarProductoDeVenta();
void ControladorVenta::cancelarProductoAVenta();
Venta ControladorVenta::crearVenta();
void ControladorVenta::eliminarProductoDeVenta();
bool ControladorVenta::estaEnVentaSinFacturar(Producto p);
DtFactura ControladorVenta::generarFactura();
map<int, DtFactura> ControladorVenta::getFacturasFecha();
set<DtActualizacion> ControladorVenta::getListadoActualizaciones();
map<int, DtProducto> ControladorVenta::getProductosVenta (int numMesa);
float ControladorVenta::getTotalFacturadoFecha();
void ControladorVenta::ingresarNumeroMesa(int numero);
void ControladorVenta::ingresarPorcentajeDescuento(float descuento);
map<int, DtProducto> ControladorVenta::obtenerProductosDisponibles();
void ControladorVenta::seleccionarProdYCant(DtProductoCantidad producto_cantidad);
