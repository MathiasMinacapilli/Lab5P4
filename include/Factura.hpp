#ifndef _FACTURA_HPP
#define _FACTURA_HPP

//Librerias de C
#include <set>
using namespace std;

//Archivos
#include "DtFechaYHora.hpp"
#include "DtProductoCantidad.hpp"
#include "Producto.hpp"

class Factura {
private:
    int codigo;
    DtFechaYHora fechaYHora;
    set<DtProductoCantidad> productos;
    float iva;
    float descuento;
    float precioSubTotal;
    float precioTotal;
public:
    Factura(int codigo, DtFechaYHora fechaYHora, set<DtProductoCantidad> productos, float iva, float descuento, float precioSubTotal, float precioTotal);
    ~Factura();
};

#endif
