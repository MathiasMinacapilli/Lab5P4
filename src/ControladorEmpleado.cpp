//Archivos
#include "../include/ControladorEmpleado.hpp"

ControladorEmpleado::ControladorEmpleado(){}

ControladorEmpleado *ControladorEmpleado::getInstance(){
	if (instance == nullptr)
		instance = new ControladorEmpleado();
	return instance; 
}

void ControladorEmpleado::IngresarNombreEmpleado(string nombre){
	this->nombre_recordado = nombre;
}
    
set<Transporte> ControladorEmpleado::getTransportes(){
	Transporte t1, t2, t3;
	t1 = bici;
	t2 = moto;
	t3 = pie;
	set<Transporte> transportes;
 	transportes.insert(t1);
 	transportes.insert(t2);
 	transportes.insert(t3);
 	return transportes;


}

void seleccionarTransporte(Transporte t);
void ingresarRepartidor();
void cancelarRepartidor();
void ingresarMozo();
void cancelarMozo();

