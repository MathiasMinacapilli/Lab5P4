#ifndef _CONTROLADORMESA_HPP
#define _CONTROLADORMESA_HPP

//Librerias de C
using namespace std;
#include <set>
#include <map>

//Archivos
#include "IMesa.hpp"
#include "IEmpleado.hpp"

class ControladorMesa : public IMesa {
private:
    ControladorMesa();
    static ControladorMesa *instance;
    map<int, Mesa*> mesas;
    Mesa* mesa_recordada;
    int num_mozo_recordado;
    set<int> posibles_mesas;
    set<int> mesas_seleccionadas;
public:
    //Asignar automáticamente mozos a mesas
    map<int, DtMesasMozo> asignarMozosAMesas();
    //Facturación de una venta - generarFactura() - ControladorVenta
    void finalizarVenta();
    //Quitar Producto a una Venta - getProductosVenta() - ControladorVenta
    Venta* obtenerVenta(int numero);
    //Iniciar Venta en Mesas
    set<int> getMesasMozoSinVentas(int num_mozo);
    void seleccionarMesasVenta(set<int> numeros);
    set<int> getMesasSeleccionadas();
    void iniciarVenta();
    void cancelarVenta();
};

#endif