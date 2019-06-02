#ifndef _ENCAMINO_HPP
#define _ENCAMINO_HPP

//Librerias de C
using namespace std;

//Archivos
#include "Etapa.hpp"

class EnCamino : public Etapa {
public:
    EnCamino();
    ~EnCamino();
    Etapa avanzarEtapa();
    Etapa cancelar();
};

#endif
