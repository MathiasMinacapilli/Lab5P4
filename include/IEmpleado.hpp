#ifndef _IEMPLEADO_HPP
#define _IEMPLEADO_HPP

//Archivos
#include "Mozo.hpp"
#include "Repartidor.hpp"

class IEmpleado {
protected:
    IEmpleado();
public:
    virtual Mozo *getMozo(int num_mozo);
    virtual ~IEmpleado() {}; // virtual y vacío
};

#endif
