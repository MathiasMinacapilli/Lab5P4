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
    DtFechaYHora(int hora, int minutos, int segundos);
    ~DtFechaYHora();
};

#endif
