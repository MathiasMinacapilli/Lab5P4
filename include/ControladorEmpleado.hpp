#ifndef _CONTROLADOREMPLEADO_HPP
#define _CONTROLADOREMPLEADO_HPP

//Librerias de C
#include <map>
using namespace std;

//Archivos
#include "Mozo.hpp"
#include "Repartidor.hpp"
#include "IEmpleado.hpp"


class ControladorEmpleado : public IEmpleado{
private:
	//instancia patron Singleton
	static ControladorEmpleado *instance;
	//Constructor
	ControladorEmpleado();
	//pseudoatributos que representan colecciones de empleados
	map<int, Mozo *> mozos;
	map<int, Repartidor *> repartidores;
	//atributos de memoria controlador
	string nombre_recordado;

public:
	//operacion patron Singleton
	static ControladorEmpleado *getInstance();
    //caso de uso: Alta empleado
    void IngresarNombreEmpleado(string nombre);
    set<Transporte> getTransportes();
    void seleccionarTransporte(Transporte t);
    void ingresarRepartidor();
    void cancelarRepartidor();
    void ingresarMozo();
    void cancelarMozo();
	
	Mozo *getMozo(int num_mozo);

};

#endif
