
#include "../include/DtFacturaLocal.hpp";

DtFacturaLocal::DtFacturaLocal(int codigo, DtFechaYHora fechaYHora, DtProductoCantidad productos, float iva, float descuento, float precioSubTotal, float precioTotal, string nombreMozo)
:DtFactura(codigo, fechaYHora, productos, iva, descuento, precioSubTotal, precioTotal) {
    this->nombreMozo = nombreMozo;
}

string DtFacturaLocal::getNombreMozo() {
    return this->nombreMozo;
}

DtFacturaLocal::~DtFacturaLocal() {}
