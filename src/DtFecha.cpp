
#include "../include/DtFecha.hpp";

DtFecha::DtFecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

int DtFecha::getDia() {
    return this->dia;
}

int DtFecha::getMes() {
    return this->mes;
}

int DtFecha::getAnio() {
    return this->anio;
}

DtFecha::~DtFecha() {}

bool DtFecha::operator==(const DtFecha &f2) {
    return ((this->getAnio() == f2.getAnio()) && 
        (this->getMes() == f2.getMes()) && 
        (this->getDia() == f2.getDia()));
}
