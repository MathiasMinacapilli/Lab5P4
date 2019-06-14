#ifndef _MOZO_HPP
#define _MOZO_HPP

//Librerias de C
#include <string>
using namespace std;

//Archivos
#include "Empleado.hpp"
#include "Mesa.hpp"

class Mozo: public Empleado {
private:
    //Pseudo atributo que representa la asociacion de Mozo con Mesa con multiplicidad *
    map<int, Mesa*> mesas_mozo;
public:
    //Constructor
    Mozo();
    Mozo(int numero, string nombre);
    
    void agregarMesaAColleccion(Mesa* mesa);

    //Desctructor
    ~Mozo();
};

#endif
