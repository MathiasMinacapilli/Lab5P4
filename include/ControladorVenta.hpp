#ifndef _CONTROLADORVENTA_HPP
#define _CONTROLADORVENTA_HPP

//Librerias de C
#include <map>
#include <set>
#include <vector>
using namespace std;

//Archivos
#include "IVenta.hpp"
#include "VentaLocal.hpp"
#include "VentaADomicilio.hpp"
#include "DtFecha.hpp"
//#include "DtFactura.hpp"

class ControladorVenta : public IVenta {
private:
    //Constructor
    ControladorVenta();
    //Instancia patrón Singleton
    static ControladorVenta *instance;
    //Colección de Ventas
    map<int, VentaLocal *> ventasLocales;
    map<int, VentaADomicilio *> ventasDomicilio;

    int numero_mesa; //AGREGAR PRODUCTO A UNA VENTA - ingresarNumeroMesa - numero
    Producto* prod; //AGREGAR PRODUCTO A UNA VENTA - seleccionarProdYCant - prod
    int cantidad; //AGREGAR PRODUCTO A UNA VENTA - seleccionarProdYCant - producto_cantidad.getCantidad
    Venta* v; //QUITAR PRODUCTO A UNA VENTA - getProductosVenta - v
    int numero_venta; //INICIAR VENTA EN MESAS - iniciarVenta
    DtFecha fecha_venta; //RESUMEN FACTUACION 1 DIA DADA LA FECHA - ingresarFecha - fecha
    string telefono_recordado; //VENTA A DOMICILIO - ingresarTelefono - telefono
    VentaADomicilio* venta_domicilio; //VENTA A DOMICILIO -
public:
    static ControladorVenta *getInstance();

    //BAJA PRODUCTO - eliminarProducto - ControladorProducto
    bool estaEnVentaSinFacturar(Producto *p);

    //INICIAR VENTA EN MESAS - iniciarVenta - ControladorMesa
    VentaLocal *crearVenta();

    //AGREGAR PRODUCTO A UNA VENTA
    void ingresarNumeroMesa(int numero);
    map<int, DtProducto> obtenerProductosDisponibles();
    void seleccionarProdYCant(DtProductoCantidad producto_cantidad);
    void agregarProductoAVenta();
    void cancelarProductoAVenta();

    //QUITAR PRODUCTO A UNA VENTA
    map<int, DtProducto> getProductosVenta (int numMesa);
    //seleccionarProdYCant
    void eliminarProductoDeVenta();
    void cancelarEliminarProductoDeVenta();

    //FACTURACION DE UNA VENTA
    //ingresarNumeroMesa
    void ingresarPorcentajeDescuento(float descuento);
    DtFactura* generarFactura();

    //VENTA A DOMICILIO
    bool ingresarTelefono(string telefono);
    //obtenerProductosDisponibles
    void almacenarProducto(DtProductoCantidad prod_y_cant);
    map<int, Repartidor*> obtenerRepartidores();
    void elegirRepartidor(int numero_repartidor);
    void crearVentaADomicilio(bool quiere_repartidor);
    void cancelarVentaADomicilio();
    DtFactura* generarFacturaDomicilio();

    //CONSULTAR ACTUALIZACIONES PEDIDOS A DOMICILIO -- SUBSCRIBIR -- DES-SUBSCRIBIR
    void subscribirCliente(string telefono);
    void desSubscrirCliente(string telefono);

    //RESUMEN FACTURACION DE 1 DIA DADA LA FECHA
    void ingresarFecha(DtFecha fecha);
    map<int, DtFactura> getFacturasYTotalFecha(float &totalfacturado);

    //CONSULTAR ACTUALIZACIONES DE PEDIDOS A DOMICILIO POR PARTE DEL ADMINISTRADOR
    vector<DtActualizacion> getListadoActualizaciones();

    //cargarDatosDePrueba
    void aumentarNumeroVenta();
};

#endif
