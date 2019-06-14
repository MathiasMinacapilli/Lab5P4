#ifndef _VENTAADOMICILIO_HPP
#define _VENTAADOMICILIO_HPP

//Librerias de C
#include <vector>
using namespace std;

//Forward Declaration
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
    vector<DtActualizacion> actualizaciones;
public:
    //Constructor
	VentaADomicilio();
    VentaADomicilio(int numero, float descuento, Factura* factura, Etapa* etapa, Cliente *miCliente, Repartidor *miRepartidor);

    //Destructor
    ~VentaADomicilio();
    
    void avanzarEtapaVenta(string nombre_repartidor);
    void cancelarVenta(string nombre_repartidor);

    //Getters
    Cliente* getCliente();
    vector<DtActualizacion> getActualizaciones() const;

    DtFactura* facturar();
};

//Forward Declaration
#include "Repartidor.hpp"

#endif
