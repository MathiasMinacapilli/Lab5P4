//Archivos
#include "../include/DtFacturaLocal.hpp"

DtFacturaLocal::DtFacturaLocal(int codigo, DtFechaYHora fechaYHora, map<int, DtProductoCantidad> productos, float iva, float descuento, float precioSubTotal, float precioTotal, string nombreMozo)
:DtFactura(codigo, fechaYHora, productos, iva, descuento, precioSubTotal, precioTotal) {
    this->nombreMozo = nombreMozo;
}

string DtFacturaLocal::getNombreMozo() {
    return this->nombreMozo;
}

DtFacturaLocal::~DtFacturaLocal() {}

ostream &operator<< (ostream& o, DtFacturaLocal dtf) {
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
      << "\nNombre del Mozo: " << dtf.getNombreMozo(); 
    return o;
}