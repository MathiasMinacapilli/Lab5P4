#ifndef _DTPRODUCTOSIMPLE_HPP
#define _DTPRODUCTOSIMPLE_HPP

//Librerias de C
#include <string>
using namespace std;

//Archivos
#include "DtProducto.hpp"

class DtProductoSimple : public DtProducto {
public:
    //Constructor
    DtProductoSimple();
    DtProductoSimple(int codigo, string descripcion, float precio);
    DtProductoSimple(int codigo, string descripcion, float precio, int cantidadVendidos);

    //Destructor
    ~DtProductoSimple();
};

#endif
