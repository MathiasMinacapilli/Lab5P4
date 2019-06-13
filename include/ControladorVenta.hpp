#ifndef _CONTROLADORVENTA_HPP
#define _CONTROLADORVENTA_HPP

//Librerias de C
#include <map>
#include <set>
using namespace std;

//Archivos
#include "IVenta.hpp"
#include "VentaLocal.hpp"
#include "VentaADomicilio.hpp"
#include "DtFecha.hpp"
//#include "DtFactura.hpp"

class ControladorVenta : public IVenta {
private:
  //constructor
  ControladorVenta();
  //instancia patron Singleton
  static ControladorVenta *instance;
  //coleccion de ventas
  map<int, Venta*> ventas;
  int numero_mesa; //AGREGAR PRODUCTO A UNA VENTA - ingresarNumeroMesa - numero
  Producto* prod; //AGREGAR PRODUCTO A UNA VENTA - seleccionarProdYCant - prod
  int cantidad; //AGREGAR PRODUCTO A UNA VENTA - seleccionarProdYCant - producto_cantidad.getCantidad
  Venta* v; //QUITAR PRODUCTO A UNA VENTA - getProductosVenta - v
  int numero_venta; //INICIAR VENTA EN MESAS - iniciarVenta
  DtFecha fecha_venta; //RESUMEN FACTUACION 1 DIA DADA LA FECHA - ingresarFecha - fecha
  string telefono_recordado; //VENTA A DOMICILIO - ingresarTelefono - telefono
public:
  static ControladorVenta *getInstance();

  //BAJA PRODUCTO - eliminarProducto - ControladorProducto
  bool estaEnVentaSinFacturar(Producto *p);

  //INICIAR VENTA EN MESAS - iniciarVenta - ControladorMesa
  VentaLocal *crearVenta();

  //AGREGAR PRODUCTO A UNA VENTA
  void ingresarNumeroMesa(int numero);
  map<int, DtProducto> obtenerProductosDisponibles();
  void seleccionarProdYCant(DtProductoCantidad producto_cantidad);
  void agregarProductoAVenta();
  void cancelarProductoAVenta();

  //QUITAR PRODUCTO A UNA VENTA
  map<int, DtProducto> getProductosVenta (int numMesa);
  //seleccionarProdYCant
  void eliminarProductoDeVenta();
  void cancelarEliminarProductoDeVenta();

  //FACTURACION DE UNA VENTA
  //ingresarNumeroMesa
  void ingresarPorcentajeDescuento(float descuento);
  DtFactura* generarFactura();

  //VENTA A DOMICILIO
  bool ingresarTelefono(string telefono);
  void cancelarVentaADomicilio();

  //RESUMEN FACTURACION DE 1 DIA DADA LA FECHA
  void ingresarFecha(DtFecha fecha);
  map<int, DtFactura> getFacturasYTotalFecha(float &totalfacturado);

  //CONSULTAR ACTUALIZACIONES DE PEDIDOS A DOMICILIO POR PARTE DEL ADMINISTRADOR
  set<DtActualizacion> getListadoActualizaciones();

};

#endif
