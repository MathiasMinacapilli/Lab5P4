#ifndef _DTREPARTIDOR_HPP
#define _DTREPARTIDOR_HPP

#include "Transporte.hpp";

class DtRepartidor {
private:
    Transporte medioTransporte;
public:
    DtRepartidor(Transporte medioTransporte);
    ~DtRepartidor();
};



#endif