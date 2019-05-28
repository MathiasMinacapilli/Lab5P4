#ifndef _DTFACTURA_HPP
#define _DTFACTURA_HPP

//Archivos
#include "DtFechaYHora.hpp";
#include "DtProductoCantidad.hpp";


class DtFactura {
private:
    int codigo;
    DtFechaYHora fechaYHora;
    DtProductoCantidad productos;
    float iva;
    float descuento;
    float precioSubTotal;
    float precioTotal;
public:
    
};

#endif