//Archivos
#include "../include/DtDireccion.hpp"

DtDireccion::DtDireccion(){}

DtDireccion::DtDireccion(string calle, int numeroPuerta, bool esq, string esquina1, string esquina2) {
    this->calle = calle;
    this->numeroPuerta = numeroPuerta;
    this->hay_esquinas = esq;
    this->esquina1 = esquina1;
    this->esquina2 = esquina2;
}

string DtDireccion::getCalle() {
    return this->calle;
}

int DtDireccion::getNumeroPuerta() {
    return this->numeroPuerta;
}

bool DtDireccion::hayEsquinas(){
    return this->hay_esquinas;
}

string DtDireccion::getEsquina1() {
    return this->esquina1;
}

string DtDireccion::getEsquina2() {
    return this->esquina2;
}

DtDireccion::~DtDireccion() {}

ostream& operator<<(ostream & os, DtDireccion dir){
    os << dir.getCalle() << " " << dir.getNumeroPuerta();
    if (dir.hayEsquinas())
        os << ", entre " << dir.getEsquina1() << " y " << dir.getEsquina2();
    return os;
}
