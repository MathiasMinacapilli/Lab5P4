
#include "DtFactura.hpp";

//Librerias de C
#include <string>
using namespace std;

class DtFacturaLocal: public DtFactura {
private:
    string nombreMozo;
public:
    DtFacturaLocal(int codigo, DtFechaYHora fechaYHora, DtProductoCantidad productos, float iva, float descuento, float precioSubTotal, float precioTotal, string nombreMozo);
    string getNombreMozo();
    ~DtFacturaLocal();
};
