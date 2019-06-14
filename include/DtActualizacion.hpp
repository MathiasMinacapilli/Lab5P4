#ifndef _DTACTUALIZACION_HPP
#define _DTACTUALIZACION_HPP

//Librerias de C
#include <set>
#include <map>
#include <string>
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
    map<int, DtProductoCantidad> datosProductos;
    string nombreRepartidor;
    EtapaPedido etapaActual;
public:
    //Constructor
    DtActualizacion(DtFechaYHora fechaYHora, string nombre, string telefono, map<int, DtProductoCantidad> datosProductos, string nombreRepartidor, EtapaPedido etapaActual);

    //Destructor
    ~DtActualizacion();

    //Getters
    DtFechaYHora getFechaYHora() const;
    string getNombre();
    string getTelefono();
    map<int, DtProductoCantidad> getDatosProductos();
    string getNombreRepartidor();
    EtapaPedido getEtapaActual();

    //Sobrecarga de operador de comparación
    bool operator<(const DtActualizacion&) const;
};

#endif
