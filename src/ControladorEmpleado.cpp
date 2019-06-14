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

Repartidor* ControladorEmpleado::getRepartidorRecordado(){
	map<int, Repartidor *>::iterator it = this -> repartidores.find(numero_repartidor);
	if (it != this->repartidores.end())
		return (it -> second);
	else
		throw new invalid_argument("Error. No existe un repartidor con ese id. ");
}

void ControladorEmpleado::borrarNumero() {
    this -> numero_repartidor = 0;
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
/* Selecciona el id y el rango de fechas para obtener las ventas facturadas*/
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
	ControladorVenta *cont_venta = ControladorVenta::getInstance();
	map<int, VentaADomicilio *> ventas_repartidor = cont_venta->obtenerVentasRepartidor(this->id_repartidor_recordado);
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

//Caso de uso: Asignar automaticamente mozos a mesas
/* El método consiste en asignar PISO(Me/Mo) mesas a cada mozo (donde Me es la cantidad 
de mesas y Mo la de mozos) y el resto (de la división entera) de las mesas se 
asignan aleatoriamente a los mozos. */
map<int, DtMesasMozo> ControladorEmpleado::asignarMozosAMesas() {
	ControladorMesa* cont_mesa = ControladorMesa::getInstance();
	map<int, Mesa*> mesas = cont_mesa->getMesas();
	map<int, Mesa*>::iterator it_mesas = mesas.begin();
	map<int, Mozo *>::iterator it_mozos;
	int cant_mesas = mesas.size();
	int cant_mozos = mesas.size();
	double cant_mesas_a_asignar = floor(cant_mesas/cant_mozos);
	//Recorro la coleccion de mozos asignandole a cada mozo (en el while)
	//cant_mesas_a_asignar (que es la cuenta piso(me/mo)) mesas.
	for(it_mozos = this->mozos.begin(); it_mozos != this->mozos.end(); ++it_mozos) {
		double i = 0;
		while(i<cant_mesas_a_asignar) {
			it_mozos->second->agregarMesaAColleccion(it_mesas->second);
			++it_mesas;
			i++;
		}
	}
	//Si luego de recorrer todos los mozos y asignarle el valor cant_mesas_a_asignar
	//a cada uno aun me quedan mesas por asignar, asigno estas mesas aleatoriamente
	if(it_mesas != mesas.end()) {
		it_mozos = this->mozos.begin();
		while(it_mesas != mesas.end()) {
			it_mozos->second->agregarMesaAColleccion(it_mesas->second);
			++it_mesas;
			++it_mozos;
			if(it_mozos == this->mozos.end()) { //Para hacerlo circular
				it_mozos = this->mozos.begin();
			}
		}
	}
}

//destructor
ControladorEmpleado::~ControladorEmpleado(){}
