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
    //Constructor
    Menu(int codigo, string descripcion);

    //Destructor
    ~Menu();

    //Getters
    map<int, ProductoEnMenu *> getProductos();

    void eliminar();
    bool eliminarProducto(int cod);
    void agregarProducto(ProductoSimple *prod, int cantidad);
    bool esVacio();
};

#endif
