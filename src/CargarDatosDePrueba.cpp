//Archivos
#include "../include/.hpp"





void cargarDatosDePrueba() {

    //PRODUCTOS SIMPLES

    DtProductoSimple producto_simple;
    //P1
    producto_simple = DtProductoSimple(1, "Pizza con muzzarella", 130);
    iproducto->ingresarDatosProducto(producto_simple);
    iproducto->ingresarProductoSimple();
    //P2
    producto_simple = DtProductoSimple(2, "Milanesa con guarnición", 230);
    iproducto->ingresarDatosProducto(producto_simple);
    iproducto->ingresarProductoSimple();
    //P3
    producto_simple = DtProductoSimple(3, "Coca Cola 1.25L", 95);
    iproducto->ingresarDatosProducto(producto_simple);
    iproducto->ingresarProductoSimple();
    //P4
    producto_simple = DtProductoSimple(4, "Empanada Capresse", 72);
    iproducto->ingresarDatosProducto(producto_simple);
    iproducto->ingresarProductoSimple();
    //P5
    producto_simple = DtProductoSimple(5, "Flan con dulce de leche", 110);
    iproducto->ingresarDatosProducto(producto_simple);
    iproducto->ingresarProductoSimple();

    //MENÚES

    //P6
    iproducto->ingresarDatosMenu(6, "Combo Pizza");
    DtProducto producto = DtProducto(1, "Pizza", 130);
    DtProductoCantidad producto_cantidad = DtProductoCantidad(producto, 1);
    iproducto->seleccionarProductoYCantidad(producto_cantidad);
    producto = DtProducto(3, "Coca Cola 1.25L", 95);
    producto_cantidad = DtProductoCantidad(producto, 1);
    iproducto->seleccionarProductoYCantidad(producto_cantidad);
    iproducto->ingresarMenu();
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




















}
