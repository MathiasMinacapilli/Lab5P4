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
#include "../include/EtapaPedido.hpp"
#include "../include/DtActualizacion.hpp"

//Librerias de C
using namespace std;


void cargarDatosDePrueba() {

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

    ControladorVenta *cont_venta = ControladorVenta::getInstance();

    Repartidor *r1 = cont_empleado -> getRepartidor(4);
    Repartidor *r2 = cont_empleado -> getRepartidor(5);
    Cliente *c1 = cont_cliente -> getCliente("098217523");
    Cliente *c2 = cont_cliente -> getCliente("091651249");
    //V4
    EnCamino *enCamino_v4 = new EnCamino();
    VentaADomicilio *v4 = new VentaADomicilio(4, 0, nullptr, enCamino_v4, c2, c2, r1);
    v4 -> agregarProductoAVenta(p7, 5);
    cont_venta -> agregarVentaDomicilio(v4);
    //V5
    Recibido *recibido_v5 = new Recibido();
    VentaADomicilio* v5 = new VentaADomicilio(5, 0, nullptr, recibido_v5, c2, c2, r2);
    v5 -> agregarProductoAVenta(p2, 2);
    cont_venta -> agregarVentaDomicilio(v5);
    //V6
    EnCamino *enCamino_v6 = new EnCamino();
    VentaADomicilio *v6 = new VentaADomicilio(6, 0, nullptr, enCamino_v6, c1, c1, r1);
    v6 -> agregarProductoAVenta(p6, 1);
    cont_venta -> agregarVentaDomicilio(v6);

    //NOTIFICACIONES

    //N4 -- V4 -- PEDIDO
    DtFechaYHora f_n4 = DtFechaYHora(16, 06, 2019, 21, 13, 0);
    map<int, DtProductoCantidad> datos_v4;
    datos_v4.clear();
    map<int, CantidadProducto *> prods_v4 = v4 -> getCants_Productos();
    map<int, CantidadProducto *>::iterator it_v4;
    for (it_v4 = prods_v4.begin(); it_v4 != prods_v4.end(); ++it_v4){
        DtProducto dtp_v4 = it_v4 -> second -> getProducto() -> getDatosProducto();
        DtProductoCantidad dtprod_cant_v4 = DtProductoCantidad(dtp_v4, it_v4 -> second -> getCantidad());
        datos_v4[dtp_v4.getCodigo()] = dtprod_cant_v4;
    }
    EtapaPedido etapa_n4 = pedido;
    DtActualizacion act_n4 = DtActualizacion(f_n4, "Martin", "091651249", datos_v4, etapa_n4);
    v4->agregarActualizacion(act_n4);

    //N1 -- V4 -- EN CAMINO
    DtFechaYHora f_n1 = DtFechaYHora(16, 06, 2019, 21, 27, 0);
    EtapaPedido etapa_n1;
    etapa_n1 = enCamino;
    DtActualizacion act_n1 = DtActualizacion(f_n1, "Martin", "091651249", datos_v4, etapa_n1);
    v4->agregarActualizacion(act_n1);

    //N3 -- V6 -- PEDIDO
    DtFechaYHora f_n3 = DtFechaYHora(16, 06, 2019, 21, 14, 0);
    map<int, DtProductoCantidad> datos_v6;
    datos_v6.clear();
    map<int, CantidadProducto *> prods_v6 = v6 -> getCants_Productos();
    map<int, CantidadProducto *>::iterator it_v6;
    for (it_v6 = prods_v6.begin(); it_v6 != prods_v6.end(); ++it_v6){
        DtProducto dtp_v6 = it_v6 -> second -> getProducto() -> getDatosProducto();
        DtProductoCantidad dtprod_cant_v6 = DtProductoCantidad(dtp_v6, it_v6 -> second -> getCantidad());
        datos_v6[dtp_v6.getCodigo()] = dtprod_cant_v6;
    }
    EtapaPedido etapa_n3 = pedido;
    DtActualizacion act_n3 = DtActualizacion(f_n3, "Vladimir", "098217523", datos_v6, etapa_n3);
    v6->agregarActualizacion(act_n3);

    //N2 -- V6 -- EN CAMINO
    DtFechaYHora f_n2 = DtFechaYHora(16, 06, 2019, 21, 27, 0);
    EtapaPedido etapa_n2 = enCamino;
    DtActualizacion act_n2 = DtActualizacion(f_n2, "Vladimir", "098217523", datos_v6, etapa_n2);
    v4->agregarActualizacion(act_n2);

    //N7 -- V5 -- PEDIDO
    DtFechaYHora f_n7 = DtFechaYHora(16, 06, 2019, 15, 02, 0);
    map<int, DtProductoCantidad> datos_v5;
    datos_v5.clear();
    map<int, CantidadProducto *> prods_v5 = v5 -> getCants_Productos();
    map<int, CantidadProducto *>::iterator it_v5;
    for (it_v5 = prods_v5.begin(); it_v5 != prods_v5.end(); ++it_v5){
        DtProducto dtp_v5 = it_v5 -> second -> getProducto() -> getDatosProducto();
        DtProductoCantidad dtprod_cant_v5 = DtProductoCantidad(dtp_v5, it_v5 -> second -> getCantidad());
        datos_v5[dtp_v5.getCodigo()] = dtprod_cant_v5;
    }
    EtapaPedido etapa_n7 = pedido;
    DtActualizacion act_n7 = DtActualizacion(f_n7, "Martin", "091651249", datos_v5, etapa_n7);
    v5->agregarActualizacion(act_n7);

    //N6 -- V5 -- EN CAMINO
    DtFechaYHora f_n6 = DtFechaYHora(16, 06, 2019, 16, 15, 0);
    EtapaPedido etapa_n6 = enCamino;
    DtActualizacion act_n6 = DtActualizacion(f_n6, "Martin", "091651249", datos_v5, etapa_n6);
    v5->agregarActualizacion(act_n6);

    //N5 -- V5 -- RECIBIDO
    DtFechaYHora f_n5 = DtFechaYHora(16, 06, 2019, 16, 37, 0);
    EtapaPedido etapa_n5 = recibido;
    DtActualizacion act_n5 = DtActualizacion(f_n5, "Martin", "091651249", datos_v5, etapa_n5);
    v5->agregarActualizacion(act_n5);    
}
