#ifndef _VENTALOCAL_HPP
#define _VENTALOCAL_HPP

//Archivos
#include "DtFacturaLocal.hpp"
#include "Venta.hpp"
#include "Mozo.hpp"
#include "Producto.hpp"

class VentaLocal : public Venta {
private:
	Mozo *miMozo;
public:
    VentaLocal(int numero, float descuento, Factura* factura);
    ~VentaLocal();

	//Setters
    void setMozo(Mozo *mozo);
	
    DtFactura* facturar();
};

#endif
