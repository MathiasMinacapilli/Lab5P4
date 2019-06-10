#ifndef _DTCLIENTE_HPP
#define _DTCLIENTE_HPP

//Librerias C
#include <set>
#include <string>
#include <iostream>
using namespace std;

//Archivos
#include "DtDireccion.hpp"
#include "DtActualizacion.hpp"

class DtCliente {
private:
  int telefono;
  string nombre;
  DtDireccion direccion;
  string mail;
  string clave;
  set<DtActualizacion> etapaPedidos;
public:
  DtCliente(int telefono, string nombre, DtDireccion direccion, set<DtActualizacion> etapaPedidos);
  int getTelefono();
  string getNombre();
  DtDireccion getDireccion();
  set<DtActualizacion> getEtapaPedidos();
  ~DtCliente();
};

//sobrecarga operador cout
  ostream& operator<<(ostream &, DtCliente);

#endif
