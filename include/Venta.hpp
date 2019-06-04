#ifndef _VENTA_HPP
#define _VENTA_HPP

// Librerias de C
#include ctime
#include <map>
using namespace std;

// Archivos
#include "DtProductoCantidad.hpp";
#include "Producto.hpp";
#include "Facturar.hpp";

class Venta {
private:
    int numero;
    float descuento;
    map<int, CantidadProducto*> cants_productos;
    Factura* factura;
protected:
    Venta(int numero, float descuento, Factura* factura);
public:
    ~Venta();

    // Getters
    int getNumero();
    float getDescuento();
    map<int, CantidadProducto*> getCants_Productos();
    Factura* getFactura();

    void agregarProductoAVenta(Producto* producto, DtProductoCantidad prod_cantidad);
    bool buscarProducto(Producto* producto);
    bool estaFacturada();
    void eliminarProducto(Producto* producto, int cantidad);
    void facturar();
    map<int, DtProducto> obtenerProductos();
};

#endif
