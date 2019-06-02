//Librerias de C
using namespace std;

//Archivos
#include "../include/Factura.hpp"

Factura::Factura(int codigo, DtFechaYHora fechaYHora, map<int, DtProductoCantidad> productosCantidad, float iva, float descuento, float precioSubTotal, float precioTotal) {
    this->codigo = codigo;
    this->fechaYHora = fechaYHora;
    this->productosCantidad = productosCantidad;
    this->iva = iva;
    this->descuento = descuento;
    this->precioSubTotal = precioSubTotal;
    this->precioTotal = precioTotal;
}

Factura::~Factura() {
}
