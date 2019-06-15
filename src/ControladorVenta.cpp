//Librerias de C
#include <map>
#include <algorithm>
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
ControladorVenta::ControladorVenta(){
  this->numero_venta = 1;
}

ControladorVenta *ControladorVenta::getInstance() {
  if (instance == nullptr)
    instance = new ControladorVenta();
  return instance;
}

//BAJA PRODUCTO - eliminarProducto - ControladorProducto
bool ControladorVenta::estaEnVentaSinFacturar(Producto *p) {
  map<int, VentaLocal*>::iterator it_local;
  bool encontre_producto = false;
  bool existe_factura;
  for(it_local = ventasLocales.begin(); ((it_local != ventasLocales.end()) && (!encontre_producto)); ++it_local) {
    existe_factura = (it_local -> second) -> estaFacturada();
    if (!existe_factura)
      encontre_producto = (it_local->second) -> buscarProducto(p);
  }
  return encontre_producto;
}

//INICIAR VENTA EN MESAS - iniciarVenta - ControladorMesa
VentaLocal *ControladorVenta::crearVenta() {
  bool encontre_lugar = false;
  VentaLocal *ve;
  while (!encontre_lugar){
    if (!this->existeVenta(this->numero_venta)){
      ve = new VentaLocal((this -> numero_venta), 0, nullptr);
      encontre_lugar = true;
    }
    else this->numero_venta++;

  }
  ventasLocales.insert(pair<int, VentaLocal *>(ve -> getNumero(), ve));
  this -> numero_venta++;
  return ve;
}

