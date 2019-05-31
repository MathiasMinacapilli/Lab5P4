#ifndef _PRODUCTO_HPP
#define _PRODUCTO_HPP

#include "Producto.hpp"

using namespace std;

class ProductoEnMenu {
private:
    int cantidad;
    ProductoSimple *producto;
public:
    bool estaProducto(int cod);
    
    //constructor y destructor
    ProductoEnMenu(int cantidad, ProductoSimple *producto);
    ~ProductoEnMenu();
};

#endif
