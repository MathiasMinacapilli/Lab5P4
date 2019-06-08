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
	DtEmpleado();
    DtEmpleado(int numero, string nombre);
    int getNumero();
    string getNombre();
    ~DtEmpleado();
};

#endif