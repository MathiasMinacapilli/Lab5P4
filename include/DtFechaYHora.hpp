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
    //Constructor
    DtFechaYHora();
    DtFechaYHora(int dia, int mes, int anio, int hora, int minutos, int segundos);

    //Destructor
    ~DtFechaYHora();

    //Getters
    int getHora() const;
    int getMinutos() const;
    int getSegundos() const;

    //Sobrecarga de operador de comparación
    bool operator<=(const DtFechaYHora&);
};

ostream &operator<< (ostream&, DtFechaYHora);

#endif
