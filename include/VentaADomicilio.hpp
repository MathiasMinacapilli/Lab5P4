#ifndef _VENTAADOMICILIO_HPP
#define _VENTAADOMICILIO_HPP

//Librerias de C
#include <set>
using namespace std;

//Archivos
#include "Venta.hpp"
#include "Etapa.hpp"

class VentaADomicilio: public Venta{
private:
    Etapa *etapa;
public:
    VentaADomicilio(int numero, float descuento, Factura* factura, Etapa* etapa);
    ~VentaADomicilio();
    void avanzarEtapaVenta();
    void cancelarVenta();
};

#endif
