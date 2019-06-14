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
    //Constructor
	DtProductoCantidad();
    DtProductoCantidad(DtProducto producto, int cantidad);

    //Destructor
    ~DtProductoCantidad();

    //Getters
    DtProducto getProducto();
    int getCantidad();
};

ostream &operator<< (ostream&, DtProductoCantidad);

#endif
