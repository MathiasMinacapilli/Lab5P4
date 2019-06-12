#ifndef _ETAPAPEDIDO_HPP
#define _ETAPAPEDIDO_HPP

#include <iostream>

enum EtapaPedido {pedido, enCamino, recibido, cancelado};

std::ostream& operator<<(std::ostream & os, EtapaPedido etapa);

#endif
