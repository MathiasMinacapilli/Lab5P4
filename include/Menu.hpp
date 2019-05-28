#ifndef _MENU_HPP
#define _MENU_HPP

#include <iterator> 
#include <map> 

#include "Producto.hpp"
#include "ProductoSimple.hpp"
#include "ProductoEnMenu.hpp"

using namespace std;

class Menu : public Producto {
private:
    map<int, ProductoEnMenu *> productos;
public:
    //constructor y destructor
    Menu();
    ~Menu();
    
    void eliminar();
    void eliminarProducto(int cod);
    void agregarProducto(ProductoSimple *prod);
    bool esVacio();
  

};

#endif
