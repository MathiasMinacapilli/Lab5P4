#ifndef _DTFECHA_HPP
#define _DTFECHA_HPP

class DtFecha {
private:
    int dia;
    int mes;
    int anio;
public:
    DtFecha(int dia, int mes, int anio);
    int getDia();
    int getMes();
    int getAnio();
    ~DtFecha();
};

#endif