//Librerias de C
#include <string>
#include <map>
using namespace std;

//Archivos
#include "DtFactura.hpp"

class DtFacturaLocal: public DtFactura {
private:
    string nombreMozo;
public:
    //Constructor
    DtFacturaLocal(int codigo, DtFechaYHora fechaYHora, map<int, DtProductoCantidad> productos, float iva, float descuento, float precioSubTotal, float precioTotal, string nombreMozo);

    //Destructor
    ~DtFacturaLocal();

    //Getters
    string getNombreMozo();
};

ostream &operator<< (ostream&, DtFacturaLocal);
