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

DtFechaYHora::~DtFechaYHora() {}
