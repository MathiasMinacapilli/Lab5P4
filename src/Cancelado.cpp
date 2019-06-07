//Archivos
#include "../include/Cancelado.hpp"

Cancelado::Cancelado() : Etapa() {
}

Cancelado::~Cancelado() {
}

Etapa *Cancelado::avanzarEtapa() {
    return this;
}

Etapa *Cancelado::cancelar() {
    return this;
}
