//Archivos
#include "../include/Transporte.hpp"

std::ostream& operator<<(std::ostream & os, Transporte t){
  switch (t) {
  case Pie:
      os << "Pie";
      break;
  case Bici:
      os << "Bici";
      break;
  case Moto:
      os << "Moto";
  }
  return os;
}