#ifndef _IOBSERVERACTUALIZACIONES_HPP
#define _IOBSERVERACTUALIZACIONES_HPP

//Archivos
#include "DtActualizacion.hpp"

class IObserverActualizaciones {
public:
	virtual void notificar(DtActualizacion actualizacion) = 0;
};

#endif
