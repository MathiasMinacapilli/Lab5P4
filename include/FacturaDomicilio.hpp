#ifndef _FACTURADOMICILIO_HPP
#define _FACTURADOMICILIO_HPP

#include "Factura.hpp";

//Bibliotecas de C
#include <string>

//Archivos
#include "Transporte.hpp";
class FacturaDomicilio: public Factura {
private:
    string nombreRepartidor;
    Transporte transporte;
public:
};

#endif