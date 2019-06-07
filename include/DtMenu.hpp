#ifndef _DTMENU_HPP
#define _DTMENU_HPP

//Librerias de C
#include <map>
#include <string>
using namespace std;

//Archivos
#include "DtProducto.hpp"
#include "DtProductoEnMenu.hpp"

class DtMenu : public DtProducto {
private:
    map<int, DtProductoEnMenu> productos;
public:
    DtMenu(int codigo, string descripcion, float precio, map<int, DtProductoEnMenu> productos);
    map<int, DtProductoEnMenu> getProductos();
    ~DtMenu();
};

#endif
