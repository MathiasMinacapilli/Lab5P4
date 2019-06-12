//Librerias de C
using namespace std;
#include <ctime>

//Archivos
#include "../include/VentaADomicilio.hpp"

VentaADomicilio::VentaADomicilio(int numero, float descuento, Factura* factura, Etapa* etapa) : Venta (numero, descuento, factura) {
  this -> etapa = etapa;
}

VentaADomicilio::~VentaADomicilio() {
}

set<DtActualizacion> VentaADomicilio::getActualizaciones() const{
  return this -> actualizaciones;
}

void VentaADomicilio::avanzarEtapaVenta(string nombre_repartidor) {
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
    	DtActualizacion actualizacion = DtActualizacion(fecha_y_hora, this->miCliente->getNombre(), this->miCliente->getTelefono(), info_productos, nombre_repartidor, etapa_pedido);
    	if (this->miObservador != nullptr)
    		this->miObservador->notificar(actualizacion);
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
      info_productos[datos->getCodigo()] = prod_cant;
    }

    //construyo actualizacion
    DtActualizacion actualizacion = DtActualizacion(fecha_y_hora, this->miCliente->getNombre(), this->miCliente->getTelefono(), info_productos, nombre_repartidor, etapa_pedido);
    if (this->miObservador != nullptr)
      this->miObservador->notificar(actualizacion);
  }
}
