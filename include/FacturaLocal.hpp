#ifndef _FACTURALOCAL_HPP
#define _FACTURALOCAL_HPP

//Librerias de C
#include <string>
using namespace std;

//Archivos
#include "Factura.hpp"

class FacturaLocal : public Factura {
private:
    string nombreMozo;
public:
    FacturaLocal(int codigo, DtFechaYHora fechaYHora, map<int, DtProductoCantidad> productosCantidad, float iva, float descuento, float precioSubTotal, float precioTotal, string nombreMozo);
    ~FacturaLocal();
};

#endif
