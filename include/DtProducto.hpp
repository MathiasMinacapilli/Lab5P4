#ifndef _DTPRODUCTO_HPP
#define _DTPRODUCTO_HPP

//Librerias de C
#include <string>
#include <ostream>
using namespace std;

class DtProducto {
protected:
    int codigo;
    string descripcion;
    float precio;
    int cantidadVendidos;
public:
    //Constructor
    DtProducto();
    DtProducto(int codigo, string descripcion, float precio);
    DtProducto(int codigo, string descripcion, float precio, int cantidadVendidos);
    
    //Destructor virtual porque tiene clases derivadas
    virtual ~DtProducto();

    //Getters
    int getCodigo();
    string getDescripcion();
    float getPrecio();
    int getCantidadVendidos();
};

ostream &operator<< (ostream&, DtProducto);

#endif
