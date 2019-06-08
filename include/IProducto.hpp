#ifndef _IPRODUCTO_HPP
#define _IPRODUCTO_HPP

//Librerias de C
#include <string>
#include <map>
using namespace std;

//Archivos
#include "DtProducto.hpp"
#include "DtProductoCantidad.hpp"
#include "DtProductoSimple.hpp"
#include "Producto.hpp"

class IProducto { // interfaz
protected:
    IProducto();
public:
    virtual void cancelarBajaProducto() = 0;
    virtual void cancelarMenu() = 0;
    virtual void cancelarProductoSimple() = 0;
    virtual bool eliminarProducto() = 0;
    virtual void eliminarProductoDeMenu(int cod) = 0;
    virtual Producto *encontrarProducto(DtProductoCantidad producto_cantidad) = 0;
    virtual bool existeProductoSimple() = 0;
    virtual map<int, DtProducto> getProductosDisponibles() = 0;
    virtual map<int, DtProducto> getProductosSimples() = 0;
    virtual void ingresarDatosProducto(DtProductoSimple datos) = 0;
    virtual void ingresarProductoSimple() = 0;
    virtual void ingresarDatosMenu(int codigo, std::string desc) = 0;
    virtual void ingresarMenu() = 0;
    virtual void seleccionarProducto(int codigo_producto) = 0;
    virtual void seleccionarProductoYCantidad(DtProductoCantidad producto_cantidad) = 0;
    virtual ~IProducto(){}; // virtual y vacío
};

#endif
