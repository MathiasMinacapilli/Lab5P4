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
    //Constructores
	VentaADomicilio();
    VentaADomicilio(int numero, float descuento, Factura* factura, Etapa* etapa, IObserverActualizaciones* miObserver, Cliente *miCliente, Repartidor *miRepartidor);
    //Destructores
    ~VentaADomicilio();
    //Patron State
    void avanzarEtapaVenta();
    void cancelarVenta();
    //obtiene las actualizaciones de la venta
    vector<DtActualizacion> getActualizaciones() const;
    //obtiene el cliente
    Cliente* getCliente();
    //obtiene el repartidor
    Repartidor *getRepartidor();
    //facturacion de la venta
    DtFactura* facturar();
    //Patron observer
    void setObservador(IObserverActualizaciones *observador);
    void borrarObservador();

    //funciones usadas unicamente para cargar datos de prueba
    void agregarActualizacion(DtActualizacion dt_Act);
    
};

//Forward Declaration
#include "Repartidor.hpp"

#endif
