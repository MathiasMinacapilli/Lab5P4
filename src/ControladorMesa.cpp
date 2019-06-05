//Librerias de C
using namespace std;
#include <set>
#include <map>

//Archivos
#include "../include/ControladorMesa.hpp"

map<int, DtMesasMozo> ControladorMesa::asignarMozosAMesas() {
    
}

void ControladorMesa::cancelarVenta() {
  //Quedó como pregunta que es liberar la memoria
}

void ControladorMesa::finalizarVenta() {
  mesa_recordada -> terminarVenta();
}

set<int> ControladorMesa::getMesasMozoSinVentas(int num_mozo) {
  map<int, Mesa*>::iterator it;
  set<int> mozos_sin_venta;
  mozos_sin_venta.clear();
  for (it = mesas.begin(); it != mesas.end(); ++it) {
    bool sin_venta := (it -> second) -> noTieneVentas();
    if (sin_venta) {
      bool es_del_mozo = (it -> second) -> esDelMozo(num_mozo);
      if (es_del_mozo) {
        mozos_sin_venta.insert((it -> second) -> getNumero());
      }
    }
  }
  return mozos_sin_venta;
}

void ControladorMesa::seleccionarMesasVenta(set<int> posibles_mesas) {
  this -> posibles_mesas = posibles_mesas;
}

set<int> ControladorMesa::getMesasSeleccionadas() {
  set<int>::iterator it;
  set<int> mesas_a_seleccionar;
  mesas_a_seleccionar.clear();
  for (it = posibles_mesas.begin(); it != posibles_mesas.end(); ++it) {
    if (mesas.find(*it) != mesas.end()) {
      mesas_a_seleccionar.insert(*it);
    }
  }
  mesas_seleccionadas = mesas_a_seleccionar;
  return mesas_a_seleccionar;
}

void ControladorMesa::iniciarVenta() {
  ControladorVenta* cont_venta = ControladorVenta::getInstance();
  Venta* ve = cont_venta -> crearVenta();
  set<int>::iterator it_selecc;
  for (it_selecc = mesas_seleccionadas.begin(); it_selecc != mesas_seleccionadas.end(); ++it) {
    map<int, Mesa*>::iterator it_mesas = mesas.find(*it_selecc);
    if (it_mesas != mesas.begin()) {
      (it_mesas -> second) -> setVentaActual(ve);
    }
  }
  ControladorEmpleado* cont_empleado = ControladorEmpleado::getInstance();
  Mozo* mozo_a_asignar = cont_empleado -> getMozo//QUE MOZO, FALTA TERMINAR
}