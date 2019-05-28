#ifndef _PRODUCTO_HPP
#define _PRODUCTO_HPP

#include "DtProducto.hpp"
using namespace std;

class Producto {
private:
    int codigo;
    string descripcion;
    float precio;
    //constructor privado porque es abstracta
    Producto(int cod, string desc, float precio);
public:
    virtual void eliminar() = 0;
    virtual DtProducto getDatosProducto();
    //destructor
    ~Producto();
};

#endif
