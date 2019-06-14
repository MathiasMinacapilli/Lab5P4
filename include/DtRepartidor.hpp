#ifndef _DTREPARTIDOR_HPP
#define _DTREPARTIDOR_HPP

//Archivos
#include "Transporte.hpp"

class DtRepartidor {
private:
    Transporte medioTransporte;
public:
    //Constructor
    DtRepartidor(Transporte medioTransporte);

    //Destructor
    ~DtRepartidor();
};



#endif
