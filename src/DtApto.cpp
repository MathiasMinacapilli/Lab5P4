//Archivos
#include "../include/DtApto.hpp"

//constructor por defecto
DtApto::DtApto():DtDireccion(){}

//constructor por defecto
DtApto::DtApto(string calle, int numeroPuerta, bool hay_esquina, string esquina1, string esquina2, string nombreEdificio, int numeroApto)
:DtDireccion(calle, numeroPuerta, hay_esquina, esquina1, esquina2) {
    this->nombreEdificio = nombreEdificio;
    this->numeroApto = numeroApto;
}

string DtApto::getNombreEdificio() {
    return this->nombreEdificio;
}

int DtApto::getNumeroApto() {
    return this->numeroApto;
}

DtApto::~DtApto() {}
