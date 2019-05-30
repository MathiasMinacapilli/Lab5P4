#ifndef _DTINFOVENTA_HPP
#define _DTINFOVENTA_HPP

//Librerias C
#include <set>
using namespace std;

//Archivos
#include "DtProducto.hpp";
#include "Etapa.hpp";

class DtInfoVenta {
private:
    int numeroVenta;
    float descuento;
    set<DtProducto> datosProducto;
    Etapa* etapaActual;
public:
    DtInfoVenta(int numeroVenta, float descuento, set<DtProducto> datosProducto, Etapa* etapaActual);
    int getNumeroVenta();
    loat getDescuento();
    et<DtProducto> getDatosProducto();
    Etapa* getEtapaActual();
    ~DtInfoVenta();
};


#endif