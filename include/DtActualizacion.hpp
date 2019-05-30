#ifndef _DTACTUALIZACION_HPP
#define _DTACTUALIZACION_HPP

//Librerias C
#include <set>
using namespace std;

//Archivos
#include "DtFechaYHora.hpp";
#include "DtProducto.hpp";
#include "Etapa.hpp";

class DtActualizacion {
private:
    DtFechaYHora fechaYHora;
    string nombre;
    string telefono;
    set<DtProducto> datosProducto;
    string nombreRepartidor;
    Etapa* etapaActual;
public:
    DtActualizacion(DtFechaYHora fechaYHora, string nombre, string telefono, set<DtProducto> datosProducto, string nombreRepartidor, Etapa* etapaActual);
    DtFechaYHora getFechaYHora();
    string getNombre();
    string getTelefono();
    set<DtProducto> getDatosProducto();
    string getNombreRepartidor();
    Etapa* getEtapaActual();
    ~DtActualizacion();
};


#endif