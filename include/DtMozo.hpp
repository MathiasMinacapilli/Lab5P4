#ifndef _DTMOZO_HPP
#define _DTMOZO_HPP

#include "DtEmpleado.hpp";

class DtMozo: public DtEmpleado {
private:

public:
    DtMozo(int numero, string nombre);
    ~DtMozo();
};

#endif