#ifndef _PRODUCTOSIMPLE_HPP
#define _PRODUCTOSIMPLE_HPP

//Librerias de C
using namespace std;
#include <string>

//Archivos
#include "Producto.hpp"

class ProductoSimple : public Producto {
public:
    //constructor y destructor
    ProductoSimple(int codigo, string descripcion, float precio);
    ~ProductoSimple();
 
    void eliminar();  

};

#endif
