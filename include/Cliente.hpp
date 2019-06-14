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
    //Constructor
	Cliente();
	Cliente(string telefono, string nombre, DtDireccion direccion, vector<DtActualizacion> etapaPedidos);

    //Destructor
    ~Cliente();

    //Getters
    string getNombre();
    string getTelefono();
    DtDireccion getDireccion();

    //Patron Observer
    void suscribirse();
    void bajaSuscripcion();
    vector<DtActualizacion> consultarPedidos();
    void notificar(DtActualizacion actualizacion);
};

#endif
