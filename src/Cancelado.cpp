//Archivos
#include "../include/Cancelado.hpp"

Cancelado::Cancelado() : Etapa() {
}

Cancelado::~Cancelado() {
}

Etapa *Cancelado::avanzarEtapa() {
    return nullptr;
}

Etapa *Cancelado::cancelar() {
    return nullptr;
}
