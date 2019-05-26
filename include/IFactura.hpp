//Librerias de C
#include <set>
using namespace std;

//Archivos
#include "DtProducto.hpp";

class IFactura {
public:
    virtual void crearFactura(int codigo, set<DtProducto> datosProductos) = 0;
    ~IFactura() {};
};
