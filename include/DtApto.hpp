#ifndef _DTAPTO_HPP
#define _DTAPTO_HPP

//Librerias de C
using namespace std;
#include <string>

//Archivos
#include "DtDireccion.hpp"

class DtApto : public DtDireccion {
private:
    string nombreEdificio;
    int numeroApto;
public:
	DtApto();
    DtApto(string calle, int numeroPuerta, string esquina1, string esquina2, string nombreEdificio, int numeroApto);
    string getNombreEdificio();
    int getNumeroApto();
    ~DtApto();
};

#endif
