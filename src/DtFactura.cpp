//Archivos
#include "../include/DtFactura.hpp"

DtFactura::DtFactura() {}

DtFactura::~DtFactura() {}

DtFactura::DtFactura(int codigo, DtFechaYHora fechaYHora, map<int, DtProductoCantidad> productos, float iva, float descuento, float precioSubTotal, float precioTotal) {
    this->codigo = codigo;
    this->fechaYHora = fechaYHora;
    this->productos = productos;
    this->iva = iva;
    this->descuento = descuento;
    this->precioSubTotal = precioSubTotal;
    this->precioTotal = precioTotal;
}

int DtFactura::getCodigo() {
    return this->codigo;
}

DtFechaYHora DtFactura::getFechaYHora() {
    return this->fechaYHora;
}

map<int, DtProductoCantidad> DtFactura::getProductos() {
    return this->productos;
}

float DtFactura::getIva() {
    return this->iva;
}

float DtFactura::getDescuento() {
    return this->descuento;
}

float DtFactura::getPrecioSubTotal() {
    return this->precioSubTotal;
}

float DtFactura::getPrecioTotal() {
    return this->precioTotal;
}

ostream &operator<< (ostream& o, DtFactura dtf) {
    o << "\n Código: " << dtf.getCodigo() << "\n"
      << "\n Fecha y hora: " << dtf.getFechaYHora() << "\n"
      << "\n Productos de la venta. \n";
    map<int, DtProductoCantidad>::iterator it;
    map<int, DtProductoCantidad> map_prods = dtf.getProductos();
    for (it = map_prods.begin(); it != map_prods.end(); ++it)
        o << "    " << (it -> second) << "\n";
    o << "\n Iva: " << dtf.getIva() << "\n"
      << "\n Descuento: " << dtf.getDescuento() << "\n"
      << "\n Precio subtotal: $" << dtf.getPrecioSubTotal() << "\n"
      << "\n Precio total: $" << dtf.getPrecioTotal();
    return o;
}
