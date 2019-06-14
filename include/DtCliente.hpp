#ifndef _DTCLIENTE_HPP
#define _DTCLIENTE_HPP

//Librerias C
#include <set>
#include <string>
#include <iostream>
using namespace std;

//Archivos
#include "DtDireccion.hpp"
#include "DtActualizacion.hpp"

class DtCliente {
private:
    string telefono;
    string nombre;
    DtDireccion direccion;
    string mail;
    string clave;
    set<DtActualizacion> etapaPedidos;
public:
    //Constructor
    DtCliente(string telefono, string nombre, DtDireccion direccion, set<DtActualizacion> etapaPedidos);

    //Destructor
    ~DtCliente();

    //Getters
    string getTelefono();
    string getNombre();
    DtDireccion getDireccion();
    set<DtActualizacion> getEtapaPedidos();
};

//Sobrecarga operador cout
ostream& operator<<(ostream &, DtCliente);

#endif
