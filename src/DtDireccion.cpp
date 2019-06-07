
#include "../include/DtDireccion.hpp";

DtDireccion::DtDireccion(string calle, int numeroPuerta, string esquina1, string esquina2) {
    this->calle = calle;
    this->numeroPuerta = numeroPuerta;
    this->esquina1 = esquina1;
    this->esquina2 = esquina2;
}

string DtDireccion::getCalle() {
    return this->calle;
}

int DtDireccion::getNumeroPuerta() {
    return this->numeroPuerta;
}

string DtDireccion::getEsquina1() {
    return this->esquina1;
}

string DtDireccion::getEsquina2() {
    return this->esquina2;
}

DtDireccion::~DtDireccion() {}