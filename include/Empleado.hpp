#ifndef _EMPLEADO_HPP
#define _EMPLEADO_HPP

using namespace std;

class Empleado{
private:
    int numero;
    string nombre;
protected:
    Empleado(int numero, string nombre);
public:
    ~Empleado();
};

#endif
