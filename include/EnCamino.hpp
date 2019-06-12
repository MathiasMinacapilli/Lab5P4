#ifndef _ENCAMINO_HPP
#define _ENCAMINO_HPP

//Archivos
#include "Etapa.hpp"

class EnCamino : public Etapa {
public:
    EnCamino();
    ~EnCamino();
    Etapa *avanzarEtapa(EtapaPedido &etapa_pedido);
    Etapa *cancelar();
};

#endif
