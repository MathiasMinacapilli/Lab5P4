#ifndef _ETAPAPEDIDO_HPP
#define _ETAPAPEDIDO_HPP

#include <iostream>

enum EtapaPedido {Pedido, EnCamino, Recibido, Cancelado};

std::ostream& operator<<(std::ostream & os, EtapaPedido etapa);

#endif
