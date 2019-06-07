#ifndef _PEDIDO_HPP
#define _PEDIDO_HPP

//Librerias de C
using namespace std;

//Archivos
#include "Etapa.hpp"

class Pedido : public Etapa {
public:
    Pedido();
    ~Pedido();
    Etapa *avanzarEtapa();
    Etapa *cancelar();
};

#endif
