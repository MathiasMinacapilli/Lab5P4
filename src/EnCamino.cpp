//Archivos
#include "../include/EnCamino.hpp"
#include "../include/Recibido.hpp"
#include "../include/Cancelado.hpp"

EnCamino::EnCamino() : Etapa() {
}

EnCamino::~EnCamino() {
}

Etapa *EnCamino::avanzarEtapa() {
  return new Recibido();
}

Etapa *EnCamino::cancelar() {
  return new Cancelado();
}
