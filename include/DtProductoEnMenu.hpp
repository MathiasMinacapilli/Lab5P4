#ifndef _DTPRODUCTOENMENU_HPP
#define _DTPRODUCTOENMENU_HPP

//Archivos
#include "DtProductoSimple.hpp"

class DtProductoEnMenu {
private:
    DtProductoSimple producto;
    int cantidad;
public:
    //Constructor
    DtProductoEnMenu();
    DtProductoEnMenu(DtProductoSimple producto, int cantidad);

    //Destructor
    ~DtProductoEnMenu();

    //Getters
    DtProductoSimple getProducto();
    int getCantidad();
};

#endif
