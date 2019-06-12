//Librerias de C
using namespace std;
#include <ctime>

//Archivos
#include "../include/VentaADomicilio.hpp"

VentaADomicilio::VentaADomicilio(int numero, float descuento, Factura* factura, Etapa* etapa, Cliente *miCliente) : Venta (numero, descuento, factura) {
  this -> etapa = etapa;
  this -> miCliente = miCliente;
}

VentaADomicilio::~VentaADomicilio() {
}

void VentaADomicilio::avanzarEtapaVenta(string nombre_repartidor) {
	Etapa *aux = etapa -> avanzarEtapa();
	//si cambio de etapa
	if (aux != nullptr){
		//avanzo etapa
  		delete this->etapa;
  		this->etapa = aux;
  		//obtengo fecha y hora actuales
  		time_t t = time(0);
    	tm* now = localtime(&t);
    	DtFechaYHora fecha_y_hora = DtFechaYHora(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900, now->tm_hour, now->tm_min, now->tm_sec);


	}
}

void VentaADomicilio::cancelarVenta() {
  Etapa *aux = etapa -> cancelar();
  if (aux != nullptr){
  		delete etapa;
  		etapa = aux;
	}
}
