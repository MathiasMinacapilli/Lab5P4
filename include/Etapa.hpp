#ifndef _ETAPA_HPP
#define _ETAPA_HPP



class Etapa {
private:
     Etapa(/* args */);
public:
    virtual void avanzarEtapa() = 0;
    virtual void cancelar() = 0; 
    ~Etapa();
};


#endif
