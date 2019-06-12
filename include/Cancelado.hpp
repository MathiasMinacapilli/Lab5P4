#ifndef _CANCELADO_HPP
#define _CANCELADO_HPP

//Archivos
#include "Etapa.hpp"

class Cancelado : public Etapa {
public:
    Cancelado();
    ~Cancelado();
    Etapa *avanzarEtapa(EtapaPedido &etapa_pedido);
    Etapa *cancelar();
};

#endif
