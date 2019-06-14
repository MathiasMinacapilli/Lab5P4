#ifndef _MESA_HPP
#define _MESA_HPP

//Librerias de C
#include <map>
using namespace std;

class Mozo;
class VentaLocal;


class Mesa{
private:
    int numero;
    Mozo *miMozo;
    VentaLocal *ventaActual;
    map<int, VentaLocal *> ventasPasadas;
public:
    //Constructor
    Mesa(int numero, Mozo *miMozo, VentaLocal *ventaActual);

    //Destructor
    ~Mesa();

    //Getters
    int getNum();
    Mozo *getMiMozo();
    VentaLocal *getVentaActual();
    map<int, VentaLocal *> getVentasPasadas();

    //Setters
    void setMozo(Mozo *m);
    void setVentaActual(VentaLocal *v);

    void agregarAVentasPasadas(VentaLocal *v);
    bool noTieneVentas();
    bool esDelMozo(int numMozo);
    void terminarVenta();
};

//Archivos
#include "VentaLocal.hpp"
#include "Mozo.hpp"

#endif
