//Librerias de C
#include <set>
using namespace std;

//Archivos
#include "Venta.hpp";
#include "Producto.hpp";

class VentaLocal : public Venta {
public:
    VentaLocal(int numero, float descuento, map<int, CantidadProducto*> cant_producto, Factura* factura);
    ~VentaLocal();
    void agregarProductoAVenta(Producto *prod);
    bool buscarProducto(Producto p);
    bool estaFacturada();
};
