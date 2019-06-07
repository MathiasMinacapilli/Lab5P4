//Archivos
#include "../include/DtMesasMozo.hpp"

DtMesasMozo::DtMesasMozo(int codigoMozo, set<int> mesas) {
    this->codigoMozo = codigoMozo;
    this->mesas = mesas;
}

int DtMesasMozo::getCodigoMozo() {
    return this->codigoMozo;
}

set<int> DtMesasMozo::getMesas() {
    return this->mesas;
}

DtMesasMozo::~DtMesasMozo() {}
