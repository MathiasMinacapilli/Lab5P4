#ifndef _CLIENTE_HPP
#define _CLIENTE_HPP

//Librerias de C
#include <set>
#include <string>
using namespace std;

//Archivos
#include "DtActualizacion.hpp"
#include "DtDireccion.hpp"
#include "DtCliente.hpp"
#include "IObserverActualizaciones.hpp"

class Cliente : public IObserverActualizaciones{
private:
    string nombre;
    int telefono;
    DtDireccion direccion;
    set<DtActualizacion> etapaPedidos;
public:
	Cliente();
	Cliente(int telefono, string nombre, DtDireccion direccion, set<DtActualizacion> etapaPedidos);
    void suscribirse();
    void bajaSuscripcion();
    void consultarPedidos();
    void notificar(DtActualizacion actualizacion);
};

#endif
