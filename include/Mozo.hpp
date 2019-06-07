#ifndef _MOZO_HPP
#define _MOZO_HPP

//Librerias de C
#include <string>
using namespace std;

//Archivos
#include "Empleado.hpp"
#include "Mesa.hpp"

class Mozo : public Empleado {
private:
  map<int, *Mesa> mesasMozo;
public:
  Mozo(int numero, string nombre, map<int, *Mesa> mesasMozo);
  ~Mozo();
  map<int, *Mesa> getMesasMozo();
};

#endif
