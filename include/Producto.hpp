#ifndef _PRODUCTO_HPP
#define _PRODUCTO_HPP

#include "DtProducto.hpp"
using namespace std;

class Producto {
private:
    int codigo;
    string descripcion;
    float precio;
    
protected:
    //constructor protected porque es abstracta
    Producto(int codigo, string descripcion, float precio);
public:
	//getters
	int getCodigo();
    string getDescripcion();
    float getPrecio();

    //operaciones
    virtual void eliminar() = 0;
    DtProducto getDatosProducto();

    //destructor
    ~Producto();
};

#endif
