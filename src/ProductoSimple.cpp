//Librerias de C
#include <map>
using namespace std

//Archivos
#include "../include/ProductoSimple.hpp"
#include "../include/ControladorProducto.hpp"

ProductoSimple::ProductoSimple(int codigo, string descripcion, float precio)
 : Producto(codigo, descripcion, precio) {
  }

ProductoSimple::~ProductoSimple(){}

void ProductoSimple::eliminar(){
	controlador_producto = ControladorProducto::getInstance();
	controlador_producto->eliminarProductoDeMenu(this->codigo);
	delete this;

}