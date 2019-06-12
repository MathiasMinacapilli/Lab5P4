//Archivos
#include "../include/ControladorEmpleado.hpp"

ControladorEmpleado *ControladorEmpleado::instance = nullptr;

ControladorEmpleado::ControladorEmpleado(){
	this->ultimo_id = 0;
}

ControladorEmpleado *ControladorEmpleado::getInstance(){
	if (instance == nullptr)
		instance = new ControladorEmpleado();
	return instance;
}

Mozo *ControladorEmpleado::getMozo(int num_mozo){
	map<int, Mozo*>::iterator it = this->mozos.find(num_mozo);
	if (it != mozos.end())
		return it->second;
	else
		throw new invalid_argument("Error. No existe mozo con ese numero");
}

map<int, Repartidor*> ControladorEmpleado::getRepartidoresDisponibles() {
	map<int, Repartidor*> res;
	map<int, Repartidor *>::iterator it;
	for(it = repartidores.begin(); it != repartidores.end(); ++it)
		res[(it->second) -> getNumero()] = (it -> second);
	return res;
}

//ALTA EMPLEADO

void ControladorEmpleado::ingresarNombreEmpleado(string nombre){
	this->nombre_recordado = nombre;
}

set<Transporte> ControladorEmpleado::getTransportes(){
	Transporte t1, t2, t3;
	t1 = Bici;
	t2 = Moto;
	t3 = Pie;
	set<Transporte> transportes;
 	transportes.insert(t1);
 	transportes.insert(t2);
 	transportes.insert(t3);
 	return transportes;
}

void ControladorEmpleado::seleccionarTransporte(Transporte t){
	this->transporte_recordado = t;
}

void ControladorEmpleado::seleccionarRepartidor(int numero_repartidor) {
	this -> numero_repartidor = numero_repartidor;
}


int ControladorEmpleado::ingresarRepartidor(){
	this->ultimo_id++;
	Repartidor *nuevo_repartidor = new Repartidor(this->ultimo_id, this->nombre_recordado, this->transporte_recordado);
	//agrego repartidor a la coleccion de repartidores
	this->repartidores[nuevo_repartidor->getNumero()] = nuevo_repartidor;
	//"se olvida" del nombre recordado
	this->nombre_recordado = ' ';
	return nuevo_repartidor->getNumero();
}

void ControladorEmpleado::cancelarRepartidor(){
	//"se olvida" del nombre recordado
	this->nombre_recordado = ' ';
}

int ControladorEmpleado::ingresarMozo(){
	this->ultimo_id++;
	Mozo *nuevo_mozo = new Mozo(this->ultimo_id, this->nombre_recordado);
	//agrego mozo a la coleccion de mozo
	this->mozos[nuevo_mozo->getNumero()] = nuevo_mozo;
	//"se olvida" del nombre recordado
	this->nombre_recordado = ' ';
	return nuevo_mozo->getNumero();

}
void ControladorEmpleado::cancelarMozo(){
	//"se olvida" del nombre recordado
	this->nombre_recordado = ' ';
}

//Caso de uso: Ventas de un Mozo
/* Retorna un set de int que contienen todos los id de los mozos */
set<int> ControladorEmpleado::getIds() {
	set<int> ret;
	map<int, Mozo*>::iterator it;
	for(it = this->mozos.begin(); it != this->mozos.end(); ++it)
		ret.insert((it->second)->getNumero());
	return ret;
}
/* Selecciona el id y el rango de fechas para obtener las ventas facturadas 
Chequeo de fechas??????????????????????*/
void ControladorEmpleado::seleccionarIdyFechas(int id, DtFecha fecha_ini, DtFecha fecha_fin) {
	this->id_mozo_recordado = id;
	this->fecha_ini_recordada = fecha_ini;
	this->fecha_fin_recordada = fecha_fin;
}
/* Retorna una coleccion de DtFactura que representa las ventas facturadas
asociadas al mozo que tiene el id que se selecciono */
map<int, DtFactura> ControladorEmpleado::getVentasFacturadas() {
	map<int, DtFactura> res;
	return res;
}

//MODIFICAR ETAPA PEDIDO
void ControladorEmpleado::ingresarIdRepartidor(int id){
	map<int, Repartidor *>::iterator it = this->repartidores.find(id);
	if (it != this->repartidores.end()){
		this -> id_repartidor_recordado = id;
	}
	else throw new invalid_argument("Error. No existe un repartidor con ese id. ");
}

map<int, DtDireccion> ControladorEmpleado::getVentasRepartidor(){
	Repartidor *repartidor = this->repartidores[this->id_repartidor_recordado];
	map<int, DtDireccion> resultado;
	map<int, VentaADomicilio *> ventas_repartidor = repartidor -> getVentas();
	map<int, VentaADomicilio *>::iterator it; 
	for (it = ventas_repartidor.begin(); it != ventas_repartidor.end(); ++it){
		DtDireccion dir = it->second->getCliente()->getDireccion();
		int numero = it->second->getNumero();
		resultado[numero] = dir;
	}
	return resultado;
}

void ControladorEmpleado::ingresarNumeroPedido(int nro){
	this -> pedido_recordado = nro;
}

void ControladorEmpleado::avanzarEtapaPedido(){
	Repartidor *repartidor = this->repartidores[this->id_repartidor_recordado];
	map<int, VentaADomicilio *> ventas_repartidor = repartidor -> getVentas();
	VentaADomicilio *venta = ventas_repartidor[this->pedido_recordado];
	venta->avanzarEtapaVenta(repartidor->getNombre());
}

void ControladorEmpleado::cancelarPedido(){
	Repartidor *repartidor = this->repartidores[this->id_repartidor_recordado];
	map<int, VentaADomicilio *> ventas_repartidor = repartidor -> getVentas();
	VentaADomicilio *venta = ventas_repartidor[this->pedido_recordado];
	venta->cancelarVenta(repartidor->getNombre());
}

//destructor
ControladorEmpleado::~ControladorEmpleado(){}
