#ifndef _CONTROLADORMESA_HPP
#define _CONTROLADORMESA_HPP

//Librerias de C
using namespace std;
#include <set>
#include <map>

//Archivos
#include "IMesa.hpp";

class ControladorMesa : public IMesa {
private:
    ControladorMesa();
    static ControladorMesa *instance;
    map<int, Mesa*> mesas;
    Mesa* mesa_recordada
public:
    //Asignar automáticamente mozos a mesas
    map<int, DtMesasMozo> asignarMozosAMesas();
    //Iniciar Venta en Mesas - cancelarVenta() - 
    void cancelarVenta();
    //Facturación de una venta - generarFactura() - ControladorVenta
    void finalizarVenta();
    set<int> getMesasMozoSinVentas(int num_mozo);
    set<int> getMesasSeleccionadas();
    void iniciarVenta();
    Venta obtenerVenta(int numero);
    void seleccionarMesasVenta(set<int> numeros);
};

#endif
