#ifndef _MESA_HPP
#define _MESA_HPP

#include <map>

#include "Empleado.hpp"
#include "VentaLocal.hpp"

using namespace std;

class Mesa{
private:
    int numero;
    VentaLocal *ventaActual;
    map<int, VentaLocal *> ventasPasadas;
public:
    //constructor y destructor
    Mesa(int num);
    ~Mesa();
    //getters y setters 
    int getNum();
    void setVentaActual(VentaLocal *v);
    Venta *getVentaActual();
    void agregarAVentasPasadas(VentaLocal *v);
    //operaciones
    bool noTieneVentas();
    bool esDelMozo(int numMozo);
    void terminarVenta();
};

#endif
