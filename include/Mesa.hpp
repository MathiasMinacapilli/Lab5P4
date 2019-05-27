#ifndef _MESA_HPP
#define _MESA_HPP

#include "Empleado.hpp"

using namespace std;

class Mesa{
private:
   int numero;
public:
   Mesa(/* args */);
   ~Mesa();
   bool noTieneVentas();
   bool esDelMozo(int numMozo);
   void terminarVenta();
};

#endif
