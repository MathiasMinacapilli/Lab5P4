//Librerias de C
#include <map>
using namespace std;

//Archivos
#include "../include/Venta.hpp"

Venta::Venta() {}

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
  return this -> descuento;
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

void Venta::setProdsDomicilio(map<int, CantidadProducto*> prods_domicilio) {
    this->cants_productos = prods_domicilio;
}

void Venta::agregarProductoAVenta(Producto* producto, int cantidad) {
    map<int, CantidadProducto*> cant_prods = this->cants_productos;
    map<int, CantidadProducto*>::iterator it = cant_prods.begin();
    bool esta_producto = false;
    while ((it != cant_prods.end()) && (!esta_producto)) {
      esta_producto = (it->second)->estaProducto(producto->getCodigo());
      if (!esta_producto)
        ++it;
    }
    if (esta_producto)
        (it->second)->aumentarCantidad(cantidad);
    else {
        CantidadProducto* cant_producto = new CantidadProducto(cantidad, producto);
        (this->cants_productos).insert(pair<int, CantidadProducto*>(cant_producto->getProducto()->getCodigo(), cant_producto));
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
    map<int, CantidadProducto*>::iterator it  = cants_productos.begin();
    bool encontre_prod = false;
    while ((it != cants_productos.end()) && (!encontre_prod)) {
        if (!(encontre_prod = (it->second)->estaProducto(producto->getCodigo())))
            ++it;
    }
    if (encontre_prod == true) {
        bool es_cero = (it->second)->disminuir(cantidad);
        if (es_cero) {
            CantidadProducto* cant_producto = it->second;
            (it->second)->quitarProducto();
            it = cants_productos.erase(it);
            delete cant_producto;
        }
    }
    else
        throw new invalid_argument ("No existe el código del producto a quitar");
}

map<int, DtProducto> Venta::obtenerProductos() {
  map<int, CantidadProducto*>::iterator it;
  map<int, DtProducto> datos_productos;
  for(it = cants_productos.begin(); it != cants_productos.end(); ++it) {
      DtProducto datos = (it->second)->getProducto() -> getDatosProducto();
      datos_productos.insert(pair<int, DtProducto>(datos.getCodigo(), datos));
  }
  return datos_productos;
}
