
#include "../include/DtProductoEnMenu.hpp";

DtProductoEnMenu::DtProductoEnMenu(DtProductoSimple producto, int cantidad) {
    this->producto = producto;
    this->cantidad = cantidad;
}

DtProductoSimple DtProductoEnMenu::getProducto() {
    return this->producto;
}

int DtProductoEnMenu::getCantidad() {
    return this->cantidad;
}

DtProductoEnMenu::~DtProductoEnMenu() {}
