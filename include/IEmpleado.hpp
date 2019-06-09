#ifndef _IEMPLEADO_HPP
#define _IEMPLEADO_HPP

//Librerias de C
#include <string>
#include <set>
using namespace std;

//Archivos
#include "Mozo.hpp"
#include "Repartidor.hpp"
#include "Transporte.hpp"

class IEmpleado {
protected:
    //constructor protected porque es abstracta
    IEmpleado();
public:
    virtual Mozo *getMozo(int num_mozo) = 0;
    virtual void ingresarNombreEmpleado(string nombre) = 0;
    virtual set<Transporte> getTransportes() = 0;
    virtual void seleccionarTransporte(Transporte t) = 0;
    virtual void ingresarRepartidor() = 0;
    virtual void cancelarRepartidor() = 0;
    virtual void ingresarMozo() = 0;
    virtual void cancelarMozo() = 0;

    //destructor
    virtual ~IEmpleado(); // virtual y vacío
};

#endif
