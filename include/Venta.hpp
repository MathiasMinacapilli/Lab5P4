
//Librerias de C
#include <set>
using namespace std;

//Archivos
#include "DtProducto.hpp";
#include "Producto.hpp";
#include "Facturar.hpp";

class Venta {
private:
    int numero;
    float descuento;
    Venta(/*args*/);
public:
    virtual void agregarProductoAVenta(Producto prod) = 0;
    virtual bool buscarProducto(Producto p) = 0;
    virtual bool estaFacturada() = 0;
    void eliminarProducto(Producto prod, int cantidad);
    void facturar();
    virtual set<DtProducto> obtenerProductos();
    ~Venta();
};
