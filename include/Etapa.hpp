#ifndef _ETAPA_HPP
#define _ETAPA_HPP

//Librerias de C
using namespace std;

class Etapa {
private:
     Etapa();
public:
    virtual Etapa avanzarEtapa() = 0;
    virtual void cancelar() = 0;
    ~Etapa();
};

#endif
