
#include "DtFactura.hpp";

//Librerias de C
#include <string>
using namespace std;

//Archivos
#include "Transporte.hpp";

class DtFacturaDomicilio: public DtFactura {
private:
    string nombreRepartidor;
    Transporte transporte;
public:
    DtFacturaDomicilio(int codigo, DtFechaYHora fechaYHora, DtProductoCantidad productos, float iva, float descuento, float precioSubTotal, float precioTotal, string nombreRepartidor, Transporte transporte);
    string getNombreRepartidor();
    Transporte getTransporte();
    ~DtFacturaDomicilio();
};