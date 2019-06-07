//Archivos
#include "../include/Recibido.hpp"

Recibido::Recibido() : Etapa() {
}

Recibido::~Recibido() {
}

Etapa *Recibido::avanzarEtapa() {
    return this;
}

Etapa *Recibido::cancelar() {
    return this;
}
