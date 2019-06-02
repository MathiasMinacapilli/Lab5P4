#ifndef _CANTIDADPRODUCTO_HPP
#define _CANTIDADPRODUCTO_HPP

//Librerias de C
using namespace std;

//Archivos
#include "Producto.hpp"

class CantidadProducto {
private:
    int cantidad;
    Producto* producto;
public:
    // Constructor y Destructor
    CantidadProducto(int cantidad, Producto* producto);
    ~CantidadProducto();
    // Getters y Setters
    int getCantidad();
    Producto* getProducto();
    void setCantidad(int cantidad);
    
    void aumentarCantidad(int cantidad);
    bool disminuir(int cant);
    bool estaProducto(int codigo);
    DtProducto obtenerDatosProducto();
    void quitarProducto();
};

#endif
