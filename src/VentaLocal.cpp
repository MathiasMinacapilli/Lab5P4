//Librearias de C
using namespace std;

//Archivos
#include "../include/VentaLocal.hpp";

VentaLocal::(int numero, float descuento, map<int, CantidadProducto*> cant_producto, Factura* factura):Venta(numero, descuento, cant_producto, factura) {
}

VentaLocal::~VentaLocal() {
}
