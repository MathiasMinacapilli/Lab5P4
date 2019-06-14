#ifndef _DTEMPLEADO_HPP
#define _DTEMPLEADO_HPP

//Librerias C
#include <string>
using namespace std;

class DtEmpleado {
private:
    int numero;
    string nombre;
public:
    //Constructor
	DtEmpleado();
    DtEmpleado(int numero, string nombre);

    //Destructor
    ~DtEmpleado();

    //Getters
    int getNumero();
    string getNombre();
};

#endif
