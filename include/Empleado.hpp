#ifndef _EMPLEADO_HPP
#define _EMPLEADO_HPP

//Librerias de C
using namespace std;

class Empleado{
private:
    int numero;
    string nombre;
protected:
    Empleado(int numero, string nombre);
public:
    ~Empleado();
    int getNumero();
    string getNombre();
};

#endif
