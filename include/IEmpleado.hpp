#ifndef _IEMPLEADO_HPP
#define _IEMPLEADO_HPP

//Librerias de C

using namespace std;

//Archivos
#include "Mozo.hpp"
#include "Repartidor.hpp"


class IEmpleado {
public:
    virtual Mozo getMozo(int num_mozo);
    ~IEmpleado() {};
};

#endif
