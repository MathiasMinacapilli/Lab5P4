/*
======================================
▒█▀▀█ █▀▀█ █░░█ █▀▀█ █▀▀█ 　 █▀▀█ ▄▀▀▄
▒█░▄▄ █▄▄▀ █░░█ █░░█ █░░█ 　 █▄▀█ █▄▄░
▒█▄▄█ ▀░▀▀ ░▀▀▀ █▀▀▀ ▀▀▀▀ 　 █▄▄█ ▀▄▄▀
======================================
*/

//Librerias de C
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <algorithm> //all_of
#include <stdlib.h> //system("");
#include <set>
#include <map>
using namespace std;

//Archivos
#include "include/DtProductoSimple.hpp"
#include "include/DtMenu.hpp"
#include "include/ICliente.hpp"
#include "include/IEmpleado.hpp"
#include "include/IMesa.hpp"
#include "include/IProducto.hpp"
#include "include/IVenta.hpp"
#include "include/Fabrica.hpp"

/*
----------------------------------
-------Funciones De Validacion-------
----------------------------------
*/
/* Chequea que la fecha obtenida de la entrada estandar sea valida */
static bool esValidaFecha(int dia, int mes, int anio) {
    return ((1 <= dia) && (dia <= 31)) &&
        ((1 <= mes) && (mes <= 12)) &&
        (0 < anio);
}

/* Obtiene la cedula de la entrada estandar */
static int conseguir_telefono() {
    cout << "Ingrese su número de teléfono. \n"
        << " Teléfono: ";
    int telefono = 0;
    cin >> telefono;
    while ((telefono < 100000000) || (telefono > 1000000000)) {
        cout << "Teléfono no válido. Ingrese su número de teléfono. \n"
            << " Teléfono: ";
        cin >> telefono;
    }
    return telefono;
}

static void es_valido_codigo(int codigo, map<int, DtProducto> productos_disponibles) {
    map<int, DtProducto>::iterator it = productos_disponibles.find(codigo);
    if (it == productos_disponibles.end())
        throw new invalid_argument ("No existe producto con ese código.");
}

static void es_valida_cantidad(int cantidad) {
    if (cantidad <= 0)
        throw new invalid_argument ("Cantidad ingresada no válida.");
}

static void es_valido_numero_repartidor(int numero_repartidor, map<int, Repartidor*> repartidores_disponibles) {
    map<int, Repartidor*>::iterator it = repartidores_disponibles.find(numero_repartidor);
    if (it == repartidores_disponibles.end())
        throw new invalid_argument ("No existe producto con ese código.");
}

static bool confirmacion () {
    string confirmacion;
    cin >> confirmacion;
    bool error = false;
    bool quiero_confirmar = false;
    do {
        cin >> confirmacion;
        if (confirmacion == "S") {
            quiero_confirmar = true;
            error = false;
        } else {
            if (confirmacion == "N") {
                quiero_confirmar = false;
                error = false;
            } else {
                cout << "\nCaracter inválido. Ingrese S o N.\n";
                error = true;
            }
        }
    } while (error);
    return quiero_confirmar;
}

/*
----------------------------------
-------Programa Principal-------
----------------------------------
*/

