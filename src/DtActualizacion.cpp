//Archivos
#include "../include/DtActualizacion.hpp"


//constructor
DtActualizacion::DtActualizacion(DtFechaYHora fechaYHora, string nombre, string telefono, string nombre_repartidor, map<int, DtProductoCantidad> datosProductos, EtapaPedido etapaActual) {
    this->fechaYHora = fechaYHora;
    this->nombre = nombre;
    this->telefono = telefono;
    this->nombre_repartidor = nombre_repartidor;
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

string DtActualizacion::getNombreRepartidor(){
    return this->nombre_repartidor;
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
    os<< " Fecha: " <<dt_act.getFechaYHora() << "\n"
        << " Cliente: " << dt_act.getNombre() << "\n"
        << " Teléfono: " << dt_act.getTelefono() << "\n"
        << " Repartidor: " << dt_act.getNombreRepartidor() << "\n";
    map<int, DtProductoCantidad>::iterator it;
    map<int, DtProductoCantidad> datos_prods = dt_act.getDatosProductos();
    for (it = datos_prods.begin(); it != datos_prods.end(); ++it)
        os << "    " << it->second << "\n";
    os << " Etapa del pedido: " << dt_act.getEtapaActual();
    return os;

}


//destructor
DtActualizacion::~DtActualizacion() {}
