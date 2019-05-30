#ifndef _DTEMPLEADO_HPP
#define _DTEMPLEADO_HPP

//Librerias C
#include <string>
using namespace std;

//Archivos

class DtEmpleado {
private:
    int numero;
    string nombre;
public:
    DtEmpleado(int numero, string nombre);
    int getNumero();
    string getNombre();
    ~DtEmpleado();
};

#endif