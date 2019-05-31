#ifndef _DTMENU_HPP
#define _DTMENU_HPP

//Librerias de C
#include <set>
using namespace std;

#include "DtProducto.hpp"
#include "DtProductoEnMenu.hpp"

class DtProductoSimple : public DtProducto {
private:
    set<DtProductoEnMenu> productos;
public:
    DtProductoSimple(int codigo, string descripcion, float precio, set<DtProductoEnMenu> productos);
    set<DtProductoEnMenu> getProductos();
    ~DtProductoSimple();
};

#endif
