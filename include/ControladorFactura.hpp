#ifndef _CONTROLADORFACTURA_HPP
#define _CONTROLADORFACTURA_HPP

//Librerias de C
#include <set>
using namespace std;

//Archivos
#include "IFactura.hpp"

class ControladorFactura : public IFactura {
public:
    void crearFactura(int codigo, set<DtProducto> datosProductos);
};

#endif
