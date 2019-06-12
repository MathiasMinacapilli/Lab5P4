//Librerias de C
#include <set>
#include <string>
using namespace std;

//Archivos
#include "../include/Cliente.hpp"

//Constructor por defecto
Cliente::Cliente(){}

//constructor por parametros
Cliente::Cliente(string telefono, string nombre, DtDireccion direccion, set<DtActualizacion> etapaPedidos){
	this->telefono = telefono;
	this->nombre = nombre;
	this->direccion = direccion;
	this->etapaPedidos = etapaPedidos;
}

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
void Cliente::suscribirse() {}
void Cliente::bajaSuscripcion() {}
void Cliente::consultarPedidos() {}
void Cliente::notificar(DtActualizacion actualizacion) {}
