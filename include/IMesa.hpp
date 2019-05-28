#ifndef _IMESA_HPP
#define _IMESA_HPP

//Librerias de C
#include <set>
using namespace std;

//Archivos
#include "DtMesasMozo.hpp";
#include "Venta.hpp";

class IMesa {
public:
    virtual set<DtMesasMozo> asignarMozosAMesas() = 0;
    virtual void cancelarVenta() = 0;
    virtual void finalizarVenta() = 0;
    virtual set<int> getMesasMozoSinVentas(int num_mozo) = 0;
    virtual set<int> getMesasSeleccionadas() = 0;
    virtual void iniciarVenta() = 0;
    virtual Venta obtenerVenta(int numero) = 0;
    virtual void seleccionarMesasVenta(set<int> numeros) = 0;
    ~IMesa() {};
};

#endif
