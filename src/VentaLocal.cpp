//Archivos
#include "../include/VentaLocal.hpp"

VentaLocal::VentaLocal(int numero, float descuento, Factura* factura) : Venta(numero, descuento, factura) {
}

void VentaLocal::setMozo(Mozo *mozo){
	this->miMozo = mozo;
}

VentaLocal::~VentaLocal() {
}
