#ifndef _EMPLEADO_HPP
#define _EMPLEADO_HPP

//Librerias de C
#include <string>
using namespace std;

class Empleado{
private:
    int numero;
    string nombre;
protected:
    //Constructor protected porque es abstracta
    Empleado(int numero, string nombre);
public:
    //Destructor
    ~Empleado();

    //Getters
    int getNumero();
    string getNombre();
};

#endif
