//Librerias de C
using namespace std;
#include <ctime>

//Archivos
#include "../include/VentaADomicilio.hpp"

//constructor por defecto
VentaADomicilio::VentaADomicilio(): Venta(){}

//constructor por parametros
VentaADomicilio::VentaADomicilio(int numero, float descuento, Factura* factura, Etapa* etapa, IObserverActualizaciones *obs, Cliente *miCliente, Repartidor *miRepartidor) : Venta (numero, descuento, factura) {
  this -> etapa = etapa;
  this -> miCliente = miCliente;
  this -> miRepartidor = miRepartidor;
  this -> miObservador = obs;
}

//destructor
VentaADomicilio::~VentaADomicilio() {
}

//getters
vector<DtActualizacion> VentaADomicilio::getActualizaciones() const{
  return this -> actualizaciones;
}

Cliente* VentaADomicilio::getCliente(){
  return this -> miCliente;
}

Repartidor *VentaADomicilio::getRepartidor(){
  return this->miRepartidor;
}

DtFactura* VentaADomicilio::facturar() {
    map<int, CantidadProducto*>::iterator it;
    map<int, DtProductoCantidad> datos_productos;
    int precio_sub_total = 0;
    for(it = cants_productos.begin(); it != cants_productos.end(); ++it) {
        DtProducto datos = (it->second)->getProducto()->getDatosProducto();
        int cant = (it -> second)->getCantidad();
        DtProductoCantidad prod_cant = DtProductoCantidad(datos, cant);
        datos_productos.insert(pair<int, DtProductoCantidad>(datos.getCodigo(), prod_cant));
        precio_sub_total = precio_sub_total + (((it->second)->getProducto())->getPrecio()*cant);
        //Aumentar la cantidad de vendidos en el producto. Lo aumento la cantidad del producto_cantidad
        (it->second)->getProducto()->aumentarCantidadVendidos(it->second->getCantidad());
    }
    int precio_total = 0;
    if (this -> getDescuento() != 0) { 
        precio_total = precio_sub_total * (1 - this->getDescuento() / 100) * (1 + valor_iva / 100);
    } else {
        precio_total = precio_sub_total * (1 + valor_iva / 100);
    }
    time_t t = time(0);
    tm* now = localtime(&t);
    DtFechaYHora fecha_y_hora = DtFechaYHora(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900, now->tm_hour, now->tm_min, now->tm_sec);
    Factura* factura = new Factura(this->getNumero(), fecha_y_hora, datos_productos, valor_iva, this->getDescuento(), precio_sub_total, precio_total);
    this->setFactura(factura);
    if (miRepartidor != nullptr) {
        DtFactura* res = new DtFacturaDomicilio(this->getNumero(), fecha_y_hora, datos_productos, valor_iva, this->getDescuento(), precio_sub_total, precio_total, this -> miRepartidor -> getNombre(), this -> miRepartidor -> getTransporte());
        fflush(stdout);
        //genero actualizacion inicial
        EtapaPedido etapa_pedido = pedido;
        map<int, DtProductoCantidad> info_productos;
        map<int, CantidadProducto *>::iterator it;
        for (it = this->cants_productos.begin(); it != this->cants_productos.end(); ++it){
          DtProducto datos = it->second->getProducto()->getDatosProducto();
          DtProductoCantidad  prod_cant = DtProductoCantidad(datos, it->second->getCantidad());
          info_productos[datos.getCodigo()] = prod_cant;
        }
        DtActualizacion actuailizacion_inicial = DtActualizacion(res->getFechaYHora(), this->miCliente->getNombre(), this->miCliente->getTelefono(), this->miRepartidor->getNombre(), info_productos, etapa_pedido);
        
        //si tengo observador, lo notifico
        if (this->miObservador != nullptr)
          this->miObservador->notificar(actuailizacion_inicial);
        //guardo la actualizacion en mi coleccion de actualizaciones
        this -> actualizaciones.push_back(actuailizacion_inicial);

        //devuelvo Dtfactura
        return res;
    } else {
        DtFactura* res_domicilio_sin_repartidor = new DtFactura(this->getNumero(), fecha_y_hora, datos_productos, valor_iva, this->getDescuento(), precio_sub_total, precio_total);
        //construyo actualizacion de la venta
        EtapaPedido etapa_recibido = recibido;
        map<int, DtProductoCantidad> info_prods;
        map<int, CantidadProducto *>::iterator it_recibido;
        for (it_recibido = this->cants_productos.begin(); it_recibido != this->cants_productos.end(); ++it_recibido){
          DtProducto info = it_recibido->second->getProducto()->getDatosProducto();
          DtProductoCantidad  cant = DtProductoCantidad(info, it_recibido->second->getCantidad());
          info_prods[info.getCodigo()] = cant;
        }
        DtActualizacion actualizacion = DtActualizacion(res_domicilio_sin_repartidor->getFechaYHora(), this->miCliente->getNombre(), this->miCliente->getTelefono(), "Sin repartidor", info_prods, etapa_recibido);
        
        //si tengo observador, lo notifico
        if (this->miObservador != nullptr)
          this->miObservador->notificar(actualizacion);
        //guardo la actualizacion en mi coleccion de actualizaciones
        this -> actualizaciones.push_back(actualizacion);

        //devuelvo dtFactura
        return res_domicilio_sin_repartidor;
    }
}
//Operaciones patron State
void VentaADomicilio::avanzarEtapaVenta() {
	EtapaPedido etapa_pedido;
	Etapa *aux = etapa -> avanzarEtapa(etapa_pedido);
	//si cambio de etapa
	if (aux != nullptr){
		//avanzo etapa
  		delete this->etapa;
  		this->etapa = aux;

  		//obtengo fecha y hora actuales
  		time_t t = time(0);
    	tm* now = localtime(&t);
    	DtFechaYHora fecha_y_hora = DtFechaYHora(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900, now->tm_hour, now->tm_min, now->tm_sec);

    	//construyo coleccion de DtProductoCantidad con la informacion de los productos asociados a la venta
    	map<int, DtProductoCantidad> info_productos;
    	map<int, CantidadProducto *>::iterator it;
    	for (it = this->cants_productos.begin(); it != this->cants_productos.end(); ++it){
    		DtProducto datos = it->second->getProducto()->getDatosProducto();
    		DtProductoCantidad	prod_cant = DtProductoCantidad(datos, it->second->getCantidad());
    		info_productos[datos.getCodigo()] = prod_cant;
    	}

    	//construyo actualizacion
      DtActualizacion actualizacion = DtActualizacion(fecha_y_hora, this->miCliente->getNombre(), this->miCliente->getTelefono(), this->miRepartidor->getNombre(), info_productos, etapa_pedido);
      
      //si tengo observador, lo notifico
      if (this->miObservador != nullptr)
    		this->miObservador->notificar(actualizacion);
      //guardo la actualizacion en mi coleccion de actualizaciones
      this -> actualizaciones.push_back(actualizacion);
    }
}

