#ifndef _FACTURADOMICILIO_HPP
#define _FACTURADOMICILIO_HPP

//Librerias de C
using namespace std;
#include <string>

//Archivos
#include "Factura.hpp"
#include "Transporte.hpp"

class FacturaDomicilio: public Factura {
private:
    string nombreRepartidor;
    Transporte transporte;
public:
    FacturaDomicilio(int codigo, DtFechaYHora fechaYHora, set<DtProductoCantidad> productos, float iva, float descuento, float precioSubTotal, float precioTotal, string nombreRepartidor, Transporte transporte);
    ~FacturaDomicilio();
};

#endif
