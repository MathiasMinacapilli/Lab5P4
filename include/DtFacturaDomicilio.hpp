//Librerias de C
#include <string>
#include <map>
using namespace std;

//Archivos
#include "DtFactura.hpp"
#include "Transporte.hpp"

class DtFacturaDomicilio: public DtFactura {
private:
    string nombreRepartidor;
    Transporte transporte;
public:
	DtFacturaDomicilio();
    DtFacturaDomicilio(int codigo, DtFechaYHora fechaYHora, map<int, DtProductoCantidad> productos, float iva, float descuento, float precioSubTotal, float precioTotal, string nombreRepartidor, Transporte transporte);
    string getNombreRepartidor();
    Transporte getTransporte();
    ~DtFacturaDomicilio();
};