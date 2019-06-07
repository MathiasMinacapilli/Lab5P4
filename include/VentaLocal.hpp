#ifndef _VENTALOCAL_HPP
#define _VENTALOCAL_HPP

//Librerias de C
#include <set>
using namespace std;

//Archivos
#include "Venta.hpp"
#include "Producto.hpp"

class VentaLocal : public Venta {
public:
    VentaLocal(int numero, float descuento, Factura* factura);
    ~VentaLocal();
};

#endif