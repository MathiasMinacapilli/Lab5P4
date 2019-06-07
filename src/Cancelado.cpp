//Archivos
#include "../include/Cancelado.hpp"

Cancelado::Cancelado() : Etapa() {
}

Cancelado::~Cancelado() {
}

Etapa *avanzarEtapa() {
    return this;
}

Etapa *cancelar() {
    return this;
}
