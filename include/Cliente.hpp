#ifndef _CLIENTE_HPP
#define _CLIENTE_HPP

//Librerias de C
#include <set>
#include <string>
using namespace std;

//Archivos
#include "DtActualizacion.hpp"
#include "DtDireccion.hpp"
#include "IObserverActualizaciones.hpp"

class Cliente : public IObserverActualizaciones{
private:
    string nombre;
    int telefono;
    DtDireccion direccion;
    string mail;
    string clave;
    set<DtActualizacion> etapaPedidos;
public:
    void suscribirse();
    void bajaSuscripcion();
    void consultarPedidos();
    void notificar(DtActualizacion actualizacion);
};

#endif
