#ifndef _PRODUCTOSIMPLE_HPP
#define _PRODUCTOSIMPLE_HPP


#include "Producto.hpp"


using namespace std;

class ProductoSimple : public Producto {
public:
    //constructor y destructor
    ProductoSimple(int codigo, string descripcion, float precio);
    ~ProductoSimple();
    
    DtProductoSimple getDatos();
    void eliminar();  

};

#endif
