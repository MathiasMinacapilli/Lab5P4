#ifndef _VENTA_HPP
#define _VENTA_HPP

// Librerias de C
#include <map>
using namespace std;

// Archivos
#include "DtProducto.hpp";
#include "Producto.hpp";
#include "Facturar.hpp";

class Venta {
private:
    int numero;
    float descuento;
    map<int, CantidadProducto*> cant_producto;
    Factura* factura;
protected:
    Venta(int numero, float descuento, map<int, CantidadProducto*> cant_producto, Factura* factura);
public:
    // Getters
    int getNumero();
    float getDescuento();
    map<int, CantidadProducto*> getCant_Producto
    Factura* getFactura();

    virtual void agregarProductoAVenta(Producto* prod) = 0;
    virtual bool buscarProducto(Producto* p) = 0;
    virtual bool estaFacturada() = 0;
    void eliminarProducto(Producto* prod, int cantidad);
    void facturar();
    map<int, DtProducto> obtenerProductos();
    ~Venta();
};

#endif
