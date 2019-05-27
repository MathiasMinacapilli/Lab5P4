
#include "Venta.hpp";

//Librerias de C
#include <set>
using namespace std;

//Archivos
#include "Producto.hpp";

class VentaLocal
{
private:
    /* data */
public:
    virtual void agregarProductoAVenta(Producto prod);
    virtual bool buscarProducto(Producto p);
    virtual bool estaFacturada();
};
