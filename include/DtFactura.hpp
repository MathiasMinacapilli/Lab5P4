#ifndef _DTFACTURA_HPP
#define _DTFACTURA_HPP

//Librerias de C
#include <map>

//Archivos
#include "DtFechaYHora.hpp"
#include "DtProductoCantidad.hpp"

class DtFactura {
private:
    int codigo;
    DtFechaYHora fechaYHora;
    map<int, DtProductoCantidad> productos;
    float iva;
    float descuento;
    float precioSubTotal;
    float precioTotal;
public:
    DtFactura();    
    DtFactura(int codigo, DtFechaYHora fechaYHora, map<int, DtProductoCantidad> productos, float iva, float descuento, float precioSubTotal, float precioTotal);
    int getCodigo();
    DtFechaYHora getFechaYHora();
    map<int, DtProductoCantidad> getProductos();
    float getIva();
    float getDescuento();
    float getPrecioSubTotal();
    float getPrecioTotal();
    ~DtFactura();
};

#endif