#ifndef _CLIENTE_HPP
#define _CLIENTE_HPP

//Librerias de C
#include <set>
#include <vector>
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
    vector<DtActualizacion> etapaPedidos;
public:
    //constructor
	Cliente();
	Cliente(string telefono, string nombre, DtDireccion direccion, set<DtActualizacion> etapaPedidos);
    //getters
    string getTelefono();
    string getNombre();
    DtDireccion getDireccion();

    //patron observer
    void suscribirse();
    void bajaSuscripcion();
    vector<DtActualizacion> consultarPedidos();
    void notificar(DtActualizacion actualizacion);
};

#endif
