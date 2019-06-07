#ifndef _FACTURA_HPP
#define _FACTURA_HPP

//Librerias de C
#include <map>
using namespace std;

//Archivos
#include "DtFechaYHora.hpp"
#include "DtProductoCantidad.hpp"
#include "Producto.hpp"
#include "DtFactura.hpp"

const float valor_iva = 22;

class Factura {
private:
    int codigo;
    DtFechaYHora fechaYHora;
    map<int, DtProductoCantidad> productosCantidad;
    float iva;
    float descuento;
    float precioSubTotal;
    float precioTotal;
public:
	//constructor y destructor
    Factura(int codigo, DtFechaYHora fechaYHora, map<int, DtProductoCantidad> productosCantidad, float iva, float descuento, float precioSubTotal, float precioTotal);
    ~Factura();
    //getters
    int getCodigo();
    DtFechaYHora getFechaYHora();
    float getPrecioSubtotal();
    float getPrecioTotal();

    DtFactura getDatosFactura();
};

#endif
