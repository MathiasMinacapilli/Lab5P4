//Archivos
#include "../include/EnCamino.hpp"
#include "../include/Recibido.hpp"
#include "../include/Cancelado.hpp"

EnCamino::EnCamino() : Etapa() {
}

EnCamino::~EnCamino() {
}

Etapa *EnCamino::avanzarEtapa(EtapaPedido &etapa_pedido) {
	etapa_pedido = recibido;
	Etapa* nueva = new Recibido();
	return nueva;
}

Etapa *EnCamino::cancelar() {
	Etapa* nueva = new Cancelado();
	return nueva;
}
