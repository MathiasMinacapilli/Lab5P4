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
    //Constructor protected porque es abstracta
    Venta();
    Venta(int numero, float descuento, Factura* factura);
    map<int, CantidadProducto*> cants_productos;
    void setProdsDomicilio(map<int, CantidadProducto*> prods_domiclio);
public:
    //Destructor
    virtual ~Venta();

    //Getters
    int getNumero();
    float getDescuento();
    map<int, CantidadProducto*> getCants_Productos();
    Factura* getFactura();

    //Setters
    void setDescuento(float descuento);
    void setFactura(Factura* factura);

    void agregarProductoAVenta(Producto* producto, int cantidad);
    bool buscarProducto(Producto* producto);
    bool estaFacturada();
    void eliminarProducto(Producto* producto, int cantidad);
    map<int, DtProducto> obtenerProductos();
    virtual DtFactura* facturar() = 0;
};

#endif
