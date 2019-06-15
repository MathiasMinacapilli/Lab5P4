//Librerias de C
#include <set>
#include <string>
#include <algorithm>
using namespace std;

//Archivos
#include "../include/Cliente.hpp"
#include "../include/ControladorVenta.hpp"

//Constructor por defecto
Cliente::Cliente(){}

//constructor por parametros
Cliente::Cliente(string telefono, string nombre, DtDireccion direccion, vector<DtActualizacion> etapaPedidos){
	this->telefono = telefono;
	this->nombre = nombre;
	this->direccion = direccion;
	this->etapaPedidos = etapaPedidos;
}

Cliente::~Cliente() {}

//getters
string Cliente::getTelefono(){
	return this->telefono;
}

string Cliente::getNombre(){
	return this->nombre;
}

DtDireccion Cliente::getDireccion(){
	return this->direccion;
}

//patron observer
void Cliente::suscribirse() {
	ControladorVenta *cont_venta = ControladorVenta::getInstance();
	cont_venta -> suscribirCliente(this->telefono);
}

void Cliente::bajaSuscripcion() {
	ControladorVenta *cont_venta = ControladorVenta::getInstance();
	cont_venta -> desSuscribirCliente(this->telefono);
}


vector<DtActualizacion> Cliente::consultarPedidos() {
	vector<DtActualizacion> res = this -> etapaPedidos;
	std::sort(res.begin(), res.end());
	return res;
}
void Cliente::notificar(DtActualizacion actualizacion) {
	this -> etapaPedidos.push_back(actualizacion);
}
