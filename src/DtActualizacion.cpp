//Archivos
#include "../include/DtActualizacion.hpp"


//constructor
DtActualizacion::DtActualizacion(DtFechaYHora fechaYHora, string nombre, string telefono, map<int, DtProductoCantidad> datosProductos, EtapaPedido etapaActual) {
    this->fechaYHora = fechaYHora;
    this->nombre = nombre;
    this->telefono = telefono;
    this->datosProductos = datosProductos;
    this->etapaActual = etapaActual;
}
    
//getters
DtFechaYHora DtActualizacion::getFechaYHora() const{
    return this->fechaYHora;
}

string DtActualizacion::getNombre() {
    return this->nombre;
}

string DtActualizacion::getTelefono() {
    return this->telefono;
}

map<int, DtProductoCantidad> DtActualizacion::getDatosProductos() const{
    return this->datosProductos;
}

EtapaPedido DtActualizacion::getEtapaActual() {
    return this->etapaActual;
}

//sobrecarga de operador <
bool DtActualizacion::operator<(const DtActualizacion &act2) const{
    DtFechaYHora dt_fecha_hora1 = this->fechaYHora;
    DtFechaYHora dt_fecha_hora2 = act2.getFechaYHora();
    return (dt_fecha_hora1 <= dt_fecha_hora2);
}

//sobrecarga de operador cout<<
ostream &operator<< (ostream& os, DtActualizacion dt_act){
    os<< "Fecha: \n" <<dt_act->getFechaYHora()
    << "\nCliente: " << dt_act->getNombre()
    << "\n Telefono: " << dt_act->getTelefono(); 
    map<int, DtProductoCantidad>::iterator it;
    for (it = dt_act->getDatosProductos().begin(); it != dt_act->getDatosProductos().end(); ++it)
        os<< it->second;
    os << "Nombre repartidor: " << dt_act->getNombreRepartidor();
    os << "Etapa del pedido: " << dt_act->getEtapaActual();

}


//destructor
DtActualizacion::~DtActualizacion() {}
