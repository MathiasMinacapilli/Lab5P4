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

DtFactura::~DtFactura() {}

ostream &operator<< (ostream& o, DtFactura dtf) {
    o << "Codigo: " << dtf.getCodigo()
      << "\nFecha y hora: " << dtf.getFechaYHora() 
      << "\n- Productos -\n";
      map<int, DtProductoCantidad>::iterator it;
      for (it = (dtf.getProductos()).begin(); it != (dtf.getProductos()).end(); ++it) {
          o << (it -> second);
      }
    o << "\nIva: " << dtf.getIva()
      << "\nDescuento: " << dtf.getDescuento()
      << "\nPrecio Subtotal: " << dtf.getPrecioSubTotal()
      << "\nPrecio Total: " << dtf.getPrecioTotal(); 
    return o;
}
