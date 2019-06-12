//Archivos
#include "../include/Pedido.hpp"
#include "../include/EnCamino.hpp"
#include "../include/Cancelado.hpp"

Pedido::Pedido() : Etapa() {
}

Pedido::~Pedido() {
}

Etapa *Pedido::avanzarEtapa(EtapaPedido &etapa_pedido) {
	etapa_pedido = enCamino;
	return new EnCamino();
}

Etapa *Pedido::cancelar() {
  return new Cancelado();
}
