//Librerias de C
#include <set>
using namespace std

//Archivos
#include "../include/Venta.hpp"

Venta::Venta(int numero, float descuento, map<int, CantidadProducto*> cant_producto, Factura* factura) {
    this->numero = numero;
    this->descuento = descuento;
    this->cant_producto = cant_producto;
    this->factura = factura;
}

void Venta::eliminarProducto(Producto prod, int cantidad) {
    
}
