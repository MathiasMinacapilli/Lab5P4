
#ifndef _PRODUCTO_HPP
#define _PRODUCTO_HPP

//Librerias de C
#include <string>
using namespace std;

//Archivos
#include "DtProductoSimple.hpp"

class Producto {
protected:
    //Atributos protected para que las subclases Menu y ProductoSimple puedan accederlos directamente
    int codigo;
    string descripcion;
    float precio;
    //Constructor protected porque es abstracta
    Producto(int codigo, string descripcion, float precio);
    int cantidadVendidos;
public:
	//Getters
	int getCodigo();
    string getDescripcion();
    float getPrecio();
    int getCantidadVendidos();

    //Destructor
    virtual ~Producto();

    virtual void eliminar() = 0;
    DtProducto getDatosProducto();
    void aumentarCantidadVendidos(int i);
};

#endif
