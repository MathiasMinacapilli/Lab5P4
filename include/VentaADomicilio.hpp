#ifndef _VENTAADOMICILIO_HPP
#define _VENTAADOMICILIO_HPP

//Librerias de C
#include <set>
using namespace std;

class Repartidor;

//Archivos
#include "Empleado.hpp"
#include "DtFacturaDomicilio.hpp"
#include "Venta.hpp"
#include "Etapa.hpp"
#include "IObserverActualizaciones.hpp"
#include "Cliente.hpp"

class VentaADomicilio: public Venta{
private:
    Etapa *etapa;
    IObserverActualizaciones *miObservador;
    Cliente *miCliente;
    Repartidor *miRepartidor;
    set<DtActualizacion> actualizaciones;
public:
	VentaADomicilio();
    VentaADomicilio(int numero, float descuento, Factura* factura, Etapa* etapa, Cliente *miCliente, Repartidor *miRepartidor);
    ~VentaADomicilio();
    void avanzarEtapaVenta(string nombre_repartidor);
    void cancelarVenta(string nombre_repartidor);
    set<DtActualizacion> getActualizaciones() const;
    Cliente* getCliente();
    DtFactura* facturar();
};

#include "Repartidor.hpp"

#endif
