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

void Venta::eliminarProducto(Producto* prod, int cantidad) {
    map<int, CantidadProducto*>::iterator it;
    bool encontre_prod = false;
    for(it = cant_producto.begin(); ((it != cant_producto.end()) && (!encontre_prod)); ++it) {
        encontre_prod = (it->second)->estaProducto(prod->getNumero());
    }
    if (encontre_prod == true) {
        bool es_cero = (it->second)->disminuir(cantidad);
        if (es_cero) {
            (it->second)->quitarProducto();
            CantidadProducto* cp = it->second;
            cant_producto.erase(it);
            delete cp;
        }
    }
}
