#ifndef _RECIBIDO_HPP
#define _RECIBIDO_HPP

//Archivos
#include "Etapa.hpp"

class Recibido : public Etapa {
public:
    Recibido();
    ~Recibido();
    Etapa *avanzarEtapa(EtapaPedido &etapa_pedido);
    Etapa *cancelar();
};

#endif
