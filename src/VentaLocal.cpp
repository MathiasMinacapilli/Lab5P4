//Librearias de C
using namespace std;

//Archivos
#include "../include/VentaLocal.hpp";

VentaLocal::(int numero, float descuento, map<int, CantidadProducto*> cant_producto, Factura* factura):Venta(numero, descuento, cant_producto, factura) {
}

VentaLocal::~VentaLocal() {
}

void VentaLocal::agregarProductoAVenta(Producto *prod) {
  map<int, CantidadProducto*>::iterator it;
  bool esta_prod = false;
  for(it = cant_producto.begin(); it != cant_producto.end(); ++it)
      esta_prod = (it -> second) -> estaProducto(prod -> getCodigo());
  if (esta_prod)
      (it -> second) -> aumentarCantidad(/* aca en realidad no sabemos que va */);
  else {
      CantidadProducto* cant_prod = new CantidadProducto(/* aca tampoco */, prod)
      (this -> cant_producto).insert(pair<int, CantidadProducto*>(cant_prod -> getCodigo(), cant_prod))
  }
}

bool VentaLocal::buscarProducto(Producto p) {

}

bool VentaLocal::estaFacturada() {

}
