#ifndef _DTPRODUCTOSIMPLE_HPP
#define _DTPRODUCTOSIMPLE_HPP

#include "DtProducto.hpp"

class DtProductoSimple : public DtProducto {
private:
    
public:
    //constructor y destructor
    DtProductoSimple(int codigo, string descripcion, float precio);
    ~DtProductoSimple();
};

#endif
