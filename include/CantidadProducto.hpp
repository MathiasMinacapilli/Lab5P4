#ifndef _CANTIDADPRODUCTO_HPP
#define _CANTIDADPRODUCTO_HPP

#include "DtProducto.hpp"

using namespace std;

class CantidadProducto{
private:
   int cantidad;
public:
   CantidadProducto(/* args */);
   ~CantidadProducto();
   void aumentarCantidad(int cantidad);
   bool disminuir(int cant);
   bool estaProducto(int codigo);
   DtProducto obtenerDatosProducto();
   void quitarProducto();
};

#endif