//AGREGAR PRODUCTO A UNA VENTA
void ControladorVenta::ingresarNumeroMesa(int numero) {
    ControladorMesa* cont_mesa = ControladorMesa::getInstance();
    if (cont_mesa -> existeMesa(numero)){
        this -> numero_mesa = numero;
    } else {
        throw new invalid_argument("No existe mesa asociada al número ingresado");
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
    if(v != nullptr)
        v -> agregarProductoAVenta(this -> prod, this -> cantidad);
    else
        throw new invalid_argument("La mesa seleccionada no tiene una venta iniciada.");
}

void ControladorVenta::cancelarProductoAVenta() {
  prod = nullptr;
  cantidad = 0;
  numero_mesa = 0;
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
    prod = nullptr;
  cantidad = 0;
  v = nullptr;
}

//FACTURACION DE UNA VENTA
//ingresarNumeroMesa
void ControladorVenta::ingresarPorcentajeDescuento(float descuento) {
    ControladorMesa *cont_mesa;
    cont_mesa = ControladorMesa::getInstance();
    VentaLocal *v = cont_mesa -> obtenerVenta(this -> numero_mesa);
    if (v != nullptr) {
        map<int, CantidadProducto*>::iterator it;
        float el_descuento = descuento;
        for (it = (v -> getCants_Productos()).begin(); (it != (v -> getCants_Productos()).end()); ++it) {
            Producto* prod = (it -> second) -> getProducto();
            ProductoSimple* prod_simple = dynamic_cast<ProductoSimple* >(prod);
            if (prod_simple == nullptr)
                el_descuento = 0;
        }
        v -> setDescuento(el_descuento);
    }
    else
        throw new invalid_argument ("No hay venta para facturar en la mesa ingresada");
}

DtFactura* ControladorVenta::generarFactura() {
    ControladorMesa *cont_mesa;
    cont_mesa = ControladorMesa::getInstance();
    VentaLocal *v = cont_mesa -> obtenerVenta(this -> numero_mesa);
    if (v != nullptr) {
        DtFactura* factura = v -> facturar();
        cont_mesa -> finalizarVenta();
        return factura;
    } else
        throw new invalid_argument ("No hay venta para facturar en la mesa ingresada");
}

//VENTA A DOMICILIO

bool ControladorVenta::ingresarTelefono(string telefono) {
    this -> telefono_recordado = telefono;
    ControladorCliente *cont_cliente;
    cont_cliente = ControladorCliente::getInstance();
    return (cont_cliente -> existeCliente(telefono));
}

//obtenerProductosDisponibles

void ControladorVenta::almacenarProducto(DtProductoCantidad prod_y_cant) {
    ControladorProducto *cont_prod;
    cont_prod = ControladorProducto::getInstance();
    cont_prod -> seleccionarProductoYCantidad(prod_y_cant);
}

map<int, Repartidor*> ControladorVenta::obtenerRepartidores() {
    ControladorEmpleado *cont_emp;
    cont_emp = ControladorEmpleado::getInstance();
    map<int, Repartidor*> repartidores = cont_emp -> getRepartidoresDisponibles();
    return repartidores;
}

void ControladorVenta::elegirRepartidor(int numero_repartidor) {
    ControladorEmpleado *cont_emp;
    cont_emp = ControladorEmpleado::getInstance();
    cont_emp -> seleccionarRepartidor(numero_repartidor);
}

void ControladorVenta::crearVentaADomicilio(bool quiere_repartidor, float descuento) {
    ControladorProducto *cont_prod;
    cont_prod = ControladorProducto::getInstance();
    ControladorCliente *cont_cliente;
    cont_cliente = ControladorCliente::getInstance();
    //busco numero de venta sin usar
    bool encontre_lugar = false;
    while (!encontre_lugar){
      if (!this->existeVenta(this->numero_venta)){
        encontre_lugar = true;
      }
      else this->numero_venta++;
    }
    Cliente* mi_cliente = cont_cliente -> getCliente(telefono_recordado);
    bool tiene_menu = false;
    map<int, CantidadProducto*> cant_prods = cont_prod -> getProductosAlmacenados(tiene_menu);
    int el_descuento = descuento;
    if (tiene_menu) {
        el_descuento = 0;
    }
    if (quiere_repartidor) {
        ControladorEmpleado *cont_emp;
        cont_emp = ControladorEmpleado::getInstance();
        Etapa* etapa = new Pedido();
        Repartidor* mi_repartidor = cont_emp -> getRepartidorRecordado();
        VentaADomicilio* ve = new VentaADomicilio(this -> numero_venta, el_descuento, nullptr, etapa, mi_cliente, mi_cliente, mi_repartidor);
        ve -> setProdsDomicilio(cant_prods);
        venta_domicilio = ve;
        this->ventasDomicilio[ve->getNumero()] = ve;

    } else {
        Etapa* etapa = new Recibido();
        VentaADomicilio* ve = new VentaADomicilio(this -> numero_venta, el_descuento, nullptr, etapa, mi_cliente, mi_cliente, nullptr);
        ve -> setProdsDomicilio(cant_prods);
        venta_domicilio = ve;
        this->ventasDomicilio[ve->getNumero()] = ve;
    }
    this->numero_venta++;
}

void ControladorVenta::cancelarVentaADomicilio() {
    ControladorProducto *cont_prod;
    cont_prod = ControladorProducto::getInstance();
    ControladorEmpleado *cont_emp;
    cont_emp = ControladorEmpleado::getInstance();
    this -> telefono_recordado = ' ';
    cont_prod -> borrarProductos();
    cont_emp -> borrarNumero();
}

DtFactura* ControladorVenta::generarFacturaADomicilio() {
  DtFactura* factura = this->venta_domicilio->facturar();
  return factura;
}

//RESUMEN FACTURACION DE 1 DIA DADA LA FECHA
void ControladorVenta::ingresarFecha(DtFecha fecha) {
  this -> fecha_venta = fecha;
}

map<int, DtFactura> ControladorVenta::getFacturasYTotalFecha(float &totalfacturado) {
    map<int, VentaLocal *>::iterator it_local;
    map<int, VentaADomicilio *>::iterator it_domicilio;
    map<int, DtFactura> res;
    VentaLocal* ventalocal;
    VentaADomicilio *ventadomicilio;
    Factura* factura;
    DtFactura dtfactura;
    totalfacturado = 0;
    for(it_local = ventasLocales.begin(); it_local != ventasLocales.end(); ++it_local) {
        ventalocal = it_local -> second;
        if (ventalocal -> estaFacturada()) {
            factura = ventalocal -> getFactura();
            DtFecha fecha_factura = DtFecha((factura -> getFechaYHora()).getDia(), (factura -> getFechaYHora()).getMes(), (factura -> getFechaYHora()).getAnio());
            if (fecha_factura == this -> fecha_venta) {
                dtfactura = factura -> getDatosFactura();
                res.insert(pair<int, DtFactura>(dtfactura.getCodigo(), dtfactura));
                totalfacturado +=  dtfactura.getPrecioTotal();
            }
        }
    }
    for(it_domicilio = ventasDomicilio.begin(); it_domicilio != ventasDomicilio.end(); ++it_domicilio) {
        ventadomicilio = it_domicilio -> second;
        if (ventadomicilio -> estaFacturada()) {
            factura = ventadomicilio -> getFactura();
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
vector<DtActualizacion> ControladorVenta::getListadoActualizaciones() {
  vector<DtActualizacion> aux;
  vector<DtActualizacion> res;
  res.clear();
  map<int, VentaADomicilio *>::iterator it;
  for (it = this->ventasDomicilio.begin(); it != this->ventasDomicilio.end(); ++it){
      aux = (it -> second) -> getActualizaciones();
      res.insert(res.end(), aux.begin(), aux.end() );
  }
  std::sort(res.begin(), res.end());
  return res;
}


//funciones auxiliares para implementar patron Observer
void ControladorVenta::suscribirCliente(string telefono){
  map<int, VentaADomicilio *>::iterator it;
  for (it = this->ventasDomicilio.begin(); it != this->ventasDomicilio.end(); ++it){
    Cliente *cliente = it->second->getCliente();
    if (cliente->getTelefono() == telefono)
      it->second->setObservador(cliente);
  }
}


void ControladorVenta::desSuscribirCliente(string telefono){
  map<int, VentaADomicilio *>::iterator it;
  for (it = this->ventasDomicilio.begin(); it != this->ventasDomicilio.end(); ++it){
    Cliente *cliente = it->second->getCliente();
    if (cliente->getTelefono() == telefono)
      it->second->borrarObservador();
  }
}

vector<DtActualizacion> ControladorVenta::getActualizacionesCliente(string telefono){
  ControladorCliente *cont_cliente = ControladorCliente::getInstance();
  Cliente *cliente = cont_cliente->getCliente(telefono);
  return cliente->consultarPedidos();
}


//AVANZAR ETAPA DE UN PEDIDO
map<int, VentaADomicilio *> ControladorVenta::obtenerVentasRepartidor(int num){
  map<int, VentaADomicilio *>::iterator it;
  map<int, VentaADomicilio *> res;
  res.clear();
  for (it = this->ventasDomicilio.begin(); it != this->ventasDomicilio.end(); ++it){
    VentaADomicilio *v = it->second;
      if (v->getRepartidor() != nullptr)
        if (v->getRepartidor()->getNumero() == num)
          res[v->getNumero()] = v;


  }
  return res;
}

//CARGAR DATOS DE PRUEBA
bool ControladorVenta::existeVenta(int num){
  map<int, VentaLocal *>::iterator it_local = this->ventasLocales.find(num);
  map<int, VentaADomicilio *>::iterator it_domicilio;
  if (it_local == this->ventasLocales.end()){
    it_domicilio = this->ventasDomicilio.find(num);
    if (it_domicilio == this->ventasDomicilio.end())
      return false;
    else return true;
  }
  else return true;

}

void ControladorVenta::aumentarNumeroVenta() {
    this -> numero_venta = (this -> numero_venta) + 1;
}

void ControladorVenta::agregarVentaDomicilio(VentaADomicilio *v){
  if (this->ventasDomicilio.find(v->getNumero()) == this->ventasDomicilio.end())
    this->ventasDomicilio[v->getNumero()] = v;
  else throw new invalid_argument("Error. Ya existe una venta con ese codigo");
}

//Caso de uso: ventas de un mozo
map<int, DtFactura> ControladorVenta::getVentasLocalesDelMozoFacturadas(int num_mozo) {
    map<int, Factura*> ret_objeto;
    map<int, DtFactura> ret;
    map<int, VentaLocal *>::iterator it;
    ControladorEmpleado* cont_empleado = ControladorEmpleado::getInstance();
    for(it = this->ventasLocales.begin(); it != this->ventasLocales.end(); ++it) {
        //Si la venta esta facturada chequeo que el nombre del mozo de la venta
        //es igual al nombre del mozo que tiene codigo num_mozo
        if(it->second->estaFacturada()) {
            Factura* factura = it->second->getFactura();
            FacturaLocal* factura_local = dynamic_cast<FacturaLocal*>(factura);
            if(factura_local != nullptr)
                if(factura_local->getNombreMozo() == cont_empleado->getNombreMozo(num_mozo))
                    ret_objeto[factura_local->getCodigo()] = factura;
        }
    }
    map<int, Factura*>::iterator it_factura;
    //Recorro mi conjunto de objetos y creo los data values para agregarlos
    //a la coleccion a retornar
    for(it_factura = ret_objeto.begin(); it_factura != ret_objeto.end(); ++it_factura) {
        Factura* factura = it_factura->second;
        DtFactura dtfactura = factura->getDatosFactura();
        ret[dtfactura.getCodigo()] = dtfactura;
    }
    return ret;
}