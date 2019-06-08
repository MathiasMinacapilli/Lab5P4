#ifndef _DTACTUALIZACION_HPP
#define _DTACTUALIZACION_HPP

//Librerias C
#include <set>
#include <string>
using namespace std;

//Archivos
#include "DtFechaYHora.hpp"
#include "DtProducto.hpp"
#include "Etapa.hpp"

class DtActualizacion {
private:
    DtFechaYHora fechaYHora;
    string nombre;
    int telefono;
    set<DtProducto> datosProducto;
    string nombreRepartidor;
    Etapa* etapaActual;
public:
    DtActualizacion(DtFechaYHora fechaYHora, string nombre, int telefono, set<DtProducto> datosProducto, string nombreRepartidor, Etapa* etapaActual);
    DtFechaYHora getFechaYHora() const;
    string getNombre();
    int getTelefono();
    set<DtProducto> getDatosProducto();
    string getNombreRepartidor();
    Etapa* getEtapaActual();
    bool operator<(const DtActualizacion&) const;
    ~DtActualizacion();
};


#endif
