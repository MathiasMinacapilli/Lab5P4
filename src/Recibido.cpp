//Archivos
#include "../include/Recibido.hpp"

Recibido::Recibido() : Etapa() {
}

Recibido::~Recibido() {
}

Etapa *avanzarEtapa() {
    return this;
}

Etapa *cancelar() {
    return this;
}
