//Librerias de C
#include <map>
#include <set>

//Archivos
#include "../include/ControladorVenta.hpp"
#include "../include/ControladorProducto.hpp"
#include "../include/ControladorMesa.hpp"
#include "../include/ControladorCliente.hpp"
#include "../include/DtFactura.hpp"


//inicializacion de instancia
ControladorVenta *ControladorVenta::instance = nullptr;

//constructor
ControladorVenta::ControladorVenta(){}

ControladorVenta *ControladorVenta::getInstance() {
  if (instance == nullptr)
    instance = new ControladorVenta();
  return instance;
}

//BAJA PRODUCTO - eliminarProducto - ControladorProducto
bool ControladorVenta::estaEnVentaSinFacturar(Producto *p) {
  map<int, Venta*>::iterator it;
  bool encontre_producto = false;
  bool existe_factura;
  for(it = ventas.begin(); ((it != ventas.end()) && (!encontre_producto)); ++it) {
    existe_factura = (it -> second) -> estaFacturada();
    if (!existe_factura)
      encontre_producto = (it->second) -> buscarProducto(p);
  }
  return encontre_producto;
}

//INICIAR VENTA EN MESAS - iniciarVenta - ControladorMesa
VentaLocal *ControladorVenta::crearVenta() {
  VentaLocal *ve = new VentaLocal((this -> numero_venta) + 1, 0, nullptr);
  (this -> numero_venta)++;
  ventas.insert(pair<int, Venta*>(ve -> getNumero(), ve));
  return ve;
}

//AGREGAR PRODUCTO A UNA VENTA
void ControladorVenta::ingresarNumeroMesa(int numero) {
    ControladorMesa* cont_mesa = ControladorMesa::getInstance();
    if (cont_mesa -> existeMesa(numero)){
        this -> numero_mesa = numero;
    } else {
        throw new invalid_argument("\nNo existe mesa asociada al número ingresado.");
    }
}
map<int, DtProducto> ControladorVenta::obtenerProductosDisponibles() {
  ControladorProducto *cont_prod;
  cont_prod = ControladorProducto::getInstance();
  map<int, DtProducto> dtprods = cont_prod -> getProductosDisponibles();
  return dtprods;
}
void ControladorVenta::seleccionarProdYCant(DtProductoCantidad producto_cantidad) {
  ControladorProducto *cont_prod;
  cont_prod = ControladorProducto::getInstance();
  Producto* prod = cont_prod -> encontrarProducto(producto_cantidad);
  this -> prod = prod;
  this -> cantidad = producto_cantidad.getCantidad();
}
void ControladorVenta::agregarProductoAVenta() {
  ControladorMesa *cont_mesa;
  cont_mesa = ControladorMesa::getInstance();
  Venta* v = cont_mesa -> obtenerVenta(this -> numero_mesa);
  v -> agregarProductoAVenta(this -> prod, this -> cantidad);
}
void ControladorVenta::cancelarProductoAVenta() {
  //QUE ONDA CON ESTO?
  //QUE ES LIBERAR LA MEMORIA??
  // AYUDAAA!!
  prod = nullptr;
  cantidad = 0;
  v = nullptr;
}

//QUITAR PRODUCTO A VENTA
map<int, DtProducto> ControladorVenta::getProductosVenta (int numMesa) {
  ControladorMesa *cont_mesa;
  cont_mesa = ControladorMesa::getInstance();
  Venta* v = cont_mesa -> obtenerVenta(this -> numero_mesa);
  map<int, DtProducto> productos_venta = v -> obtenerProductos();
  this -> v = v;
  return productos_venta;
}
//seleccionarProdYCant
void ControladorVenta::eliminarProductoDeVenta() {
  (this -> v) -> eliminarProducto(this -> prod, this -> cantidad);
}
void ControladorVenta::cancelarEliminarProductoDeVenta() {
  //QUE ONDA CON ESTO?
  //QUE ES LIBERAR LA MEMORIA??
  // AYUDAAA!!
  prod = nullptr;
  cantidad = 0;
  v = nullptr;
}

