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



map<int, DtProducto> ControladorProducto::getProductosDisponibles(){
	map<int, DtProducto> resultado;
	map<int, ProductoSimple *>::iterator it_prod_simp;
	for(it_prod_simp = this->productosSimples.begin(); it_prod_simp != this->productosSimples.end(); ++it_prod_simp)
		resultado[(it_prod_simp->second)->getCodigo()] = (it_prod_simp->second)->getDatosProducto();
	map<int, Menu *>::iterator it_menu;
	for(it_menu = this->menus.begin(); it_menu != this->menus.end(); ++it_menu)
		resultado[(it_menu->second)->getCodigo()] = (it_menu->second)->getDatosProducto();
	return resultado;
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


void ControladorEmpleado::ingresarRepartidor(){
	this->ultimo_id++;
	Repartidor *nuevo_repartidor = new Repartidor(this->ultimo_id, this->nombre_recordado, this->transporte_recordado);
	//agrego repartidor a la coleccion de repartidores
	this->repartidores[nuevo_repartidor->getNumero()] = nuevo_repartidor;
	//"se olvida" del nombre recordado
	this->nombre_recordado = ' ';
}

void ControladorEmpleado::cancelarRepartidor(){
	//"se olvida" del nombre recordado
	this->nombre_recordado = ' ';
}

void ControladorEmpleado::ingresarMozo(){
	this->ultimo_id++;
	Mozo *nuevo_mozo = new Mozo(this->ultimo_id, this->nombre_recordado);
	//agrego mozo a la coleccion de mozo
	this->mozos[nuevo_mozo->getNumero()] = nuevo_mozo;
	//"se olvida" del nombre recordado
	this->nombre_recordado = ' ';

}
void ControladorEmpleado::cancelarMozo(){
	//"se olvida" del nombre recordado
	this->nombre_recordado = ' ';
}

ControladorEmpleado::~ControladorEmpleado(){}
