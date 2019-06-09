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
	//contador de numeros de empleados
	int ultimo_id;
	//atributos de memoria controlador
	string nombre_recordado;
	int numero_repartidor;
	Transporte transporte_recordado;

public:
	//operacion patron Singleton
	static ControladorEmpleado *getInstance();
    //caso de uso: Alta empleado
    void ingresarNombreEmpleado(string nombre);
    set<Transporte> getTransportes();
	map<int, Repartidor*> getRepartidoresDisponibles();
    void seleccionarTransporte(Transporte t);
	void seleccionarRepartidor(int numero_repartidor);
    void ingresarRepartidor();
    void cancelarRepartidor();
    void ingresarMozo();
    void cancelarMozo();

	Mozo *getMozo(int num_mozo);

	~ControladorEmpleado();

};

#endif
