#ifndef _ETAPA_HPP
#define _ETAPA_HPP

class Etapa {
protected:
     Etapa();
public:
    virtual Etapa *avanzarEtapa() = 0;
    virtual Etapa *cancelar() = 0;
    virtual ~Etapa() {};
};

#endif
