
#include "../include/DtInfoVenta.hpp";

DtInfoVenta::DtInfoVenta(int numeroVenta, float descuento, set<DtProducto> datosProducto, Etapa* etapaActual) {
    this->numeroVenta = numeroVenta;
    this->descuento = descuento;
    this->datosProducto = datosProducto;
    this->etapaActual = etapaActual;
}

int DtInfoVenta::getNumeroVenta() {
    return this->numeroVenta;
}

float DtInfoVenta::getDescuento() {
    return this->descuento;
}

set<DtProducto> DtInfoVenta::getDatosProducto() {
    return this->datosProducto;
}

Etapa* DtInfoVenta::getEtapaActual() {
    return this->etapaActual;
}

DtInfoVenta::~DtInfoVenta() {}
