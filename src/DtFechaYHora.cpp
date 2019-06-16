//Librerias de C
#include <string>
using namespace std;

//Archivos
#include "../include/DtFechaYHora.hpp"

DtFechaYHora::DtFechaYHora() {
}

DtFechaYHora::DtFechaYHora(int dia, int mes, int anio, int hora, int minutos, int segundos)
: DtFecha(dia, mes, anio) {
    this -> hora = hora;
    this -> minutos = minutos;
    this -> segundos = segundos;
}

int DtFechaYHora::getHora() const{
    return this -> hora;
}

int DtFechaYHora::getMinutos() const{
    return this -> minutos;
}

int DtFechaYHora::getSegundos() const{
    return this -> segundos;
}

bool DtFechaYHora::operator<=(const DtFechaYHora &f2){
	if (this->getAnio() > f2.getAnio())
		return false;
	else if (this->getAnio() < f2.getAnio())
		return true;
	//son el mismo anio
	else
		if(this->getMes() > f2.getMes())
			return false;
		else if (this->getMes() < f2.getMes())
			return true;
		//son el mismo mes
		else
			if (this->getDia() > f2.getDia())
				return false;
			else if (this->getDia() < f2.getDia())
				return true;
			//son el mismo dia
			else
				if(this->getHora() > f2.getHora())
					return false;
				else if (this->getHora() < f2.getHora())
					return true;
				//son la misma hora
				else
					if (this->getMinutos() > f2.getMinutos())
						return  false;
					else if (this->getMinutos() < f2.getMinutos())
						return true;
					//son el mismo minuto
					else
						if (this->getSegundos() > f2.getSegundos())
							return false;
						else if (this->getSegundos() < f2.getSegundos())
							return true;
						//son iguales
						else return true;

}

ostream &operator<< (ostream& o, DtFechaYHora dtfh) {

    int dia_int = dtfh.getDia();
    string dia = to_string(dia_int);
    if (dia_int < 10)
        dia = "0" + dia;

    int mes_int = dtfh.getMes();
    string mes = to_string(mes_int);
    if (mes_int < 10)
        mes = "0" + mes;

    int hora_int = dtfh.getHora();
    string hora = to_string(hora_int);
    if (hora_int < 10)
        hora = "0" + hora;

    int minutos_int = dtfh.getMinutos();
    string minutos = to_string(minutos_int);
    if (minutos_int < 10)
        minutos = "0" + minutos;

    o << dia << "/" << mes << "/" << dtfh.getAnio() << " - " << hora << ":" << minutos;
	return o;
}

DtFechaYHora::~DtFechaYHora() {}