int main() {
    Fabrica *fabrica = Fabrica::getInstance();
    ICliente *icliente = fabrica -> getICliente();
    IEmpleado *iempleado = fabrica -> getIEmpleado();
    IMesa *imesa = fabrica -> getIMesa();
    IProducto *iproducto = fabrica -> getIProducto();
    IVenta *iventa = fabrica -> getIVenta();
    bool salir = false;
    string msj = "";
    int opcion_menu = 0;
    int opcion_administrador = 0;
    int opcion_mozo = 0;
    int opcion_repartidor = 0;
    int opcion_cliente = 0;
    system("clear");
    while(!salir) {
        system("clear");
        cout << "--------------------" << msj << "-------------------- \n \n"
            << " - Bienvenido. Elija la opción deseada -  \n \n"
            << " 1) Administrador. \n"
            << " 2) Mozo. \n"
            << " 3) Repartidor. \n"
            << " 4) Cliente. \n"
            << " 5) Cargar datos de prueba. \n"
            << " 0) Salir. \n \n"
            << " Opción: ";
        cin >> opcion_menu;
        switch(opcion_menu) {

        /* 1) Administrador. */
        case 1:
            try {
                system("clear");
                cout << "--------------------" << "Administrador" << "-------------------- \n \n"
                    << " - Elija la opción deseada -  \n \n"
                    << " 1) Alta cliente. \n"
                    << " 2) Alta empleado. \n"
                    << " 3) Alta producto. \n"
                    << " 4) Asignar automáticamente mozos a mesas. \n"
                    << " 5) Baja de producto. \n"
                    << " 6) Consultar actualizaciones de pedidos a domicilio. \n"
                    << " 7) Información de un producto. \n"
                    << " 8) Resumen facturación de 1 día dada la fecha. \n"
                    << " 9) Venta a domicilio. \n"
                    << " 10) Ventas de un mozo. \n"
                    << " 0) Salir. \n \n"
                    << " Opción: ";
                cin >> opcion_administrador;
                switch(opcion_administrador) {

                /* 1) Alta cliente. */
                case 1:
                    try {
                    	

                    } catch(exception* e) {

                    }
                    break;
              
                /* 2) Alta empleado. */
                case 2:
                    try {
                        bool quiere_ingresar_empleado = false;
                        do{
                            system("clear");
                            string nombre;
                            cout << "Ingrese el nombre del empleado a ingresar: ";
                            cin >> nombre;
                            iempleado->ingresarNombreEmpleado(nombre);
                            string tipo_empleado;
                            bool tipo_incorrecto = false;
                            do{
                                cout << "Ingrese R para ingresar un repartidor, M para ingresar un mozo: ";
                                cin >> tipo_empleado;
                                bool confirmacion_incorrecta;
                                //se ingresa repartidor
                                if (tipo_empleado == "R"){
                                    tipo_incorrecto = false;
                                    set<Transporte> transportes_disponibles = iempleado->getTransportes();
                                    cout << "Los transportes disponibles son: \n";
                                    set<Transporte>::iterator it_transportes;
                                    for (it_transportes = transportes_disponibles.begin(); it_transportes != transportes_disponibles.end(); ++it_transportes){
                                        Transporte transporte = *it_transportes;
                                        cout << transporte << "\n";
                                    }
                                    cout << "Seleccione su transporte: ";
                                    string t_seleccionado;
                                    Transporte transporte_elegido;
                                    bool transporte_incorrecto = false;
                                    do{
                                        cin >> t_seleccionado;
                                        if (t_seleccionado == "Pie"){
                                            transporte_elegido = Pie;
                                            transporte_incorrecto = false;
                                        }
                                        else
                                            if (t_seleccionado == "Bici"){
                                                transporte_elegido = Bici;
                                                transporte_incorrecto = false;
                                            }
                                            else
                                                if (t_seleccionado == "Moto"){
                                                    transporte_elegido = Moto;
                                                    transporte_incorrecto = false;
                                                }
                                                else{
                                                    cout << "Transporte incorrecto. Por favor seleccione un transporte de los mostrados anteriormente: ";
                                                    transporte_incorrecto = true;
                                                }

                                    }while(transporte_incorrecto);
                                    iempleado->seleccionarTransporte(transporte_elegido);
                                    system("clear");
                                    cout << "Desea confirmar el ingreso del repartidor? S/N \n";
                                    bool confirma_repartidor = confirmacion();
                                    if (confirma_repartidor){
                                        iempleado->ingresarRepartidor();
                                         msj = "Repartidor agregado correctamente";
                                    }
                                    else {
                                        iempleado->cancelarRepartidor();
                                        msj = "Ingreso de repartidor cancelado";
                                    }
                                    
                                }
                                else
                                    //se ingresa mozo
                                    if (tipo_empleado == "M"){
                                        tipo_incorrecto = false;
                                        cout << "Desea confirmar el ingreso del mozo? S/N \n";
                                        bool confirma_mozo = confirmacion();
                                        if (confirma_mozo){
                                            iempleado->ingresarMozo();
                                            msj = "Mozo agregado correctamente";
                                        }
                                        else {
                                            iempleado->cancelarMozo();
                                            msj = "Ingreso de mozo cancelado";
                                        }
                                    }
                                    //tipo incorrecto
                                    else{
                                        cout << "Error. Debe ingresar R o M. \n";
                                        tipo_incorrecto = true;
                                    }
                            }while(tipo_incorrecto);
                            cout << "Desea agregar mas empleados? S/N\n";
                            quiere_ingresar_empleado = confirmacion();                        
                        }while(quiere_ingresar_empleado);
                    } catch(exception *e) {
                        system("clear");
                        msj = e -> what();
                        delete e;
                        break;
                    }
                    break;

                /* 3) Alta producto. */
                case 3:
                    try {
                    bool quiero_agregar_mas = true;
                    int tipo_producto = 0;
                    do {
                        system("clear");
                        cout << "Seleccione el tipo de producto que desea crear:\n"
                            << "1) Producto Simple\n";
                        if(iproducto->existeProductoSimple()) { //Muestro la opcion de crear un menu sii existe al menos un producto simple
                            cout << "2) Menu\n";
                        }
                        cout << "Ingrese la opción: "; cin >> tipo_producto;
                        bool existe_opcion = false;
                        do {
                            int codigo = 0;
                            float precio = 0;
                            string descripcion = "";
                            switch(tipo_producto) {
                            case 1: {
                                //Agregar producto simple
                                system("clear");
                                cout << "Ingrese los datos del producto simple a ingresar:\n"
                                    << "Codigo: "; cin >> codigo;
                                cout << "Descripcion: "; cin >> descripcion;
                                cout << "Precio: "; cin >> precio;
                                DtProductoSimple datos_producto_simple = DtProductoSimple(codigo, descripcion, precio);
                                iproducto->ingresarDatosProducto(datos_producto_simple);
                                do {
                                    string confirmar = "";
                                    cout << "\n¿Está seguro que desea ingresar el producto simple? (S/N): "; cin >> confirmar;
                                    existe_opcion = false;
                                    if(confirmar == "S") {
                                        iproducto->ingresarProductoSimple();
                                        existe_opcion = true;
                                    } else if(confirmar == "N") {
                                        iproducto->cancelarProductoSimple();
                                        existe_opcion = true;
                                    } else {
                                        existe_opcion = false;
                                        cout << "\nLa opción seleccionada no es correcta.";
                                    }
                                } while(!existe_opcion);
                                existe_opcion = true;
                                break;
                            }
                            case 2: {
                                //Agregar menu
                                system("clear");
                                cout << "Ingrese los datos del menu a ingresar:\n"
                                    << "Codigo: "; cin >> codigo;
                                cout << "\nDescripcion: "; cin >> descripcion;
                                iproducto->ingresarDatosMenu(codigo, descripcion);

                                map<int, DtProducto> productos_simples = iproducto->getProductosSimples();
                                map<int, DtProducto>::iterator it;
                                //Muestro los productos simples para que se seleccione cuales integran el menu
                                system("clear");
                                for (it = productos_simples.begin(); it != productos_simples.end(); ++it){
                                    cout << (it->second).getCodigo() << "-" << (it->second).getDescripcion() << "\n";
                                }
                                //Selecciona Productos Simples
                                bool desea_seleccionar_mas = true;
                                do {
                                    int codigo_producto_simple = 0;
                                    int cantidad = 0;
                                    cout << "Codigo: "; cin >> codigo_producto_simple;
                                    cout << "\nCantidad: "; cin >> cantidad;
                                    it = productos_simples.find(codigo_producto_simple);
                                    if(it == productos_simples.end())
                                        throw new invalid_argument("Se ingresó un código incorrecto.");
                                    DtProductoCantidad datos_producto_cantidad = DtProductoCantidad(productos_simples[codigo_producto_simple], cantidad);
                                    iproducto->seleccionarProductoYCantidad(datos_producto_cantidad);
                                    string agregar_mas = "";
                                    cout << "\n¿Desea seguir agregando productos? (S/N): "; cin >> agregar_mas;
                                    if(agregar_mas == "S") {
                                        desea_seleccionar_mas = true;
                                    } else if(agregar_mas == "N") {
                                        desea_seleccionar_mas = false;
                                    } else {
                                        desea_seleccionar_mas = false;
                                        cout << "\nLa opción seleccionada no es correcta.";
                                    }
                                }while(desea_seleccionar_mas);
                                do {
                                    string confirmar = "";
                                    cout << "\n¿Está seguro que desea ingresar el menu? (S/N): "; cin >> confirmar;
                                    existe_opcion = false;
                                    if(confirmar == "S") {
                                        iproducto->ingresarMenu();
                                        existe_opcion = true;
                                    } else if(confirmar == "N") {
                                        iproducto->cancelarMenu();
                                        existe_opcion = true;
                                    } else {
                                        existe_opcion = false;
                                        cout << "\nLa opción seleccionada no es correcta.";
                                    }
                                } while(!existe_opcion);
                                existe_opcion = false;
                                break;
                            }
                            default:
                                existe_opcion = false;
                            }
                        } while(!existe_opcion);
                        do {
                            string confirmar = "";
                            cout << "¿Desea seguir creando productos?: (S/N)"; cin >> confirmar;
                            bool existe_opcion = false;
                            if(confirmar == "S") {
                                existe_opcion = true;
                            } else if(confirmar == "N") {
                                existe_opcion = true;
                                quiero_agregar_mas = false;
                            } else {
                                existe_opcion = false;
                                cout << "\nLa opción seleccionada no es correcta.";
                            }
                        } while(!existe_opcion);
                    } while(quiero_agregar_mas);
                } catch(exception* e) {
                    cout << e->what();
                }
                    break;

                /* 4) Asignar automáticamente mozos a mesas. */
                #if 0
                case 4:
                    try {

                    } catch(exception* e) {

                    }
                    break;
                #endif
                /* 5) Baja de producto. */
                case 5:
                    try {
                        map<int, DtProducto> productos_disponibles = iproducto -> getProductosDisponibles();
                        map<int, DtProducto>::iterator it;
                        for (it = productos_disponibles.begin(); it != productos_disponibles.end(); ++it){
                            cout << (it -> second).getCodigo()
                                << " - "
                                << (it -> second).getDescripcion()
                                << "\n";
                        }
                        cout << "\nIngrese el código del producto que desea eliminar. \n"
                            << " Código: ";
                        int codigo;
                        cin >> codigo;
                        iproducto -> seleccionarProducto(codigo);
                        cout << "\nUsted ingresó el código: "
                            << codigo
                            << "\nDesea eliminar el producto? Ingrese S o N.\n";
                        string confirmacion;
                        bool error = false;
                        bool se_elimino = false;
                        do {
                            cin >> confirmacion;
                            if (confirmacion == "S") {
                                se_elimino = iproducto -> eliminarProducto();
                                error = false;
                            } else {
                                if (confirmacion == "N") {
                                    iproducto -> cancelarBajaProducto();
                                    error = false;
                                } else {
                                    cout << "\nCaracter inválido. Ingrese S o N.\n";
                                    error = true;
                                }
                            }
                        } while (error);
                        if (se_elimino)
                            msj = "Se eliminó el producto correctamente.";
                        else
                            msj = "El producto no se eliminó.";
                    } catch(exception *e) {
                        system("clear");
                        msj = e -> what();
                        delete e;
                        break;
                    }
                    break;

                /* 6) Consultar actualizaciones de pedidos a domicilio. */
                #if 0
                case 6:
                    try {

                    } catch(exception* e) {

                    }
                    break;
                #endif
                /* 7) Información de un producto. */
                #if 0
                case 7:
                    try {

                    } catch(exception* e) {

                    }
                    break;
                #endif
                /* 8) Resumen facturación de 1 día dada la fecha. */
                #if 0
                case 8:
                    try {

                    } catch(exception* e) {

                    }
                    break;
                #endif
                /* 9) Venta a domicilio. */
                #if 0
                case 9:
                    try {
                        cout << "\nIngrese su número de teléfono. \n";
                        int telefono = conseguir_telefono();
                        map<int, Cliente*> clientes = icliente -> getClientes();
                        map<int, Cliente*>::iterator it = clientes.find(telefono);
                        if (it == clientes.end())
                            altaCliente(telefono);
                        else {
                            map<int, DtProducto> productos_disponibles = iproducto -> getProductosDisponibles();
                            map<int, DtProducto>::iterator it;
                            for (it = productos_disponibles.begin(); it != productos_disponibles.end(); ++it){
                                cout << (it -> second).getCodigo()
                                    << " - "
                                    << (it -> second).getDescripcion()
                                    << "\n";
                            }
                            bool quiero_agregar = true;
                            while (quiero_agregar) {
                                cout << "\nIngrese el código del producto y la cantidad que desea comprar. \n"
                                    << " Código: ";
                                int codigo;
                                cin >> codigo;
                                es_valido_codigo(codigo, productos_disponibles);
                                cout << "\n Cantidad: ";
                                int cantidad;
                                cin >> cantidad;
                                es_valida_cantidad(cantidad);
                                DtProductoCantidad prod_y_cant = DtProductoCantidad(codigo, cantidad);
                                iproducto -> seleccionarProductoYCantidad(prod_y_cant);
                                cout << "\nDesea agregar más productos? Ingrese S o N. \n"
                                quiero_agregar = confirmacion();
                                string confirmacion;
                                bool error = false;
                            }
                            cout << "\nDesea que el pedido sea entregado? Ingrese S o N. \n"
                            bool quiero_recibir = confirmacion();
                            if (quiero_recibir) {
                                map<int, Repartidor*> repartidores_disponibles = iempleado -> getRepartidoresDisponibles();
                                map<int, Repartidor*>::iterator it_repartidores;
                                for (it_repartidores = repartidores_disponibles.begin(); it_repartidores != repartidores_disponibles.end(); ++it_repartidores){
                                    cout << (it_repartidores -> second) -> getNumero()
                                        << " - "
                                        << (it_repartidores -> second) -> getNombre()
                                        << " - "
                                        << (it_repartidores -> second) -> getTransporte();
                                }
                                cout << "\nIngrese el número del repartidor que desea. \n"
                                    << " Número: ";
                                int numero_repartidor;
                                cin >> numero_repartidor;
                                es_valido_numero_repartidor(numero_repartidor, repartidores_disponibles);
                                iempleado -> seleccionarRepartidor(numero_repartidor);
                            }
                            cout << "\nDesea confirmar su pedido? Ingrese S o N. \n";
                            bool quiero_confirmar = confirmacion();
                            if (quiero_confirmar) {
                                /////
                                ////
                                ////
                                ////
                                ////
                                ///
                                //HACER LO DE ANTES COMO UNA FUNCION, LO DE ARRIBAAAAA!!!1
                            }




                    } catch(exception* e) {

                    }
                    break;
                #endif
                /* 10) Ventas de un mozo. */
                #if 0
                case 10:
                    try {

                    } catch(exception* e) {

                    }
                    break;
                #endif
                /* 0) Salir. */
                #if 0
                case 0:
                    try {

                    } catch(exception* e) {

                    }
                    break;
                #endif
                default: {
                    msj = "Número inválido. Ingrese valor entre 0 y 10.";
                }
                break;
                }//fin switch opcion_administrador
            } catch(exception* e) {
                cout << e->what();
            }
            break;

        /* 2) Mozo. */
        case 2: {
            try {
                system("clear");
                cout << "--------------------" << "Mozo" << "-------------------- \n \n"
                    << " - Elija la opción deseada -  \n \n"
                    << " 1) Agregar producto a una venta. \n"
                    << " 2) Facturacón de una venta. \n"
                    << " 3) Iniciar venta en mesas. \n"
                    << " 4) Quitar producto de una venta. \n"
                    << " 0) Salir. \n \n"
                    << " Opción: ";
                cin >> opcion_mozo;
                switch(opcion_mozo) {

                /* 1) Agregar producto a una venta. */
                #if 0
                case 1:
                    try {

                    } catch(exception* e) {

                    }
                    break;
                #endif
                /* 2) Facturacón de una venta. */
                #if 0
                case 2:
                    try {

                    } catch(exception* e) {

                    }
                    break;
                #endif
                /* 3) Iniciar venta en mesas. */
                #if 0
                case 3:
                    try {

                    } catch(exception* e) {

                    }
                    break;
                #endif
                /* 4) Quitar producto de una venta. */
                #if 0
                case 4:
                    try {

                    } catch(exception* e) {

                    }
                    break;
                #endif
                /* 0) Salir. */
                #if 0
                case 0:
                    try {

                    } catch(exception* e) {

                    }
                    break;
                #endif
                default: {
                    msj = "Número inválido. Ingrese valor entre 0 y 4.";
                }
                break;
                }//fin switch opcion_mozo
            } catch(exception* e) {

            }
            break;

        /* 3) Repartidor. */
        case 3:
            try {

                system("clear");
                cout << "--------------------" << "Repartidor" << "-------------------- \n \n"
                    << " - Elija la opción deseada -  \n \n"
                    << " 1) Modificar estado de un pedido. \n"
                    << " 0) Salir. \n \n"
                    << " Opción: ";
                cin >> opcion_repartidor;
                switch(opcion_repartidor) {

                /* 1) Modificar estado de un pedido. */
                #if 0
                case 1:
                    try {

                    } catch(exception* e) {

                    }
                    break;
                #endif
                /* 0) Salir. */
                #if 0
                case 0:
                    try {

                    } catch(exception* e) {

                    }
                    break;
                #endif
                default: {
                    msj = "Número inválido. Ingrese valor entre 0 y 1.";
                }
                break;
                }//fin switch
            } catch(exception* e) {

            }
            break;

        /* 4) Cliente. */
        case 4:
            try {

                system("clear");
                cout << "--------------------" << "Cliente" << "-------------------- \n \n"
                    << " - Elija la opción deseada -  \n \n"
                    << " 1) Consultar actualizaciones de pedidos. \n"
                    << " 0) Salir. \n \n"
                    << " Opción: ";
                cin >> opcion_cliente;
                switch(opcion_cliente) {

                /* 1) Consultar actualizaciones de pedidos. */
                #if 0
                case 1:
                    try {

                    } catch(exception* e) {

                    }
                    break;
                #endif
                /* 0) Salir. */
                #if 0
                case 0:
                    try {

                    } catch(exception* e) {

                    }
                    break;
                #endif
                default: {
                    msj = "Número inválido. Ingrese valor entre 0 y 1.";
                }
                break;
                }//fin switch opcion_cliente
            } catch(exception* e) {

            }
            break;

        /* 5) Cargar datos de prueba. */
        #if 0
        case 5: {
            try {

            } catch(exception* e) {

            }
            break;
        }
        #endif
        /* 0) Salir. */
        case 0:
            salir = true;
            break;
        default: {
            msj = "Número inválido. Ingrese valor entre 0 y 5.";
        }
        break;

        } //fin try
    }

    }//fin while(!salir)
    return 0;
}//fin main
