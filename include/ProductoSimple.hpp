#ifndef _PRODUCTOSIMPLE_HPP
#define _PRODUCTOSIMPLE_HPP

//Librerias de C
#include <string>
using namespace std;

//Archivos
#include "Producto.hpp"

class ProductoSimple : public Producto {
public:
    //Constructor
    ProductoSimple(int codigo, string descripcion, float precio);

    //Destructor
    ~ProductoSimple();

    void eliminar();

};

#endif
