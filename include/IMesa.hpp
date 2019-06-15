#ifndef _IMESA_HPP
#define _IMESA_HPP

//Librerias de C
#include <set>
#include <map>
using namespace std;

//Archivos
#include "DtMesasMozo.hpp"
#include "Venta.hpp"

class IMesa {
protected:
    IMesa();
public:
    //Caso de uso: Asignar automaticamente mozos a mesas
    virtual map<int, DtMesasMozo> asignarMozosAMesas() = 0;
    virtual void cancelarVenta() = 0;
    virtual void finalizarVenta() = 0;
    virtual set<int> getMesasMozoSinVentas(int num_mozo) = 0;
    virtual set<int> getMesasSeleccionadas() = 0;
    virtual void iniciarVenta() = 0;
    virtual Venta *obtenerVenta(int numero) = 0;
    virtual void seleccionarMesasVenta(set<int> numeros) = 0;
    ~IMesa() {};
};

#endif
