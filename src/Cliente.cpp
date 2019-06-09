//Librerias de C
#include <set>
#include <string>
using namespace std;

//Archivos
#include "../include/Cliente.hpp"

void Cliente::suscribirse() {}
void Cliente::bajaSuscripcion() {}
void Cliente::consultarPedidos() {}
void Cliente::notificar(DtActualizacion actualizacion) {}

//Constructor por defecto
Cliente::Cliente(){}

//constructor por parametros
Cliente::Cliente(int telefono, string nombre, DtDireccion direccion, set<DtActualizacion> etapaPedidos){
	this->telefono = telefono;
	this->nombre = nombre;
	this->direccion = direccion;
	this->etapaPedidos = etapaPedidos;
}
