#ifndef _DTFECHAYHORA_HPP
#define _DTFECHAYHORA_HPP

//Librerias de C
using namespace std;

//Archivos
#include "DtFecha.hpp"

class DtFechaYHora: public DtFecha {
private:
    int hora;
    int minutos;
    int segundos;
public:
    DtFechaYHora();
    DtFechaYHora(int dia, int mes, int anio, int hora, int minutos, int segundos);
    int getHora();
    int getMinutos();
    int getSegundos();
    ~DtFechaYHora();
    bool operator<=(const DtFechaYHora&);
};

#endif
