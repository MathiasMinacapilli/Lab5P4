#ifndef _DTPRODUCTOCANTIDAD_HPP
#define _DTPRODUCTOCANTIDAD_HPP

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

#endif
