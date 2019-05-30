
#include "../include/DtFechaYHora.hpp";

DtFechaYHora::DtFechaYHora(int dia, int mes, int anio, int hora, int minutos, int segundos) 
: DtFecha(dia, mes, anio) {
    this->hora = hora;
    this->minutos = minutos;
    this->segundos = segundos;
}

int DtFechaYHora::getHora() {
    return this->hora;
}

int DtFechaYHora::getMinutos() {
    return this->minutos;
}

int DtFechaYHora::getSegundos() {
    return this->segundos;
}

DtFechaYHora::~DtFechaYHora() {}

