//Archivos
#include "../include/DtFecha.hpp"

DtFecha::DtFecha() {}

DtFecha::DtFecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

int DtFecha::getDia() const{
    return this->dia;
}

int DtFecha::getMes() const {
    return this->mes;
}

int DtFecha::getAnio() const{
    return this->anio;
}

DtFecha::~DtFecha() {}

bool DtFecha::operator==(const DtFecha &f2) {
    return ((this->getAnio() == f2.getAnio()) && 
        (this->getMes() == f2.getMes()) && 
        (this->getDia() == f2.getDia()));
}
