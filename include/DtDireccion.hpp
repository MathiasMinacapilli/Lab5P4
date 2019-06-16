#ifndef _DTDIRECCION_HPP
#define _DTDIRECCION_HPP

//Librerias de C
#include <set>
#include <string>
#include <iostream>
using namespace std;

class DtDireccion {
private:
   string calle;
   int numeroPuerta;
   bool hay_esquinas;
   string esquina1;
   string esquina2;
public:
    //Constructor
    DtDireccion();
    DtDireccion(string calle, int numeroPuerta, bool esq, string esquina1, string esquina2);

    //Destructor virtual porque tiene clases derivadas
    virtual ~DtDireccion();

    //Getters
    string getCalle();
    int getNumeroPuerta();
    bool hayEsquinas();
    string getEsquina1();
    string getEsquina2();
};

//Sobrecarga operador cout
ostream &operator<< (ostream&, DtDireccion);

#endif
