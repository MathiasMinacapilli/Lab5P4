#ifndef _MESA_HPP
#define _MESA_HPP

//Librerias de C
#include <map>
using namespace std;

//Archivos
#include "Mozo.hpp"
#include "VentaLocal.hpp"

class Mesa{
private:
    int numero;
    Mozo *miMozo;
    VentaLocal *ventaActual;
    map<int, VentaLocal *> ventasPasadas;
public:
    //constructor y destructor
    Mesa(int numero, Mozo *miMozo, VentaLocal *ventaActual, map<int, VentaLocal *> ventasPasadas);
    ~Mesa();
    //getters y setters
    int getNum();
    void setMozo(Mozo *m);
    Mozo *getMiMozo();
    void setVentaActual(VentaLocal *v);
    Venta *getVentaActual();
    void agregarAVentasPasadas(VentaLocal *v);
    map<int, VentaLocal *> getVentasPasadas();
    //operaciones
    bool noTieneVentas();
    bool esDelMozo(int numMozo);
    void terminarVenta();
};

#endif
