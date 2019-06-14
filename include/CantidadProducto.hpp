#ifndef _CANTIDADPRODUCTO_HPP
#define _CANTIDADPRODUCTO_HPP

//Archivos
#include "Producto.hpp"

class CantidadProducto {
private:
    int cantidad;
    Producto* producto;
public:
    //Constructor
    CantidadProducto(int cantidad, Producto* producto);

    //Destructor
    ~CantidadProducto();

    //Getters
    int getCantidad();
    Producto* getProducto();

    //Setters
    void setCantidad(int cantidad);

    void aumentarCantidad(int cantidad);
    bool disminuir(int cant);
    bool estaProducto(int codigo);
    DtProducto obtenerDatosProducto();
    void quitarProducto();
};

#endif
