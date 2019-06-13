#ifndef _ETAPA_HPP
#define _ETAPA_HPP

//Archivos
#include "EtapaPedido.hpp"

class Etapa {
protected:
    Etapa();
public:
    virtual Etapa *avanzarEtapa(EtapaPedido &etapa_pedido) = 0;
    virtual Etapa *cancelar() = 0;
    virtual ~Etapa() {};
};

#endif
