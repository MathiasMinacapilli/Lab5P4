#ifndef _FACTURADOMICILIO_HPP
#define _FACTURADOMICILIO_HPP

//Librerias de C
#include <string>
#include <set>
using namespace std;

//Archivos
#include "Factura.hpp"
#include "Transporte.hpp"
#include "DtProductoCantidad.hpp"

class FacturaDomicilio: public Factura {
private:
    string nombreRepartidor;
    Transporte transporte;
public:
    FacturaDomicilio(int codigo, DtFechaYHora fechaYHora, map<int, DtProductoCantidad> productosCantidad, float iva, float descuento, float precioSubTotal, float precioTotal, string nombreRepartidor, Transporte transporte);
    ~FacturaDomicilio();
};

#endif
