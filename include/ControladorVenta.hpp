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
  int numero_mesa; //ingresarNumeroMesa - numero
  Producto prod; //seleccionarProdYCant - prod
  int cantidad; //seleccionarProdYCant - producto_cantidad.getCantidad
  Venta v; //get<ProductosVenta - v
public:
  ControladorVenta ControladorVenta::getInstance();

  //Baja Producto - eliminarProducto - ControladorProducto
  bool ControladorVenta::estaEnVentaSinFacturar(Producto p);

  //Iniciar Venta en Mesas - iniciarVenta - ControladorMesa
  Venta ControladorVenta::crearVenta();

  //Agregar Producto a una Venta
  void ControladorVenta::ingresarNumeroMesa(int numero);
  map<int, DtProducto> ControladorVenta::obtenerProductosDisponibles();
  void ControladorVenta::seleccionarProdYCant(DtProductoCantidad producto_cantidad);
  void ControladorVenta::agregarProductoAVenta();
  void ControladorVenta::cancelarProductoAVenta();

  //Quitar Producto a una Venta
  map<int, DtProducto> ControladorVenta::getProductosVenta (int numMesa);
  //seleccionarProdYCant
  void ControladorVenta::eliminarProductoDeVenta();
  void ControladorVenta::cancelarEliminarProductoDeVenta();

  //Facturacion de una Venta
  //ingresarNumeroMesa
  void ControladorVenta::ingresarPorcentajeDescuento(float descuento);
  DtFactura ControladorVenta::generarFactura();

  //Resumen facturacion de 1 dia dada la fecha
  map<int, DtFactura> ControladorVenta::getFacturasFecha();
  float ControladorVenta::getTotalFacturadoFecha();

  //Consultar actualizaciones de pedidos a domicilio por parte del administrador
  set<DtActualizacion> ControladorVenta::getListadoActualizaciones();

};

#endif
