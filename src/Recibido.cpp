//Archivos
#include "../include/Recibido.hpp"

Recibido::Recibido() : Etapa() {
}

Recibido::~Recibido() {
}

Etapa *Recibido::avanzarEtapa(EtapaPedido &etapa_pedido) {
    return nullptr;
}

Etapa *Recibido::cancelar() {
    return nullptr;
}
