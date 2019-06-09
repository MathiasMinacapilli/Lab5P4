#ifndef _DTPRODUCTO_HPP
#define _DTPRODUCTO_HPP

//Librerias de C
#include <string>
#include <ostream>
using namespace std;

//Archivos

class DtProducto {
private:
    int codigo;
    string descripcion;
    float precio;
public:
    DtProducto();
    DtProducto(int codigo, string descripcion, float precio); //
    //getters
    int getCodigo();
    string getDescripcion();
    float getPrecio();
    //destructor
    ~DtProducto();
};

ostream &operator<< (ostream&, DtProducto);

#endif
