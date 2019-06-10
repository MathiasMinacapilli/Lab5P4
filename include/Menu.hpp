#ifndef _MENU_HPP
#define _MENU_HPP

//Librerias de C
#include <iterator> 
#include <map> 
#include <string>
using namespace std;

//Archivos
#include "Producto.hpp"
#include "ProductoSimple.hpp"
#include "ProductoEnMenu.hpp"


class Menu : public Producto {
private:
    map<int, ProductoEnMenu *> productos;
public:
    //constructor y destructor
    Menu(int codigo, string descripcion);
    ~Menu();
    
    map<int, ProductoEnMenu *> getProductos();
    void eliminar();
    void eliminarProducto(int cod);
    void agregarProducto(ProductoSimple *prod, int cantidad);
    bool esVacio();
  

};

#endif
