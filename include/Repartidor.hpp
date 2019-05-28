#ifndef _REPARTIDOR_HPP
#define _REPARTIDOR_HPP

#include "Empleado.hpp"
#include "Transporte.hpp"

using namespace std;

class Repartidor : public Empleado {
private:
   Transporte medioTransporte;
public:
    Repartidor(Transporte medioTransporte);
    ~Repartidor();
};

#endif