void VentaADomicilio::cancelarVenta() {
  Etapa *aux = etapa -> cancelar();
  //si cambio etapa
  if (aux != nullptr){
    //avanzo etapa
    delete this->etapa;
    this->etapa = aux;

    EtapaPedido etapa_pedido = cancelado;

    //obtengo fecha y hora actuales
    time_t t = time(0);
    tm* now = localtime(&t);
    DtFechaYHora fecha_y_hora = DtFechaYHora(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900, now->tm_hour, now->tm_min, now->tm_sec);

    //construyo coleccion de DtProductoCantidad con la informacion de los productos asociados a la venta
    map<int, DtProductoCantidad> info_productos;
    map<int, CantidadProducto *>::iterator it;
    for (it = this->cants_productos.begin(); it != this->cants_productos.end(); ++it){
      DtProducto datos = it->second->getProducto()->getDatosProducto();
      DtProductoCantidad  prod_cant = DtProductoCantidad(datos, it->second->getCantidad());
      info_productos[datos.getCodigo()] = prod_cant;
    }

    //construyo actualizacion
    DtActualizacion actualizacion = DtActualizacion(fecha_y_hora, this->miCliente->getNombre(), this->miCliente->getTelefono(), this->miRepartidor->getNombre(), info_productos, etapa_pedido);
    if (this->miObservador != nullptr)
      this->miObservador->notificar(actualizacion);
    this->actualizaciones.push_back(actualizacion);
  }
}

//PATRON OBSERVER
void VentaADomicilio::setObservador(IObserverActualizaciones *observador){
  this->miObservador = observador;
}
    
void VentaADomicilio::borrarObservador(){
  this->miObservador = nullptr;
}

//FUNCION USADA UNICAMENTE PARA CARGAR DATOS DE PRUEBA
void VentaADomicilio::agregarActualizacion(DtActualizacion dt_Act){
  this->actualizaciones.push_back(dt_Act);
  if (this->miObservador != nullptr){
    this->miObservador->notificar(dt_Act);
  }
}
