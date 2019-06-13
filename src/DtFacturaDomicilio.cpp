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
      << "\nPrecio Total: " << dtf.getPrecioTotal()
      << "\nNombre del Repartidor: " << dtf.getNombreRepartidor()
      << "\nTransporte: " << dtf.getTransporte(); 
    return o;
}