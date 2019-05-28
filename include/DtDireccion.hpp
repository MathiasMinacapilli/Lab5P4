#ifndef _DTDIRECCION_HPP
#define _DTDIRECCION_HPP

//Librerias de C
using namespace std;

//Archivos 

class DtDireccion{
private:
   string calle;
   int numeroPuerta;
   string esquina1;
   string esquina2;
public:
    DtDireccion(string calle, int numeroPuerta, string esquina1, string esquina2);
    ~DtDireccion();
};

#endif
