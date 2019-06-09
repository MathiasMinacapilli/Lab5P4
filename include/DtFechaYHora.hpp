#ifndef _DTFECHAYHORA_HPP
#define _DTFECHAYHORA_HPP

//Librerias de C
#include <ostream>
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
    int getHora() const;
    int getMinutos() const;
    int getSegundos() const;
    ~DtFechaYHora();
    bool operator<=(const DtFechaYHora&);
};

ostream &operator<< (ostream&, DtFechaYHora);

#endif
