

//Librerias de C
#include <set>
using namespace std;

//Archivos
#include "DtProductoCantidad.hpp";
#include "DtProducto.hpp";
#include "DtFactura.hpp";
#include "DtInfoVenta.hpp";
#include "Venta.hpp";
#include "Producto.hpp";

class IVenta { // interfaz
public:
    virtual void agregarProductoAVenta() = 0;
    virtual void cancelarEliminarProductoDeVenta() = 0;
    virtual void cancelarProductoAVenta() = 0;
    virtual Venta crearVenta() = 0;
    virtual void eliminarProductoDeVenta() = 0;
    virtual bool estaEnVentaSinFacturar(Producto p) = 0;
    virtual DtFactura generarFactura() = 0;
    virtual set<DtFactura> getFacturasFecha() = 0;
    virtual set<DtInfoVenta> getListadoActualizaciones() = 0;
    virtual set<DtProducto> getProductosVenta(int numMesa) = 0;
    virtual float getTotalFacturadoFecha() = 0;
    virtual void ingresarNumeroMesa(int numero) = 0;
    virtual void ingresarPorcentajeDescuento(float descuento) = 0;
    virtual set<DtProducto> obtenerProductosDisponibles() = 0;
    virtual void seleccionarProductoYCantidad(DtProductoCantidad producto_cantidad) = 0;
    virtual ~IVenta(){}; // virtual y vacío
};