//Archivos
#include "../include/ControladorProducto.hpp"
#include "../include/ProductoSimple.hpp"
#include "../include/Menu.hpp"
#include "../include/ProductoEnMenu.hpp"
#include "../include/ControladorEmpleado.hpp"
#include "../include/Transporte.hpp"
#include "../include/Mesa.hpp"
#include "../include/ControladorMesa.hpp"
#include "../include/ControladorCliente.hpp"
#include "../include/DtApto.hpp"
#include "../include/DtDireccion.hpp"
#include "../include/VentaADomicilio.hpp"
#include "../include/EnCamino.hpp"
#include "../include/Recibido.hpp"

//Librerias de C
using namespace std;


void cargarDatosDePrueba() {
    #if 0
    //PRODUCTOS SIMPLES

    ControladorProducto *cont_producto = ControladorProducto::getInstance();
    //P1
    ProductoSimple *p1 = new ProductoSimple(1, "Pizza con muzzarella", 130);
    cont_producto -> agregarProductoSimple(p1);
    //P2
    ProductoSimple *p2 = new ProductoSimple(2, "Milanesa con guarnición", 230);
    cont_producto -> agregarProductoSimple(p2);
    //P3
    ProductoSimple *p3 = new ProductoSimple(3, "Coca Cola 1.25L", 95);
    cont_producto -> agregarProductoSimple(p3);
    //P4
    ProductoSimple *p4 = new ProductoSimple(4, "Empanada Capresse", 72);
    cont_producto -> agregarProductoSimple(p4);
    //P5
    ProductoSimple *p5 = new ProductoSimple(5, "Flan con dulce de leche", 110);
    cont_producto -> agregarProductoSimple(p5);

    //MENÚES

    //P6
    Menu *p6 = new Menu(6, "Combo Pizza");
    p6 -> agregarProducto(p1, 1);
    p6 -> agregarProducto(p3, 1);
    cont_producto -> agregarMenu(p6);
    //P7
    Menu *p7 = new Menu(7, "Combo Empanadas");
    p7 -> agregarProducto(p3, 1);
    p7 -> agregarProducto(p4, 3);
    cont_producto -> agregarMenu(p7);

    //MOZOS

    ControladorEmpleado *cont_empleado = ControladorEmpleado::getInstance();
    //M1
    cont_empleado -> ingresarNombreEmpleado("Juan Pedro");
    cont_empleado -> ingresarMozo();
    //M2
    cont_empleado -> ingresarNombreEmpleado("Johnny");
    cont_empleado -> ingresarMozo();
    //M3
    cont_empleado -> ingresarNombreEmpleado("José");
    cont_empleado -> ingresarMozo();

    //REPARTIDORES

    //R1
    cont_empleado -> ingresarNombreEmpleado("Tito");
    Transporte t = Bici;
    cont_empleado -> seleccionarTransporte(t);
    cont_empleado -> ingresarRepartidor();
    //R2
    cont_empleado -> ingresarNombreEmpleado("Raúl");
    t = Moto;
    cont_empleado -> seleccionarTransporte(t);
    cont_empleado -> ingresarRepartidor();
    //R3
    cont_empleado -> ingresarNombreEmpleado("Tiki Gelana");
    t = Pie;
    cont_empleado -> seleccionarTransporte(t);
    cont_empleado -> ingresarRepartidor();

    //MESAS

    Mesa *mesa;
    ControladorMesa *cont_mesa = ControladorMesa::getInstance();
    //MM1
    mesa = new Mesa(1, nullptr, nullptr);
    cont_mesa -> agregarMesa(mesa);
    //MM2
    mesa = new Mesa(2, nullptr, nullptr);
    cont_mesa -> agregarMesa(mesa);
    //MM3
    mesa = new Mesa(3, nullptr, nullptr);
    cont_mesa -> agregarMesa(mesa);
    //MM4
    mesa = new Mesa(4, nullptr, nullptr);
    cont_mesa -> agregarMesa(mesa);
    //MM5
    mesa = new Mesa(5, nullptr, nullptr);
    cont_mesa -> agregarMesa(mesa);
    //MM6
    mesa = new Mesa(6, nullptr, nullptr);
    cont_mesa -> agregarMesa(mesa);
    //MM7
    mesa = new Mesa(7, nullptr, nullptr);
    cont_mesa -> agregarMesa(mesa);

    //CLIENTES

    ControladorCliente *cont_cliente = ControladorCliente::getInstance();
    DtApto apto;
    DtDireccion direccion;
    //C1
    apto = DtApto("18 de Julio", 2033, "", "", "Mar Austral", 701);
    cont_cliente -> ingresarDatosCliente("098217523", "Vladimir", apto);
    cont_cliente -> ingresarCliente();
    //C2
    direccion = DtDireccion("Cabildo", 500, "", "");
    cont_cliente -> ingresarDatosCliente("091651249", "Martin", direccion);
    cont_cliente -> ingresarCliente();
    //C3
    apto = DtApto("Avenida Brasil", 842, "", "", "Atlantis", 302);
    cont_cliente -> ingresarDatosCliente("097321590", "Ronaldo", apto);
    cont_cliente -> ingresarCliente();

    //VENTAS A DOMICILIO

    Repartidor *r1 = cont_empleado -> getRepartidor(4);
    Repartidor *r2 = cont_empleado -> getRepartidor(5);
    Cliente *c1 = cont_cliente -> getCliente("098217523");
    Cliente *c2 = cont_cliente -> getCliente("091651249");
    //V4
    EnCamino *enCamino = new EnCamino();
    VentaADomicilio *v4 = new VentaADomicilio(4, 0, nullptr, enCamino, c2, r1);
    v4 -> agregarProductoAVenta(p7, 5);
    //V5
    Recibido *recibido = new Recibido();
    VentaADomicilio* v5 = new VentaADomicilio(5, 0, nullptr, recibido, c2, r2);
    v5 -> agregarProductoAVenta(p2, 2);
    //V6
    EnCamino *enCamino2 = new EnCamino();
    VentaADomicilio *v6 = new VentaADomicilio(6, 0, nullptr, enCamino2, c1, r1);
    v6 -> agregarProductoAVenta(p6, 1);

    //NOTIFICACIONES

    //N1
    
    //N2

    //N3

    //N4

    //N5

    //N6

    //N7
    #endif
}
