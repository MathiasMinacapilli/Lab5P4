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
    o << "\n Código: " << dtf.getCodigo() << "\n"
      << "\n Fecha y hora: " << dtf.getFechaYHora() << "\n"
      << "\n Productos de la venta.\n";
    map<int, DtProductoCantidad>::iterator it;
    for (it = (dtf.getProductos()).begin(); it != (dtf.getProductos()).end(); ++it)
        o << "    " << (it -> second) << "\n";
    o << "\n Iva: " << dtf.getIva() << "\n"
      << "\n Descuento: " << dtf.getDescuento() << "\n"
      << "\n Precio subtotal: $" << dtf.getPrecioSubTotal() << "\n"
      << "\n Precio total: $" << dtf.getPrecioTotal() << "\n"
      << "\n Nombre del mozo: " << dtf.getNombreMozo();
    return o;
}
