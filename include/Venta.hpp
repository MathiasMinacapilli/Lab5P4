#ifndef _VENTA_HPP
#define _VENTA_HPP

// Librerias de C
#include <ctime>
#include <map>
#include <set>
using namespace std;

// Archivos
#include "DtProductoCantidad.hpp"
#include "Producto.hpp"
#include "CantidadProducto.hpp"
#include "Factura.hpp"
#include "DtActualizacion.hpp"

class Venta {
private:
    int numero;
    float descuento;
    Factura* factura;
protected:
    Venta(int numero, float descuento, Factura* factura);
    map<int, CantidadProducto*> cants_productos;
public:
    virtual ~Venta();

    // Getters
    int getNumero();
    float getDescuento();
    map<int, CantidadProducto*> getCants_Productos();
    Factura* getFactura();
    
    // Setters
    void setDescuento(float descuento);
    void setFactura(Factura* factura);

    void agregarProductoAVenta(Producto* producto, int cantidad);
    bool buscarProducto(Producto* producto);
    bool estaFacturada();
    void eliminarProducto(Producto* producto, int cantidad);
    DtFactura facturar();
    map<int, DtProducto> obtenerProductos();
};

#endif
