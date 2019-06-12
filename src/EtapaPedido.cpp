//Archivos
#include "../include/EtapaPedido.hpp"

std::ostream& operator<<(std::ostream & os, EtapaPedido etapa){
  switch (etapa) {
  case Pedido:
      os << "Pedido";
      break;
  case EnCamino:
      os << "En Camino";
      break;
  case Recibido:
      os << "Recibido";
      break;
  case Cancelado:
      os<< "Cancelado"
      break;
  }
  return os;
}