//FACTURACION DE UNA VENTA
//ingresarNumeroMesa
void ControladorVenta::ingresarPorcentajeDescuento(float descuento) {
  ControladorMesa *cont_mesa;
  cont_mesa = ControladorMesa::getInstance();
  Venta* v = cont_mesa -> obtenerVenta(this -> numero_mesa);
  v -> setDescuento(descuento);
}

DtFactura* ControladorVenta::generarFactura() {
  ControladorMesa *cont_mesa;
  cont_mesa = ControladorMesa::getInstance();
  Venta* v = cont_mesa -> obtenerVenta(this -> numero_mesa);
  DtFactura* factura = v -> facturar();
  cont_mesa -> finalizarVenta();
  return factura;
}

//VENTA A DOMICILIO
//FALTAN OP
//FALTAN OP
//FALTAN OP
//FALTAN OP
//FALTAN OP
//FALTAN OP
bool ControladorVenta::ingresarTelefono(string telefono) {
    this -> telefono_recordado = telefono;
    ControladorCliente *cont_cliente;
    cont_cliente = ControladorCliente::getInstance();
    return (cont_cliente -> existeCliente(telefono));
}

void ControladorVenta::cancelarVentaADomicilio() {
    //QUE ONDA CON ESTO?
    //QUE ES LIBERAR LA MEMORIA??
    // AYUDAAA!!
    prod = nullptr;
    cantidad = 0;
    v = nullptr;
}

DtFactura* ControladorVenta::generarFacturaDomiclio() {
  DtFactura* factura = venta_domicilio -> facturar();
  return factura;
}

//RESUMEN FACTURACION DE 1 DIA DADA LA FECHA
void ControladorVenta::ingresarFecha(DtFecha fecha) {
  this -> fecha_venta = fecha;
}

map<int, DtFactura> ControladorVenta::getFacturasYTotalFecha(float &totalfacturado) {
  map<int, Venta*>::iterator it;
  map<int, DtFactura> res;
  Venta* venta;
  Factura* factura;
  DtFactura dtfactura;
  totalfacturado = 0;
  for(it = ventas.begin(); it != ventas.end(); ++it) {
    venta = it -> second;
    if (venta -> estaFacturada()) {
      factura = venta -> getFactura();
      DtFecha fecha_factura = DtFecha((factura -> getFechaYHora()).getDia(), (factura -> getFechaYHora()).getMes(), (factura -> getFechaYHora()).getAnio());
      if (fecha_factura == this -> fecha_venta) {
        dtfactura = factura -> getDatosFactura();
        res.insert(pair<int, DtFactura>(dtfactura.getCodigo(), dtfactura));
        totalfacturado +=  dtfactura.getPrecioTotal();
      }
    }
  }
  return res;
}

//CONSULTAR ACTUALIZACIONES DE PEDIDOS A DOMICILIO POR PARTE DEL ADMINISTRADOR
set<DtActualizacion> ControladorVenta::getListadoActualizaciones() {
  set<DtActualizacion> res;
  set<DtActualizacion> aux;
  set<DtActualizacion>::iterator it_actualizacion;
  pair<set<DtActualizacion>::iterator, bool> ptr;
  map<int, Venta*>::iterator it;
  for(it = ventas.begin(); it != ventas.end(); ++it) {
    Venta *v = it->second;
    const VentaADomicilio* venta_domicilio = dynamic_cast<VentaADomicilio*>(const_cast<Venta*>(v));
    aux = venta_domicilio -> getActualizaciones();
    for (it_actualizacion = aux.begin(); it_actualizacion != aux.end(); ++it_actualizacion){
          DtActualizacion dt_act = *it_actualizacion;
          ptr = res.insert(dt_act);
      }
  }
  return res;
}
