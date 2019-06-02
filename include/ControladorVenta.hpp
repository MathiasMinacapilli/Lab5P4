#ifndef _CONTROLADORVENTA_HPP
#define _CONTROLADORVENTA_HPP

//Librerias de C
using namespace std;
#include <map>
#include <set>

//Archivos
#include "IVenta.hpp"

class ControladorVenta : public IVenta {
private:
  ControladorVenta();
  static ControladorVenta *instance;
  map<int, Venta*> ventas;  
public:
  ControladorVenta getInstance();
  void agregarProductoAVenta();
  void cancelarEliminarProductoDeVenta();
  void cancelarProductoAVenta();
  Venta crearVenta();
  void eliminarProductoDeVenta();
  bool estaEnVentaSinFacturar(Producto p);
  DtFactura generarFactura();
  map<int, DtFactura> getFacturasFecha();
  set<DtActualizacion> getListadoActualizaciones();
  map<int, DtProducto> getProductosVenta (int numMesa);
  float getTotalFacturadoFecha();
  void ingresarNumeroMesa(int numero);
  void ingresarPorcentajeDescuento(float descuento);
  map<int, DtProducto> obtenerProductosDisponibles();
  void seleccionarProdYCant(DtProductoCantidad producto_cantidad);
};

#endif
