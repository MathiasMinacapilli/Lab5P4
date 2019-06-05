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
  Producto* prod; //seleccionarProdYCant - prod
  int cantidad; //seleccionarProdYCant - producto_cantidad.getCantidad
  Venta* v; //getProductosVenta - v
  int numero_venta;
public:
  ControladorVenta ControladorVenta::getInstance();

  //BAJA PRODUCTO - eliminarProducto - ControladorProducto
  bool ControladorVenta::estaEnVentaSinFacturar(Producto p);

  //INICIAR VENTA EN MESAS - iniciarVenta - ControladorMesa
  Venta ControladorVenta::crearVenta();

  //AGREGAR PRODUCTO A UNA VENTA
  void ControladorVenta::ingresarNumeroMesa(int numero);
  map<int, DtProducto> ControladorVenta::obtenerProductosDisponibles();
  void ControladorVenta::seleccionarProdYCant(DtProductoCantidad producto_cantidad);
  void ControladorVenta::agregarProductoAVenta();
  void ControladorVenta::cancelarProductoAVenta();

  //QUITAR PRODUCTO A UNA VENTA
  map<int, DtProducto> ControladorVenta::getProductosVenta (int numMesa);
  //seleccionarProdYCant
  void ControladorVenta::eliminarProductoDeVenta();
  void ControladorVenta::cancelarEliminarProductoDeVenta();

  //FACTURACION DE UNA VENTA
  //ingresarNumeroMesa
  void ControladorVenta::ingresarPorcentajeDescuento(float descuento);
  DtFactura ControladorVenta::generarFactura();

  //RESUMEN FACTURACION DE 1 DIA DADA LA FECHA
  map<int, DtFactura> ControladorVenta::getFacturasFecha();
  float ControladorVenta::getTotalFacturadoFecha();

  //CONSULTAR ACTUALIZACIONES DE PEDIDOS A DOMICILIO POR PARTE DEL ADMINISTRADOR
  set<DtActualizacion> ControladorVenta::getListadoActualizaciones();

};

#endif
