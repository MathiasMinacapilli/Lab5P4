#ifndef _REPARTIDOR_HPP
#define _REPARTIDOR_HPP

//Librerias de C
#include <string>
using namespace std;

//Archivos
#include "Empleado.hpp"
#include "Transporte.hpp"

class Repartidor : public Empleado {
private:
   Transporte medioTransporte;
public:
    Repartidor(int numero, string nombre, Transporte medioTransporte);
    ~Repartidor();
    Transporte getTransporte();
};

#endif
