#ifndef _IVENTA_HPP
#define _IVENTA_HPP

//Librerias de C
#include <map>
#include <set>
#include <vector>
using namespace std;

//Archivos
#include "Venta.hpp"
#include "DtFactura.hpp"
#include "DtActualizacion.hpp"
#include "Producto.hpp"
#include "DtProducto.hpp"
#include "DtProductoCantidad.hpp"

class IVenta { // interfaz
protected:
    IVenta();
public:
    virtual void agregarProductoAVenta() = 0;
    virtual void cancelarEliminarProductoDeVenta() = 0;
    virtual void cancelarProductoAVenta() = 0;
    virtual VentaLocal *crearVenta() = 0;
    virtual void eliminarProductoDeVenta() = 0;
    virtual bool estaEnVentaSinFacturar(Producto *p) = 0;
    virtual DtFactura* generarFactura() = 0;
    virtual map<int, DtFactura> getFacturasYTotalFecha(float &totalfacturado) = 0;
    virtual vector<DtActualizacion> getListadoActualizaciones() = 0;
    virtual map<int, DtProducto> getProductosVenta(int numMesa) = 0;
    virtual void ingresarFecha(DtFecha fecha) = 0;
    virtual void ingresarNumeroMesa(int numero) = 0;
    virtual void ingresarPorcentajeDescuento(float descuento) = 0;
    virtual bool ingresarTelefono(string telefono) = 0;
    virtual map<int, DtProducto> obtenerProductosDisponibles() = 0;
    virtual void seleccionarProdYCant(DtProductoCantidad producto_cantidad) = 0;
    virtual ~IVenta(){}; // virtual y vacío
};

#endif
