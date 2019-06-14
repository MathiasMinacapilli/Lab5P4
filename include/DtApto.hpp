#ifndef _DTAPTO_HPP
#define _DTAPTO_HPP

//Librerias de C
#include <string>
using namespace std;

//Archivos
#include "DtDireccion.hpp"

class DtApto : public DtDireccion {
private:
    string nombreEdificio;
    int numeroApto;
public:
    //Constructor
	DtApto();
    DtApto(string calle, int numeroPuerta, string esquina1, string esquina2, string nombreEdificio, int numeroApto);

    //Destructor
    ~DtApto();

    //Getters
    string getNombreEdificio();
    int getNumeroApto();
};

#endif
