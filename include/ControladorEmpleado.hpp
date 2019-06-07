#ifndef _CONTROLADOREMPLEADO_HPP
#define _CONTROLADOREMPLEADO_HPP

//Librerias de C
#include <map>
using namespace std;

//Archivos
#include "Mozo.hpp"
#include "Repartidor.hpp"


class ControladorEmpleado : public IEmpleado{
private:
	static ControladorEmpleado *instance;
	ControladorEmpleado();
	map<int, Mozo *> mozos;
	map<int, Repartidor *> repartidores;

public:
	static ControladorEmpleado getInstance();
    virtual Mozo getMozo(int num_mozo);
};

#endif
