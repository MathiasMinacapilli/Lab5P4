//Librerias de C
#include <set>
#include <map>

//Archivos
#include "../include/ControladorMesa.hpp"

//inicializacion instancia patron Singleton
ControladorMesa *ControladorMesa::instance = nullptr;

//constructor
ControladorMesa::ControladorMesa(){}

bool ControladorMesa::existeMesa(int num_mesa) {
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

//Facturación de una venta - generarFactura() - ControladorVenta

void ControladorMesa::finalizarVenta() {
  mesa_recordada -> terminarVenta();
}

//Quitar Producto a una Venta - getProductosVenta() - ControladorVenta

VentaLocal* ControladorMesa::obtenerVenta(int numero) {
    map<int, Mesa*>::iterator it = mesas.find(numero);
    VentaLocal *ve = nullptr;
    if (it != mesas.end()) {
        ve = (it -> second) -> getVentaActual();
        this->mesa_recordada = it->second;
    } else {
      throw new invalid_argument("No existe una mesa con el numero ingresado");
    }
    return ve;
}

//Iniciar Venta en Mesas

set<int> ControladorMesa::getMesasMozoSinVentas(int num_mozo) {
    ControladorEmpleado* cont_empleado = ControladorEmpleado::getInstance();
    map<int, Mozo*> mozos = cont_empleado->getMozos();
    map<int, Mozo*>::iterator it = mozos.find(num_mozo);
    if(it != mozos.end()) {
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
    } else {
        throw new invalid_argument("El codigo del mozo que ingreso no es correcto.");
    }
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

void ControladorMesa::agregarMesa(Mesa *m) {
    if (!existeMesa(m -> getNum()))
        mesas.insert(pair<int, Mesa*>(m -> getNum(), m));
    else
        throw new invalid_argument ("Ya existe ese número de mesa");
}

void ControladorMesa::iniciarVenta() {
  ControladorVenta* cont_venta = ControladorVenta::getInstance();
  VentaLocal* ve = cont_venta -> crearVenta();
  set<int>::iterator it_selecc;
  for (it_selecc = this->mesas_seleccionadas.begin(); it_selecc != this->mesas_seleccionadas.end(); ++it_selecc) {
    map<int, Mesa*>::iterator it_mesas = mesas.find(*it_selecc);
    if (it_mesas != mesas.end()) {
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

//Caso de uso: Asignar automaticamente mozos a mesas
map<int, Mesa*> ControladorMesa::getMesas() {
    return this->mesas;
}

set<int> ControladorMesa::getNumeroMesas() {
    map<int, Mesa*>::iterator it;
    set<int> res;
    res.clear();
    for (it = this -> mesas.begin(); it != this -> mesas.end(); ++it)
        res.insert(it -> first);
    return res;
}

//Caso de uso: Asignar automaticamente mozos a mesas
/* Se retorna una coleccion de DtMesasMozo el cual contiene el codigo de un mozo
y el conjunto de mesas (los numeros) asignados a el.
El método consiste en asignar PISO(Me/Mo) mesas a cada mozo (donde Me es la cantidad
de mesas y Mo la de mozos) y el resto (de la división entera) de las mesas se
asignan aleatoriamente a los mozos. */
map<int, DtMesasMozo> ControladorMesa::asignarMozosAMesas() {
    map<int, DtMesasMozo> col_ret; //Coleccion a retornar
	ControladorEmpleado* cont_empleado = ControladorEmpleado::getInstance();
	map<int, Mozo*> mozos = cont_empleado->getMozos();
	map<int, Mozo*>::iterator it_mozos = mozos.begin();
	map<int, Mesa*>::iterator it_mesas = this->mesas.begin();
	int cant_mesas = this->mesas.size();
	int cant_mozos = mozos.size();
    double cant_mesas_a_asignar = 0;
    if(cant_mozos != 0) {
	    cant_mesas_a_asignar = floor(cant_mesas/cant_mozos);
    } else {
        throw new invalid_argument("Debe haber al menos un mozo en el sistema para poder realizar esta operación.");
    }
	//Recorro la coleccion de mozos asignandole a cada mozo (en el while)
	//cant_mesas_a_asignar (que es la cuenta piso(me/mo)) mesas.
	for(it_mozos = mozos.begin(); it_mozos != mozos.end(); ++it_mozos) {
        set<int> mesas_mozo;
		double i = 0;
		while(i<cant_mesas_a_asignar) {
			it_mesas->second->setMozo(it_mozos->second);
            mesas_mozo.insert(it_mesas->second->getNum());
			++it_mesas;
			i++;
		}
        DtMesasMozo dt_mesas_mozo = DtMesasMozo(it_mozos->second->getNumero(), mesas_mozo);
        col_ret[it_mozos->second->getNumero()] = dt_mesas_mozo;
	}
	//Si luego de recorrer todos los mozos y asignarle el valor cant_mesas_a_asignar
	//a cada uno aun me quedan mesas por asignar, asigno estas mesas aleatoriamente
	if(it_mesas != this->mesas.end()) {
		it_mozos = mozos.begin();
		while(it_mesas != this->mesas.end()) {
			it_mesas->second->setMozo(it_mozos->second);
            //Agrego el numero de la mesa al datatype (accedo con getMesas()) que contiene
            //el conjunto de las mesas del mozo
            set<int> mesas_mozo = col_ret[it_mozos->second->getNumero()].getMesas();
            mesas_mozo.insert(it_mesas->second->getNum());
            DtMesasMozo dt_mesas_mozo = DtMesasMozo(col_ret[it_mozos->second->getNumero()].getCodigoMozo(), mesas_mozo);
            col_ret[it_mozos->second->getNumero()] = dt_mesas_mozo;
			++it_mesas;
			++it_mozos;
			if(it_mozos == mozos.end()) { //Para hacerlo circular
				it_mozos = mozos.begin();
			}
		}
	}
    return col_ret;
}
