#ifndef _ETAPA_HPP
#define _ETAPA_HPP

//Librerias de C
using namespace std;

class Etapa {
protected:
     Etapa();
public:
    virtual Etapa *avanzarEtapa() = 0;
    virtual Etapa *cancelar() = 0;
    ~Etapa();
};

#endif
