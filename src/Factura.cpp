
#include "../include/Factura.hpp"

Factura::Factura(int codigo, DtFechaYHora fechaYHora, set<DtProductoCantidad> productos, float iva, float descuento, float precioSubTotal, float precioTotal) {
    this->codigo = codigo;
    this->fechaYHora = fechaYHora;
    this->productos = productos;
    this->iva = iva;
    this->descuento = descuento;
    this->precioSubTotal = precioSubTotal;
    this->precioTotal = precioTotal;
}

