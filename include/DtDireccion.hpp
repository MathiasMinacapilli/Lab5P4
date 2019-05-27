#ifndef _DTDIRECCION_HPP
#define _DTDIRECCION_HPP

using namespace std;


class DtDireccion{
private:
   string calle;
   int numeroPuerta;
   string esquina1;
   string esquina2;
public:
    DtDireccion(/* args */);
    ~DtDireccion();
};

class DtApto : public DtDireccion {
    string nombreEdificio;
    int numeroApto;
}

#endif
