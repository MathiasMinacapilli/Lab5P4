//Librerias de C
#include <set>
using namespace std

//Archivos
#include "../include/Venta.hpp"

Venta::Venta(int numero, float descuento, Factura* factura) {
    this -> numero = numero;
    this -> descuento = descuento;
    this -> factura = factura;
    cants_productos.clear();
}

Venta::~Venta() {
}

int Venta::getNumero() {
  return this -> numero;
}

float Venta::getDescuento() {
  return this -> descuento:
}

map<int, CantidadProducto*> Venta::getCants_Productos() {
  return this -> cants_productos;
}

Factura* Venta::getFactura() {
  return this -> factura;
}

void Venta::setDescuento(float descuento) {
  this -> descuento = descuento;
}

void Venta::setFactura(Factura* factura) {
  this -> factura = factura;
}

void VentaLocal::agregarProductoAVenta(Producto* producto, int cantidad) {
  map<int, CantidadProducto*>::iterator it;
  bool esta_producto = false;
  for(it = cants_productos.begin(); ((it != cants_productos.end()) && (!esta_producto)); ++it)
      esta_producto = (it->second)->estaProducto(producto->getCodigo());
  if (esta_producto)
      (it->second)->aumentarCantidad(cantidad);
  else {
      CantidadProducto* cant_producto = new CantidadProducto(cantidad, producto);
      (this->cants_productos).insert(pair<int, CantidadProducto*>(cant_producto->getCodigo(), cant_producto));
  }
}

bool Venta::buscarProducto(Producto* producto) {
    map<int, CantidadProducto*>::iterator it;
    bool esta_producto = false;
    for(it = cants_productos.begin(); ((it != cants_productos.end()) && (!esta_producto)); ++it)
        esta_producto = (it->second)->estaProducto(producto->getCodigo());
    return esta_producto;
}

bool Venta::estaFacturada() {
    return !(this->factura == nullptr);
}

void Venta::eliminarProducto(Producto* producto, int cantidad) {
    map<int, CantidadProducto*>::iterator it;
    bool encontre_prod = false;
    for(it = cants_productos.begin(); ((it != cants_productos.end()) && (!encontre_prod)); ++it) {
        encontre_prod = (it->second)->estaProducto(producto->getCodigo());
    }
    if (encontre_prod == true) {
        bool es_cero = (it->second)->disminuir(cantidad);
        if (es_cero) {
            (it->second)->quitarProducto();
            CantidadProducto* cant_producto = it->second;
            cants_productos.erase(it);
            delete cant_producto;
        }
    }
}

DtFactura Venta::facturar() {
    map<int, CantidadProducto*>::iterator it;
    map<int, DtProducto> datos_productos;
    int precio_sub_total = 0;
    for(it = cants_productos.begin(); it != cants_productos.end(); ++it) {
        DtProducto datos = (it->second)->obtenerDatosProductos();
        datos_productos.insert(pair<int, DtProducto>(datos.getCodigo(), datos));
        precio_sub_total = precio_sub_total + (((it->second)->getProducto())->getPrecio());
    }
    int precio_total = precio_sub_total * (1 - this->descuento) * (1 + valor_iva);
    time_t t = time(0);
    tm* now = localtime(&t);
    DtFechaYHora fecha_y_hora = DtFechaYHora(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900, now->tm_hour, now->tm_min, now->tm_sec);
    Factura* factura = new Factura(this->codigo, fecha_y_hora, datos_productos, valor_iva, this->descuento, precio_sub_total, precio_total);
    this->factura = factura;
    DtFactura res = DtFactura(this->codigo, fecha_y_hora, datos_productos, valor_iva, this->descuento, precio_sub_total, precio_total);
    return res;
}

map<int, DtProducto> Venta::obtenerProductos() {
  map<int, CantidadProducto*>::iterator it;
  map<int, DtProducto> datos_productos;
  for(it = cants_productos.begin(); it != cants_productos.end(); ++it) {
      DtProducto datos = (it->second)->obtenerDatosProductos();
      datos_productos.insert(pair<int, DtProducto>(datos.getCodigo(), datos));
  }
  return datos_productos;
}
