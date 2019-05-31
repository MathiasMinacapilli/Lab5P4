#ifndef _DTPRODUCTOENMENU_HPP
#define _DTPRODUCTOENMENU_HPP

#include "DtProductoSimple.hpp";

class DtProductoEnMenu {
private:
    DtProductoSimple producto;
    int cantidad;
public:
    DtProductoEnMenu(DtProductoSimple producto, int cantidad);
    DtProductoSimple getProducto();
    int getCantidad();
    ~DtProductoEnMenu();
};

#endif