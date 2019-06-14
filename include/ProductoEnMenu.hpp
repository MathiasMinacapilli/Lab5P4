#ifndef _PRODUCTOENMENU_HPP
#define _PRODUCTOENMENU_HPP

//Librerias de C
using namespace std;

//Archivos
#include "ProductoSimple.hpp"
#include "DtProductoSimple.hpp"

class ProductoEnMenu {
private:
    int cantidad;
    ProductoSimple *producto;
public:
    bool estaProducto(int cod);
    void aumentarCantidad(int cant);

    //Getters
    int getCantidad();
    ProductoSimple* getProducto();

    //Constructor
    ProductoEnMenu(int cantidad, ProductoSimple *producto);

    //Destructor
    ~ProductoEnMenu();
};

#endif
