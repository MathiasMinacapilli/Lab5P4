//Archivos
#include "../include/EtapaPedido.hpp"

std::ostream& operator<<(std::ostream & os, EtapaPedido etapa){
  switch (etapa) {
  case pedido:
      os << "Pedido";
      break;
  case enCamino:
      os << "En Camino";
      break;
  case recibido:
      os << "Recibido";
      break;
  case cancelado:
      os<< "Cancelado";
      break;
  }
  return os;
}