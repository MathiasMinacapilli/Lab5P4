
#include "Venta.hpp";

//Librerias de C
#include <set>
using namespace std;

//Archivos
#include "DtProducto.hpp";
#include "Producto.hpp";


class VentaADomicilio: public Venta{
private:
    Etapa etapa;
public:
    void agregarProductoAVenta(Producto prod);
    bool buscarProducto(Producto p);
    bool estaFacturada();
    void avanzarEtapaVenta();
    void cancelarVenta();
};
