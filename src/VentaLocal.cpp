//Archivos
#include "../include/VentaLocal.hpp"

VentaLocal::VentaLocal(int numero, float descuento, Factura* factura) : Venta(numero, descuento, factura) {
}

void VentaLocal::setMozo(Mozo *mozo){
	this->miMozo = mozo;
}

VentaLocal::~VentaLocal() {
}

DtFactura* VentaLocal::facturar() {
    map<int, CantidadProducto*>::iterator it;
    map<int, DtProductoCantidad> datos_productos;
    int precio_sub_total = 0;
    for(it = cants_productos.begin(); it != cants_productos.end(); ++it) {
        DtProducto datos = (it->second)->getProducto()->getDatosProducto();
        int cant = (it -> second)->getCantidad();
        DtProductoCantidad prod_cant = DtProductoCantidad(datos, cant);
        datos_productos.insert(pair<int, DtProductoCantidad>(datos.getCodigo(), prod_cant));
        precio_sub_total = precio_sub_total + (((it->second)->getProducto())->getPrecio());
        //Aumentar la cantidad de vendidos en el producto. Lo aumento la cantidad del producto_cantidad
        (it->second)->getProducto()->aumentarCantidadVendidos(it->second->getCantidad());
    }
    int precio_total = precio_sub_total * (1 - this->getDescuento()) * (1 + valor_iva);
    time_t t = time(0);
    tm* now = localtime(&t);
    DtFechaYHora fecha_y_hora = DtFechaYHora(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900, now->tm_hour, now->tm_min, now->tm_sec);
    Factura* factura = new Factura(this->getNumero(), fecha_y_hora, datos_productos, valor_iva, this->getDescuento(), precio_sub_total, precio_total);
    this->setFactura(factura);
    DtFacturaLocal res_local = DtFacturaLocal(this->getNumero(), fecha_y_hora, datos_productos, valor_iva, this->getDescuento(), precio_sub_total, precio_total, miMozo -> getNombre());
    DtFactura* res = &res_local;
    return res;
}
