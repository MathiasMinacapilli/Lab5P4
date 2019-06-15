//Archivos
#include "../include/DtFacturaDomicilio.hpp"

DtFacturaDomicilio::DtFacturaDomicilio() : DtFactura() {}

DtFacturaDomicilio::DtFacturaDomicilio(int codigo, DtFechaYHora fechaYHora, map<int, DtProductoCantidad> productos, float iva, float descuento, float precioSubTotal, float precioTotal, string nombreRepartidor, Transporte transporte)
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

ostream &operator<< (ostream& o, DtFacturaDomicilio dtf) {
    o << "\n Código: " << dtf.getCodigo() << "\n"
      << "\n Fecha y hora: " << dtf.getFechaYHora() << "\n"
      << "\n Productos de la venta.\n";
    map<int, DtProductoCantidad> map_prod = dtf.getProductos();
    map<int, DtProductoCantidad>::iterator it;
    for (it = map_prod.begin(); it != map_prod.end(); ++it) {
      o << "    " << (it -> second) << "\n";
    }
    o  << "\n Iva: " << dtf.getIva() << "\n"
      << "\n Descuento: " << dtf.getDescuento() << "\n"
      << "\n Precio Subtotal: $" << dtf.getPrecioSubTotal() << "\n"
      << "\n Precio Total: $" << dtf.getPrecioTotal() << "\n"
      << "\n Nombre del repartidor: " << dtf.getNombreRepartidor() << "\n"
      << "\n Transporte: " << dtf.getTransporte();
    return o;
}
