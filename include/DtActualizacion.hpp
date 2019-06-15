#ifndef _DTACTUALIZACION_HPP
#define _DTACTUALIZACION_HPP

//Librerias de C
#include <set>
#include <map>
#include <string>
#include <iostream>
using namespace std;

//Archivos
#include "DtFechaYHora.hpp"
#include "DtProductoCantidad.hpp"
#include "EtapaPedido.hpp"

class DtActualizacion {
private:
    DtFechaYHora fechaYHora;
    string nombre;
    string telefono;
    string nombre_repartidor;
    map<int, DtProductoCantidad> datosProductos;
    EtapaPedido etapaActual;
public:
    //Constructor
    DtActualizacion(DtFechaYHora fechaYHora, string nombre, string telefono, string nombre_repartidor, map<int, DtProductoCantidad> datosProductos, EtapaPedido etapaActual);

    //Destructor
    ~DtActualizacion();

    //Getters
    DtFechaYHora getFechaYHora() const;
    string getNombre();
    string getTelefono();
    string getNombreRepartidor();
    map<int, DtProductoCantidad> getDatosProductos() const;
    EtapaPedido getEtapaActual();

    //Sobrecarga de operador de comparación
    bool operator<(const DtActualizacion&) const;
};

ostream &operator<< (ostream&, DtActualizacion);

#endif
