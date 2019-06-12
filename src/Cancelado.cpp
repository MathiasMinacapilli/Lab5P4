//Archivos
#include "../include/Cancelado.hpp"

Cancelado::Cancelado() : Etapa() {
}

Cancelado::~Cancelado() {
}

Etapa *Cancelado::avanzarEtapa(EtapaPedido &etapa_pedido) {
    return nullptr;
}

Etapa *Cancelado::cancelar() {
    return nullptr;
}
