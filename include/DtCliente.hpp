#ifndef _DTCLIENTE_HPP
#define _DTCLIENTE_HPP

#include "DtDireccion.hpp"

using namespace std;


class DtCliente{
private:
   string telefono;
   string nombre;
   DtDireccion direccion;
   //set(DtActualizacion) etapaPedidos
public:
    DtCliente(/* args */);
    ~DtCliente();
};

#endif
