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

//Baja Producto - eliminarProducto - ControladorProducto
bool ControladorVenta::estaEnVentaSinFacturar(Producto p) {
  map<int, Venta*>::iterator it;
  bool encontre_producto = false;
  bool existe_factura;
  for(it = ventas.begin(); ((it != ventas.end()) && (!encontre_producto)); ++it) {
    existe_factura = (it -> second) -> estaFacturada();
    if (!existe_factura)
      encontre_producto = (it->second) -> buscarProducto(p);
  }
  return encontre_producto;
}

//Iniciar Venta en Mesas - iniciarVenta - ControladorMesa
//FALTA LO DEL NUMEROOOOO
//ACAA
//ACAA
//ACAA
Venta ControladorVenta::crearVenta() {
  ve = new VentaLocal(/*numero random o contador de ventas*/, 0, NULL);
  ventas.insert(pair<int, Venta>(ve -> getCodigo(), ve));
  return ve;
}

//Agregar Producto a una Venta
void ControladorVenta::ingresarNumeroMesa(int numero) {
  numero_mesa = numero;
}

map<int, DtProducto> ControladorVenta::obtenerProductosDisponibles() {
  ControladorProducto *cont_prod;
  cont_prod = ControladorProducto::getInstance();
  map<int, DtProducto> dtprods = 	cont_prod -> getProductosDisponibles();
  return dtprods;
}

void ControladorVenta::seleccionarProdYCant(DtProductoCantidad producto_cantidad) {
  
}
void ControladorVenta::agregarProductoAVenta();
void ControladorVenta::cancelarProductoAVenta();


//Quitar Producto a una Venta
map<int, DtProducto> ControladorVenta::getProductosVenta (int numMesa);
//seleccionarProdYCant
void ControladorVenta::eliminarProductoDeVenta();
void ControladorVenta::cancelarEliminarProductoDeVenta();


//Facturacion de una Venta
//ingresarNumeroMesa
void ControladorVenta::ingresarPorcentajeDescuento(float descuento);
DtFactura ControladorVenta::generarFactura();


//Resumen facturacion de 1 dia dada la fecha
map<int, DtFactura> ControladorVenta::getFacturasFecha();
float ControladorVenta::getTotalFacturadoFecha();


//Consultar actualizaciones de pedidos a domicilio por parte del administrador
set<DtActualizacion> ControladorVenta::getListadoActualizaciones();
