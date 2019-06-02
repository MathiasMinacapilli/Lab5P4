//Librerias de C
#include <map>
using namespace std

//Archivos
#include "../include/ProductoSimple.hpp"
#include "../include/ControladorProducto.hpp"

ProductoSimple::ProductoSimple(int codigo, string descripcion, float precio)
 : Producto(codigo, descripcion, precio) {
  }

DtProductoSimple Producto::getDatos() {
    DtProductoSimple dtprodsimple = DtProductoSimple(this->codigo, this->descripcion, this->precio);                                                                                                                                                                   
    return dtprod;    
}


void ProductoSimple::eliminar(){
	controlador_producto = ControladorProducto::getInstance();
	controlador_producto->eliminarProductoDeMenu(this->codigo);
	delete this;

}