
#include "../include/DtFacturaDomicilio.hpp";

DtFacturaDomicilio::DtFacturaDomicilio(int codigo, DtFechaYHora fechaYHora, DtProductoCantidad productos, float iva, float descuento, float precioSubTotal, float precioTotal, string nombreRepartidor, Transporte transporte)
:DtFactura(codigo, fechaYHora, productos, iva, descuento, precioSubTotal, precioTotal) {
    this->nombreRepartidor = nombreRepartidor;
    this->transporte = transporte;
}

string DtFacturaDomicilio::getNombreRepartidor() {
    return this->nombreRepartidor;
}

Transporte DtFacturaDomicilio::getTransporte() {
    return this->transporte;
}

DtFacturaDomicilio::~DtFacturaDomicilio() {}
