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
    string telefono;
    DtDireccion direccion;
    set<DtActualizacion> etapaPedidos;
public:
	Cliente();
	Cliente(string telefono, string nombre, DtDireccion direccion, set<DtActualizacion> etapaPedidos);
    string getTelefono();
    void suscribirse();
    void bajaSuscripcion();
    void consultarPedidos();
    void notificar(DtActualizacion actualizacion);
};

#endif
