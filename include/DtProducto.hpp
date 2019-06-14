#ifndef _DTPRODUCTO_HPP
#define _DTPRODUCTO_HPP

//Librerias de C
#include <string>
#include <ostream>
using namespace std;

class DtProducto {
private:
    int codigo;
    string descripcion;
    float precio;
public:
    //Constructor
    DtProducto();
    DtProducto(int codigo, string descripcion, float precio);

    //Destructor virtual porque tiene clases derivadas
    virtual ~DtProducto();

    //Getters
    int getCodigo();
    string getDescripcion();
    float getPrecio();
};

ostream &operator<< (ostream&, DtProducto);

#endif
