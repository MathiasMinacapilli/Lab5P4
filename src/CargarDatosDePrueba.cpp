//Archivos
#include "../include/.hpp"





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

    ///
    //
    ///
    //
    //
    //SEGUIR ACA, TENER CUIDADO CON EL MENU, CAMBIAR DE DTPRODCUTO A MENU OO A PRODUCTO
    //
    //
    //
    //
    //
    Menu *p6 = new Menu(6, "Combo Pizza")
    iproducto -> ingresarDatosMenu(6, "Combo Pizza");
    DtProducto producto = DtProducto(1, "Pizza", 130);
    DtProductoCantidad producto_cantidad = DtProductoCantidad(producto, 1);
    iproducto -> seleccionarProductoYCantidad(producto_cantidad);
    producto = DtProducto(3, "Coca Cola 1.25L", 95);
    producto_cantidad = DtProductoCantidad(producto, 1);
    iproducto -> seleccionarProductoYCantidad(producto_cantidad);
    iproducto -> ingresarMenu();
    //P7
    iproducto->ingresarDatosMenu(7, "Combo Empanadas");
    producto = DtProducto(3, "Coca Cola 1.25L", 95);
    producto_cantidad = DtProductoCantidad(producto, 1);
    iproducto->seleccionarProductoYCantidad(producto_cantidad);
    producto = DtProducto(4, "Empanada Capresse", 72);
    producto_cantidad = DtProductoCantidad(producto, 3);
    iproducto->seleccionarProductoYCantidad(producto_cantidad);
    iproducto->ingresarMenu();

    //MOZOS

    //M1
    iempleado->ingresarNombreEmpleado("Juan Pedro");
    iempleado->ingresarMozo();
    //M2
    iempleado->ingresarNombreEmpleado("Johnny");
    iempleado->ingresarMozo();
    //M3
    iempleado->ingresarNombreEmpleado("José");
    iempleado->ingresarMozo();

    //REPARTIDORES

    //R1
    iempleado->ingresarNombreEmpleado("Tito");
    Transporte t = Bici;
    iempleado->seleccionarTransporte(t);
    iempleado->ingresarRepartidor();
    //R2
    iempleado->ingresarNombreEmpleado("Raúl");
    t = Moto;
    iempleado->seleccionarTransporte(t);
    iempleado->ingresarRepartidor();
    //R3
    iempleado->ingresarNombreEmpleado("Tiki Gelana");
    t = Pie;
    iempleado->seleccionarTransporte(t);
    iempleado->ingresarRepartidor();

    //MESAS
    Mesa *mesa;
    ControladorMesa *cont_mesa = imesa -> getInstance();
    //MM1
    mesa = Mesa(1, nullptr, nullptr);
    cont_mesa -> agregarMesa(mesa);
    //MM2
    mesa = Mesa(2, nullptr, nullptr);
    cont_mesa -> agregarMesa(mesa);
    //MM3
    mesa = Mesa(3, nullptr, nullptr);
    cont_mesa -> agregarMesa(mesa);
    //MM4
    mesa = Mesa(4, nullptr, nullptr);
    cont_mesa -> agregarMesa(mesa);
    //MM5
    mesa = Mesa(5, nullptr, nullptr);
    cont_mesa -> agregarMesa(mesa);
    //MM6
    mesa = Mesa(6, nullptr, nullptr);
    cont_mesa -> agregarMesa(mesa);
    //MM7
    mesa = Mesa(7, nullptr, nullptr);
    cont_mesa -> agregarMesa(mesa);

    //CLIENTES

    ControladorCliente *cont_cliente = icliente -> getInstance();
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

    VentaADomicilio *venta_domicilio;
    ControladorVenta *cont_venta = iventa -> getInstance();
    ControladorEmpleado *cont_empleado = iempleado -> getInstance();
    //V4
    venta_domicilio = new VentaADomicilio(4, 0, nullptr, EnCamino, "Martin");
    cont_empleado -> seleccionarRepartidor(4);

    venta_domicilio -> agregarProductoAVenta()





    //V5
    venta_domicilio = new VentaADomicilio(5, 0, nullptr, Recibido, "Martin");
    cont_empleado -> seleccionarRepartidor(5);


    //V6
    venta_domicilio = new VentaADomicilio(6, 0, nullptr, EnCamino, "Vladimir");
    cont_empleado -> seleccionarRepartidor(4);














}
