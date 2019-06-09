#ifndef _DTPRODUCTOCANTIDAD_HPP
#define _DTPRODUCTOCANTIDAD_HPP

//Librerias de C
#include <ostream>

//Archivos
#include "DtProducto.hpp"

class DtProductoCantidad{
private:
    DtProducto producto;
    int cantidad;
public:
	DtProductoCantidad();
    DtProductoCantidad(DtProducto producto, int cantidad);
    DtProducto getProducto();
    int getCantidad();
    ~DtProductoCantidad();
};

ostream &operator<< (ostream&, DtProductoCantidad);

#endif
