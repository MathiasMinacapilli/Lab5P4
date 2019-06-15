#ifndef _DTREPARTIDOR_HPP
#define _DTREPARTIDOR_HPP

//Librerias de C
#include <iostream>

//Archivos
#include "Transporte.hpp"
#include "DtEmpleado.hpp"


class DtRepartidor : public DtEmpleado {
private:
    Transporte medioTransporte;
public:
    //Constructor
    DtRepartidor();
    DtRepartidor(int numero, string nombre, Transporte medioTransporte);

    //Destructor
    ~DtRepartidor();

    //Getters
    Transporte getTransporteRepartidor();
};

//Sobrecarga operador cout
ostream& operator<<(ostream &, DtRepartidor);

#endif
