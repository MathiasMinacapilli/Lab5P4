#ifndef _VENTAADOMICILIO_HPP
#define _VENTAADOMICILIO_HPP

//Librerias de C
#include <set>
using namespace std;

//Archivos
#include "Venta.hpp"
#include "Etapa.hpp"
#include "IObserverActualizaciones.hpp"
#include "Cliente.hpp"

class VentaADomicilio: public Venta{
private:
    Etapa *etapa;
    IObserverActualizaciones *miObservador;
    Cliente *miCliente;
public:
    VentaADomicilio(int numero, float descuento, Factura* factura, Etapa* etapa, Cliente *miCliente);
    ~VentaADomicilio();
    void avanzarEtapaVenta(string nombre_repartidor);
    void cancelarVenta();
};

#endif
