//Archivos
#include "../include/DtMenu.hpp"

DtMenu::DtMenu(int codigo, string descripcion, float precio, map<int, DtProductoEnMenu> productos)
:DtProducto(codigo, descripcion, precio) {
    this->productos = productos;
}

map<int, DtProductoEnMenu> DtMenu::getProductos() {
    return this->productos;
}

DtMenu::~DtMenu() {
    //liberar memoria de productos?
}
