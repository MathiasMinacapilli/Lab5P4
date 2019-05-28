#ifndef _CANTIDADPRODUCTO_HPP
#define _CANTIDADPRODUCTO_HPP

//Librerias de C
using namespace std;

//Archivos
#include "DtProducto.hpp"

class CantidadProducto{
private:
   int cantidad;
public:
   CantidadProducto(int cantidad);
   ~CantidadProducto();
   void aumentarCantidad(int cantidad);
   bool disminuir(int cant);
   bool estaProducto(int codigo);
   DtProducto obtenerDatosProducto();
   void quitarProducto();
};

#endif
