#ifndef _PRODUCTOENMENU_HPP
#define _PRODUCTOENMENU_HPP

//Librerias de C
using namespace std;

//Archivos
#include "Producto.hpp"
#include "DtProductoSimple.hpp"

class ProductoEnMenu {
private:
    int cantidad;
    ProductoSimple *producto;
public:
    bool estaProducto(int cod);
    void aumentarCantidad(int cant);

    //getters
    int getCantidad();

    //constructor y destructor
    ProductoEnMenu(int cantidad, ProductoSimple *producto);
    ~ProductoEnMenu();
};

#endif
