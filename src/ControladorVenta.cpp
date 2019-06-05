//Librerias de C
using namespace std;
#include <map>
#include <set>

//Archivos
#include "../include/ControladorVenta.hpp"
//#include "../include/ControladorProducto.hpp"
//#include "../include/ControladorMesa.hpp"

ControladorVenta::ControladorVenta() {
}

ControladorVenta ControladorVenta::getInstance() {
  if (instance == nullptr)
    instance = new ControladorVenta;
  return instance;
}

//BAJA PRODUCTO - eliminarProducto - ControladorProducto
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

//INICIAR VENTA EN MESAS - iniciarVenta - ControladorMesa
Venta ControladorVenta::crearVenta() {
  ve = new VentaLocal((this -> numero_venta) + 1, 0, NULL);
  (this -> numero_venta)++;
  ventas.insert(pair<int, Venta>(ve -> getCodigo(), ve));
  return ve;
}

//AGREGAR PRODUCTO A UNA VENTA
void ControladorVenta::ingresarNumeroMesa(int numero) {
  this -> numero_mesa = numero;
}
map<int, DtProducto> ControladorVenta::obtenerProductosDisponibles() {
  ControladorProducto *cont_prod;
  cont_prod = ControladorProducto::getInstance();
  map<int, DtProducto> dtprods = 	cont_prod -> getProductosDisponibles();
  return dtprods;
}
void ControladorVenta::seleccionarProdYCant(DtProductoCantidad producto_cantidad) {
  ControladorProducto *cont_prod;
  cont_prod = ControladorProducto::getInstance();
  Producto* prod = cont_prod -> encontrarProducto(producto_cantidad);
  this -> prod = prod;
  this - > cantidad = producto_cantidad.getCantidad();
}
void ControladorVenta::agregarProductoAVenta() {
  ControladorMesa *cont_mesa;
  cont_mesa = ControladorMesa::getInstance();
  Venta* v = cont_mesa -> obtenerVenta(this -> numero_mesa);
  v -> agregarProductoAVenta(this -> prod, this -> cantidad);
}
void ControladorVenta::cancelarProductoAVenta() {
  //QUE ONDA CON ESTO?
  //QUE ES LIBERAR LA MEMORIA??
  // AYUDAAA!!
  prod = nullptr;
  cantidad = 0;
  v = nullptr;
}

//QUITAR PRODUCTO A VENTA
map<int, DtProducto> ControladorVenta::getProductosVenta (int numMesa) {
  ControladorMesa *cont_mesa;
  cont_mesa = ControladorMesa::getInstance();
  Venta* v = cont_mesa -> obtenerVenta(this -> numero_mesa);
  map<int, DtProducto> productos_venta = v -> obtenerProductos();
  this -> v = v;
}
//seleccionarProdYCant
void ControladorVenta::eliminarProductoDeVenta() {
  (this -> v) -> eliminarProducto(this -> prod, this -> cantidad);
}
void ControladorVenta::cancelarEliminarProductoDeVenta() {
  //QUE ONDA CON ESTO?
  //QUE ES LIBERAR LA MEMORIA??
  // AYUDAAA!!
  prod = nullptr;
  cantidad = 0;
  v = nullptr;
}

//FACTURACION DE UNA VENTA
//ingresarNumeroMesa
void ControladorVenta::ingresarPorcentajeDescuento(float descuento) {
  ControladorMesa *cont_mesa;
  cont_mesa = ControladorMesa::getInstance();
  Venta* v = cont_mesa -> obtenerVenta(this -> numero_mesa);
  v -> setDescuento(descuento);
}
DtFactura ControladorVenta::generarFactura() {
  ControladorMesa *cont_mesa;
  cont_mesa = ControladorMesa::getInstance();
  Venta* v = cont_mesa -> obtenerVenta(this -> numero_mesa);
  DtFactura factura = v -> facturar();
  cont_mesa -> finalizarVenta();
  return factura;
}

//RESUMEN FACTURACION DE 1 DIA DADA LA FECHA
map<int, DtFactura> ControladorVenta::getFacturasFecha() {
  
}
float ControladorVenta::getTotalFacturadoFecha();

//CONSULTAR ACTUALIZACIONES DE PEDIDOS A DOMICILIO POR PARTE DEL ADMINISTRADOR
set<DtActualizacion> ControladorVenta::getListadoActualizaciones();
