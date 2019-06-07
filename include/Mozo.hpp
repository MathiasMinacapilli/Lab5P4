#ifndef _MOZO_HPP
#define _MOZO_HPP

//Librerias de C
#include <string>
using namespace std;

//Archivos
#include "Empleado.hpp"

class Mozo : public Empleado {
private:
public:
  Mozo(int numero, string nombre);
  ~Mozo();
};

#endif
