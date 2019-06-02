#ifndef _IVENTA_HPP
#define _IVENTA_HPP

//Librerias de C
#using namespace std;
#include <map>
#include <set>

//Archivos
#include "Venta.hpp"
#include "DtFactura.hpp"
#include "DtActualizacion.hpp"
#include "Producto.hpp"
#include "DtProducto.hpp"
#include "DtProductoCantidad.hpp"

class IVenta { // interfaz
public:
    virtual void agregarProductoAVenta() = 0;
    virtual void cancelarEliminarProductoDeVenta() = 0;
    virtual void cancelarProductoAVenta() = 0;
    virtual Venta crearVenta() = 0;
    virtual void eliminarProductoDeVenta() = 0;
    virtual bool estaEnVentaSinFacturar(Producto p) = 0;
    virtual DtFactura generarFactura() = 0;
    virtual map<int, DtFactura> getFacturasFecha() = 0;
    virtual set<DtActualizacion> getListadoActualizaciones() = 0;
    virtual map<int, DtProducto> getProductosVenta(int numMesa) = 0;
    virtual float getTotalFacturadoFecha() = 0;
    virtual void ingresarNumeroMesa(int numero) = 0;
    virtual void ingresarPorcentajeDescuento(float descuento) = 0;
    virtual map<int, DtProducto> obtenerProductosDisponibles() = 0;
    virtual void seleccionarProductoYCantidad(DtProductoCantidad producto_cantidad) = 0;
    virtual ~IVenta(){}; // virtual y vacío
};

#endif
