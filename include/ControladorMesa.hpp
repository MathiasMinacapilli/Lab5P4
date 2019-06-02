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
public:
    map<int, DtMesasMozo> asignarMozosAMesas();
    void cancelarVenta();
    void finalizarVenta();
    set<int> getMesasMozoSinVentas(int num_mozo);
    set<int> getMesasSeleccionadas();
    void iniciarVenta();
    Venta obtenerVenta(int numero);
    void seleccionarMesasVenta(set<int> numeros);
};

#endif
