//Librerias de C
#include <set>
#include <map>

//Archivos
#include "../include/ControladorMesa.hpp"

//inicializacion instancia patron Singleton
ControladorMesa *ControladorMesa::instance = nullptr;

//constructor
ControladorMesa::ControladorMesa(){}

bool existeMesa(int num_mesa) {
    map<int, Mesa*>::iterator it;
    for (it = mesas.begin(); it != mesas.end(); ++it) {
        if ((it -> second) -> getNum() == num_mesa) {
            return true;
        }
    }
    return false;
}

//devolver instancia patron Singleton
ControladorMesa *ControladorMesa::getInstance(){
  if (instance == nullptr)
    instance = new ControladorMesa();
  return instance;
}

//Asignar automáticamente mozos a mesas

map<int, DtMesasMozo> ControladorMesa::asignarMozosAMesas() {
    //FALTAA , TENEMOS DUDA
  //
  //
  //
  map<int, DtMesasMozo> res;
  res.clear();
  return res;
}

//Facturación de una venta - generarFactura() - ControladorVenta

void ControladorMesa::finalizarVenta() {
  mesa_recordada -> terminarVenta();
}

//Quitar Producto a una Venta - getProductosVenta() - ControladorVenta

Venta* ControladorMesa::obtenerVenta(int numero) {
    map<int, Mesa*>::iterator it = mesas.find(numero);
    Venta* ve = nullptr;
    if (it != mesas.end()) {
        ve = (it -> second) -> getVentaActual();
    }
    return ve;
}

//Iniciar Venta en Mesas

set<int> ControladorMesa::getMesasMozoSinVentas(int num_mozo) {
  map<int, Mesa*>::iterator it;
  set<int> mesas_sin_venta;
  mesas_sin_venta.clear();
  for (it = mesas.begin(); it != mesas.end(); ++it) {
    bool sin_venta = (it -> second) -> noTieneVentas();
    if (sin_venta) {
      bool es_del_mozo = (it -> second) -> esDelMozo(num_mozo);
      if (es_del_mozo) {
        mesas_sin_venta.insert((it -> second) -> getNum());
      }
    }
  }
  num_mozo_recordado = num_mozo;
  return mesas_sin_venta;
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
  VentaLocal* ve = cont_venta -> crearVenta();
  set<int>::iterator it_selecc;
  for (it_selecc = mesas_seleccionadas.begin(); it_selecc != mesas_seleccionadas.end(); ++it_selecc) {
    map<int, Mesa*>::iterator it_mesas = mesas.find(*it_selecc);
    if (it_mesas != mesas.begin()) {
      (it_mesas -> second) -> setVentaActual(ve);
    }
  }
  ControladorEmpleado* cont_empleado = ControladorEmpleado::getInstance();
  Mozo* mozo_a_asignar = cont_empleado -> getMozo(num_mozo_recordado);
  ve -> setMozo(mozo_a_asignar);
}

void ControladorMesa::cancelarVenta() {
  //Quedó como pregunta que es liberar la memoria
}
