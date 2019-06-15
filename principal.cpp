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
#include <vector>
using namespace std;

//Archivos
#include "include/DtProducto.hpp"
#include "include/DtProductoSimple.hpp"
#include "include/DtMenu.hpp"
#include "include/DtRepartidor.hpp"
#include "include/ICliente.hpp"
#include "include/IEmpleado.hpp"
#include "include/IMesa.hpp"
#include "include/IProducto.hpp"
#include "include/IVenta.hpp"
#include "include/Fabrica.hpp"
#include "src/CargarDatosDePrueba.cpp"

/*
-------------------------------------
-------Funciones De Validación-------
-------------------------------------
*/

/* Obtiene la fecha de la entrada estandar */
static void obtenerFecha(int &dia, int &mes, int &anio) {
    cout << "Ingrese la fecha deseada. \n"
        << " Día: ";
    cin >> dia;
    cout << " Mes: ";
    cin >> mes;
    cout << " Año: ";
    cin >> anio;
}

static int conseguirCantidad() {
    int cantidad;
    do {
        cout << "\nIngrese la cantidad del producto a ingresar. \n"
            << " Cantidad: ";
        cin >> cantidad;
        if (cantidad < 0)
            cout << "\nCantidad ingresada no válida.";

    } while (cantidad < 0);
    return cantidad;
}

/* Obtiene un numero positivo de la entrada estandar */
static int conseguirNumeroMesa() {
    int numero;
    do {
        cout << "Ingrese el número de mesa. \n"
            << " Número: ";
        cin >> numero;
        if (!(numero >= 0)) {
            cout << "\nNúmero ingresado no valido.";
            system("clear");
        }
    } while (numero < 0);
    return numero;
}

/* Chequea que la fecha obtenida de la entrada estandar sea valida */
static bool esValidaFecha(int dia, int mes, int anio) {
    return ((1 <= dia) && (dia <= 31)) &&
        ((1 <= mes) && (mes <= 12)) &&
        (0 < anio);
}

/* Obtiene el número de teléfono. */
static string conseguirTelefono() {
    cout << "Ingrese su número de teléfono. \n"
        << " Teléfono: ";
    string telefono;
    cin >> telefono;
    bool no_lo_consigo = true;
    bool es_numero = false;
    while (no_lo_consigo) {
        es_numero = all_of(telefono.begin(), telefono.end(), ::isdigit);
        if (!es_numero) {
            cout << "\nTeléfono ingresado no válido. Ingrese su número de teléfono. \n"
                << " Teléfono: ";
            cin >> telefono;
        }
        else
            no_lo_consigo = false;
    }
    return telefono;
    }

/* Obtiene el porcentaje de descuento. */
static float conseguirDescuento() {
    cout << "\nIngrese el descuento que desea aplicar. \n"
        << " Descuento: ";
    float descuento;
    cin >> descuento;
    bool no_lo_consigo = true;
    while (no_lo_consigo) {
        if ((descuento < 0) || (descuento >= 101)) {
            cout << "Descuento no válido. Ingrese un descuento entre 0 y 100. \n"
                << " Descuento: ";
            cin >> descuento;
        } else
            no_lo_consigo = false;
    }
    return descuento;
}

/* Chequea que sea valido el codigo del producto buscando el codigo en la coleccion
de productos disponibles. Si el codigo no existe en esta coleccion tira una excepcion */
static void es_valido_codigo(int codigo, map<int, DtProducto> productos_disponibles) {
    map<int, DtProducto>::iterator it = productos_disponibles.find(codigo);
    if (it == productos_disponibles.end())
        throw new invalid_argument ("No existe producto con ese código");
}

/* Si la cantidad es menor o igual a 0 tira una excepcion invalid_argument */
static void es_valida_cantidad(int cantidad) {
    if (cantidad <= 0)
        throw new invalid_argument ("Cantidad ingresada no válida");
}

/* Chequea que sea valido el codigo del repartidor buscando el codigo en la coleccion
de repartidores. Si el codigo no existe en esta coleccion tira una excepcion */
static void es_valido_numero_repartidor(int numero_repartidor, map<int, Repartidor*> repartidores_disponibles) {
    map<int, Repartidor*>::iterator it = repartidores_disponibles.find(numero_repartidor);
    if (it == repartidores_disponibles.end())
        throw new invalid_argument ("No existe producto con ese código.");
}

/* Procedimiento de E/S con el usuario el cual pide que confirme sus acciones,
las opciones son S o N, si ingresa algo distinto de S o N pide al usuario que ingrese
nuevamente una opcion. */
static bool confirmacion () {
    string confirmacion;
    bool error = false;
    bool quiero_confirmar = false;
    cout << " Opción: ";
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
                cout << "\nOpción ingresada no válida. Ingrese S o N. \n"
                    << " Opción: ";
                error = true;
            }
        }
    } while (error);
    return quiero_confirmar;
}

/*Caso de uso: ALTA CLIENTE*/
//Implementado como función porque es referenciado desde otro caso de uso
static void altaCliente(string telefono, ICliente *icliente, string &mensaje) {
    bool existe_cliente = icliente->existeCliente(telefono);
    if (existe_cliente)
        throw new invalid_argument("Error. Ya existe un cliente con ese teléfono ingresado en el sistema. ");
    else{
        //consumo el enter que quedo del ingreso del telefono
        getchar();
        //ingresar datos del cliente
        cout << "\nIngrese el nombre del cliente. \n"
            << " Nombre: ";
        string nombre;
        getline(cin, nombre);
        cout << "\nIngrese la dirección del cliente. \n";
        DtDireccion casa;
        DtApto apto;
        string calle;
        cout << " Calle: ";
        getline(cin, calle);
        cout << " Número de puerta: ";
        int nro;
        cin >> nro;
        getchar();
        cout << " Esquina 1: ";
        string esq1;
        getline(cin, esq1);
        cout << " Esquina 2: ";
        string esq2;
        getline(cin, esq2);
        cout << "\n¿Vive en un apartamento? Ingrese S o N. \n";
        bool es_apto = confirmacion();
        getchar();
        if (es_apto){
            cout <<"\nIngrese el nombre del edificio y el número de apartamento. \n"
                << " Nombre edificio: ";
            string nombre_edificio;
            getline(cin, nombre_edificio);
            cout<< " Número de apartamento: ";
            int nro_apto;
            cin >> nro_apto;
            apto = DtApto(calle, nro, esq1, esq2, nombre_edificio, nro_apto);
        }
        else
            casa = DtDireccion(calle, nro, esq1, esq2);
        try{
            system("clear");
            cout << "--------------------" << "Alta Cliente" << "-------------------- \n \n";
            if (es_apto){
                icliente->ingresarDatosCliente(telefono, nombre, apto);
                DtCliente datos = icliente->getDatosIngresados();
                cout << "Los datos ingresados son: \n";
                cout << datos << "\n";
                cout << "            Edificio: " << apto.getNombreEdificio() << " apto. " << apto.getNumeroApto() << "." << endl;
            }
            else{
                icliente->ingresarDatosCliente(telefono, nombre, casa);
                DtCliente datos = icliente->getDatosIngresados();
                cout << "Los datos ingresados son: \n";
                cout << datos << "\n";
            }

            cout << "\n¿Desea confirmar el ingreso del cliente? Ingrese S o N. \n";
            bool confirma_cliente = confirmacion();
            if (confirma_cliente){
                icliente->ingresarCliente();
                mensaje = "Cliente ingresado correctamente";
            }
            else{
                icliente->cancelarCliente();
                mensaje = "Ingreso de cliente cancelado";
            }

        }
        catch(exception *e){
            throw e;
        }
    }
}

/*
------------------------------------------
------------Programa Principal------------
------------------------------------------
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
                    << " 0) Volver a pantalla principal. \n \n"
                    << " Opción: ";
                cin >> opcion_administrador;
                switch(opcion_administrador) {

                /* 1) Alta cliente. */
                case 1:
                    try {
                        system("clear");
                        cout << "--------------------" << "Alta Cliente" << "-------------------- \n \n";
                        string telefono_cliente = conseguirTelefono();
                        altaCliente(telefono_cliente, icliente, msj);
                    } catch(exception* e) {
                        system("clear");
                        msj = e -> what();
                        delete e;
                        break;
                    }
                    break;

                /* 2) Alta empleado. */
                case 2:
                    try {
                        bool quiere_ingresar_empleado = false;
                        do{
                            system("clear");
                            cout << "--------------------" << "Alta Empleado" << "-------------------- \n \n";
                            string nombre;
                            cout << "Ingrese el nombre del empleado a ingresar. \n"
                                << " Nombre: ";
                            cin >> nombre;
                            iempleado->ingresarNombreEmpleado(nombre);
                            string tipo_empleado;
                            bool tipo_incorrecto = false;
                            do{
                                cout << "\nIngrese R para ingresar un repartidor, M para ingresar un mozo. \n"
                                    << " Opción: ";
                                cin >> tipo_empleado;
                                //se ingresa repartidor
                                if (tipo_empleado == "R"){
                                    tipo_incorrecto = false;
                                    set<Transporte> transportes_disponibles = iempleado->getTransportes();
                                    cout << "\nSeleccione el transporte deseado. \n";
                                    set<Transporte>::iterator it_transportes;
                                    int cont = 0;
                                    for (it_transportes = transportes_disponibles.begin(); it_transportes != transportes_disponibles.end(); ++it_transportes){
                                        cont++;
                                        Transporte transporte = *it_transportes;
                                        cout << " " << cont << ") " << transporte << "\n";
                                    }
                                    cout << "\nOpción: ";
                                    string t_seleccionado;
                                    Transporte transporte_elegido;
                                    bool transporte_incorrecto = false;
                                    do{
                                        cin >> t_seleccionado;
                                        if (t_seleccionado == "1"){
                                            transporte_elegido = Pie;
                                            transporte_incorrecto = false;
                                        }
                                        else
                                            if (t_seleccionado == "2"){
                                                transporte_elegido = Bici;
                                                transporte_incorrecto = false;
                                            }
                                            else
                                                if (t_seleccionado == "3"){
                                                    transporte_elegido = Moto;
                                                    transporte_incorrecto = false;
                                                }
                                                else{
                                                    cout << "\nOpción ingreada no válida. \n \n"
                                                        << "Por favor seleccione una de las opciones mostradas anteriormente. \n"
                                                        << " Opción: ";
                                                    transporte_incorrecto = true;
                                                }

                                    }while(transporte_incorrecto);
                                    iempleado->seleccionarTransporte(transporte_elegido);
                                    system("clear");
                                    cout << "--------------------" << "Alta Empleado" << "-------------------- \n \n";
                                    DtRepartidor datos = iempleado->getDatosIngresadosRepartidor();
                                    cout << "Los datos ingresados son: \n";
                                    cout << datos << "\n";
                                    cout << "¿Desea confirmar el ingreso del repartidor? Ingrese S o N. \n";
                                    bool confirma_repartidor = confirmacion();
                                    if (confirma_repartidor){
                                        iempleado->ingresarRepartidor();
                                         cout << "\nRepartidor agregado correctamente. \n";
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
                                        system("clear");
                                        cout << "--------------------" << "Alta Empleado" << "-------------------- \n \n";
                                        DtMozo datos = iempleado -> getDatosIngresadosMozo();
                                        cout << "Los datos ingresados son: \n";
                                        cout << datos << "\n";
                                        cout << "¿Desea confirmar el ingreso del mozo? Ingrese S o N. \n";
                                        bool confirma_mozo = confirmacion();
                                        if (confirma_mozo){
                                            iempleado -> ingresarMozo();
                                            cout << "\nMozo agregado correctamente. \n";
                                        }
                                        else {
                                            iempleado -> cancelarMozo();
                                            msj = "Ingreso de mozo cancelado";
                                        }
                                    }
                                    //tipo incorrecto
                                    else{
                                        cout << "\nOpción ingresada no válida. \n";
                                        tipo_incorrecto = true;
                                    }
                            }while(tipo_incorrecto);
                            cout << "\n¿Desea agregar más empleados? Ingrese S o N. \n";
                            quiere_ingresar_empleado = confirmacion();
                        }while(quiere_ingresar_empleado);
                    } catch(exception *e) {
                        system("clear");
                        msj = e -> what();
                        delete e;
                        break;
                    }
                    break;

                /* 3) Alta producto */
                case 3:
                    try {
                        msj = "";
                        bool quiero_agregar_mas = true;
                        int tipo_producto = 0;
                        do {
                            system("clear");
                            cout << "--------------------" << "Alta producto" << "-------------------- \n \n";
                            cout << "Seleccione el tipo de producto que desea crear. \n"
                                << " 1) Producto simple. \n";
                            if(iproducto->existeProductoSimple()) { //Muestro la opcion de crear un menu sii existe al menos un producto simple
                                cout << " 2) Menú. \n";
                            }
                            cout << "\nOpción: ";
                            bool existe_opcion = false;
                            do {
                                int codigo = 0;
                                float precio = 0;
                                string descripcion = "";
                                cin >> tipo_producto;
                                switch(tipo_producto) {
                                case 1: {
                                    //Agregar producto simple
                                    system("clear");
                                    cout << "--------------------" << "Agregar producto simple" << "-------------------- \n \n";
                                    cout << "Ingrese los datos del producto simple a ingresar. \n"
                                        << " Código: "; cin >> codigo;
                                    cout << " Descripción: ";
                                    getchar();
                                    getline(cin, descripcion);
                                    cout << " Precio: $";
                                    cin >> precio;
                                    DtProductoSimple datos_producto_simple = DtProductoSimple(codigo, descripcion, precio);
                                    iproducto->ingresarDatosProducto(datos_producto_simple);
                                    cout << "\n¿Desea confirmar el ingreso del producto? Ingrese S o N. \n";
                                    if(confirmacion()) {
                                        iproducto->ingresarProductoSimple();
                                        cout << "\nProducto ingresado correctamente. \n";

                                    } else {
                                        iproducto->cancelarProductoSimple();
                                        cout << "\nIngreso de producto cancelado. \n";
                                    }
                                    existe_opcion = true;
                                    break;
                                }
                                case 2: {
                                    //Agregar menu
                                    system("clear");
                                    cout << "--------------------" << "Agregar menú" << "-------------------- \n \n";
                                    cout << "Ingrese los datos del menú a ingresar. \n"
                                        << " Código: ";
                                    cin >> codigo;
                                    cout << " Descripción: ";
                                    getchar();
                                    getline(cin, descripcion);
                                    iproducto->ingresarDatosMenu(codigo, descripcion);
                                    map<int, DtProducto> productos_simples = iproducto->getProductosSimples();
                                    map<int, DtProducto>::iterator it;
                                    //Selecciona Productos Simples
                                    bool desea_seleccionar_mas = true;
                                    do {
                                        system("clear");
                                        cout << "--------------------" << "Agregar productos al menú" << "-------------------- \n \n";
                                        cout << "Estos son los productos disponibles. \n";
                                        //Muestro los productos simples para que se seleccione cuales integran el menu
                                        for (it = productos_simples.begin(); it != productos_simples.end(); ++it){
                                            cout << " " << (it->second).getCodigo() << " - " << (it->second).getDescripcion() << "\n";
                                        }
                                        int codigo_producto_simple = 0;
                                        int cantidad = 0;
                                        cout << "\nIngrese el código del producto que desea agregar al menú. \n"
                                            << " Código: ";
                                        cin >> codigo_producto_simple;
                                        cout << "\nIngrese la cantidad del producto que desea agregar al menú. \n"
                                            << " Cantidad: ";
                                        cin >> cantidad;
                                        it = productos_simples.find(codigo_producto_simple);
                                        if(it == productos_simples.end())
                                            throw new invalid_argument("Se ingresó un código incorrecto.");
                                        DtProductoCantidad datos_producto_cantidad = DtProductoCantidad(productos_simples[codigo_producto_simple], cantidad);
                                        iproducto->seleccionarProductoYCantidad(datos_producto_cantidad);
                                        string agregar_mas = "";
                                        cout << "\n¿Desea seguir agregando productos? Ingrese S o N. \n";
                                        if(confirmacion()) {
                                            desea_seleccionar_mas = true;
                                        } else {
                                            desea_seleccionar_mas = false;
                                        }
                                    }while(desea_seleccionar_mas);

                                    system("clear");
                                    cout << "--------------------" << "Agregar productos al menú" << "-------------------- \n \n";
                                    cout << "Estos son los productos a agregar al menú. \n";
                                    map<int, DtProductoCantidad> productos_en_menu = iproducto -> getDatosIngresadosMenu();
                                    map<int, DtProductoCantidad>::iterator it_menu;
                                    for (it_menu = productos_en_menu.begin(); it_menu != productos_en_menu.end(); ++it_menu){
                                        cout << (it_menu->second).getProducto() << " - Cantidad: " << (it_menu->second).getCantidad() << "\n";
                                    }
                                    cout << "\n¿Desea confirmar el ingreso del menú? Ingrese S o N. \n";
                                    if(confirmacion()) {
                                        iproducto->ingresarMenu();
                                        cout << "\nMenú ingresado correctamente. \n";
                                    } else {
                                        iproducto->cancelarMenu();
                                        cout << "\nIngreso de menú cancelado. \n";
                                    }
                                    existe_opcion = true;
                                    break;
                                }

                                default: {
                                    existe_opcion = false;
                                    cout << "\nOpción ingreada no válida. \n \n"
                                        << "Por favor seleccione una de las opciones mostradas anteriormente. \n"
                                        << " Opción: ";
                                }
                                break;
                                }
                            } while(!existe_opcion);
                            cout << "\n¿Desea seguir dando de alta productos? Ingrese S o N. \n";
                            if(confirmacion()) {
                                quiero_agregar_mas = true;
                            } else {
                                quiero_agregar_mas = false;
                            }
                        } while(quiero_agregar_mas);
                    } catch(exception* e) {
                        system("clear");
                        msj = e -> what();
                        delete e;
                        break;
                    }
                break;

                /* 4) Asignar automáticamente mozos a mesas. */
                case 4:
                    try {
                        system("clear");
                        cout << "--------------------" << "Asignar automáticamente mozos a mesas" << "-------------------- \n \n";
                        map<int, DtMesasMozo> mesas_mozo = imesa->asignarMozosAMesas();
                        map<int, DtMesasMozo>::iterator it_mesas_mozo;
                        for(it_mesas_mozo = mesas_mozo.begin(); it_mesas_mozo != mesas_mozo.end(); ++it_mesas_mozo) {
                            cout << " Al mozo con ID " << it_mesas_mozo->second.getCodigoMozo() << " se le asignó/asignaron la/s mesa/s ";
                            set<int> mesas = it_mesas_mozo->second.getMesas();
                            set<int>::iterator it_mesas;
                            for (it_mesas = mesas.begin(); it_mesas != mesas.end(); ++it_mesas) {
                                cout << *it_mesas << " ";
                            }
                            cout << "\n\n";
                        }
                        cout << "Presione <enter> para continuar...";
                        getchar();
                        string continuar;
                        getline(cin, continuar);
                        msj = "Mesas asignadas correctamente";
                    } catch(exception* e) {
                        system("clear");
                        msj = e -> what();
                        delete e;
                        break;
                    }
                    break;

                /* 5) Baja de producto */
                case 5:
                    try {
                        system("clear");
                        cout << "--------------------" << "Baja de producto" << "-------------------- \n \n";
                        map<int, DtProducto> productos_disponibles = iproducto -> getProductosDisponibles();
                        map<int, DtProducto>::iterator it;
                        cout << "Estos son los productos disponibles. \n";
                        for (it = productos_disponibles.begin(); it != productos_disponibles.end(); ++it){
                             cout << (it -> second)
                                << "\n";
                        }
                        cout << "\nIngrese el código del producto que desea dar de baja. \n"
                            << " Código: ";
                        int codigo;
                        cin >> codigo;
                        iproducto -> seleccionarProducto(codigo);
                        cout << "\n¿Desea eliminar el producto? Ingrese S o N.\n";
                        bool se_elimino = confirmacion();
                        if (se_elimino)
                            se_elimino = iproducto -> eliminarProducto();
                        else {
                            iproducto -> cancelarBajaProducto();
                            se_elimino = false;
                        }
                        string waste = "";
                        getline(cin, waste);
                        cout << "\nPresione <enter> para continuar.";
                        getline(cin, waste);
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

                case 6:
                    try {
                        msj = "";
                        system("clear");
                        cout << "-----------------" << "Actualizaciones de pedidos a domicilio" << "----------------- \n \n";
                        vector<DtActualizacion> actualizaciones = iventa -> getListadoActualizaciones();
                        vector<DtActualizacion>::iterator it_actualizacion;
                        cout<< "Se listan las actualizaciones de todos los pedidos a domicilio. \n\n";
                        for (it_actualizacion = actualizaciones.begin(); it_actualizacion != actualizaciones.end(); ++it_actualizacion){
                           cout << *it_actualizacion << "\n\n";
                        }
                        cout<< "Presione <enter> para continuar...";
                        getchar();
                        string continuar;
                        getline(cin, continuar);
                    } catch(exception* e) {
                        system("clear");
                        msj = e -> what();
                        delete e;
                        break;
                    }
                    break;

                /* 7) Información de un producto. */
                case 7:
                    try {
                        msj = "";
                        system("clear");
                        cout << "--------------------" << "Información de un producto" << "-------------------- \n \n";
                        map<int, DtProducto> productos_disponibles = iproducto->getProductosDisponibles();
                        map<int, DtProducto>::iterator it;
                        cout << "Estos son los productos disponibles. \n";
                        //Muestro los productos disponibles para seleccionar cual se quiere ver su info
                        for (it = productos_disponibles.begin(); it != productos_disponibles.end(); ++it){
                            cout << " " << (it->second).getCodigo() << " - " << (it->second).getDescripcion() << "\n";
                        }
                        int codigo = 0;
                        bool es_valido_el_codigo = true;
                        bool cancelar = false;
                        do {
                            cout << "\nIngrese el código del producto que desea ver la información. \n"
                                << " Código: ";
                            cin >> codigo;
                            es_valido_el_codigo = iproducto -> ingresarCodigoProductoAConsultar(codigo);
                            if(!es_valido_el_codigo) {
                                cout << "Código inválido. ¿Desea cancelar la consulta? Ingrese S o N. \n"
                                    << " Opción: ";
                                if(confirmacion()) {
                                    es_valido_el_codigo = true;
                                    cancelar = true;
                                } else {
                                    es_valido_el_codigo = false;
                                    cancelar = false;
                                }
                            }
                        } while(!es_valido_el_codigo);
                        if(!cancelar) {
                            DtProducto* prod = iproducto->getProducto();
                            DtMenu* dtmenu_ptr = dynamic_cast<DtMenu*>(prod);
                            system("clear");
                            cout << "--------------------" << "Información de un producto" << "-------------------- \n \n";
                            cout << "Información del producto. \n";
                            cout << " Código: " << prod->getCodigo() << "\n"
                                << " Descripción: " << prod->getDescripcion() << "\n"
                                << " Precio: $" << prod->getPrecio() << "\n"
                                << " Cantidad vendidos: " << prod->getCantidadVendidos() << "\n";
                            //Si es un menu debo mostrar todos los productos que tiene dentro
                            if(dtmenu_ptr != nullptr) {
                                //Tengo que mostrar todos los productos simples dentro del menu
                                DtMenu dtmenu = *dtmenu_ptr;
                                map<int, DtProductoEnMenu> prods = dtmenu.getProductos();
                                map<int, DtProductoEnMenu>::iterator it;
                                for(it = prods.begin(); it != prods.end(); ++it) {
                                    cout << "   " << it->second.getProducto().getCodigo() << " - " << it->second.getProducto().getDescripcion() << " - Cantidad: " << it->second.getCantidad() << "\n";
                                }
                            }
                            delete prod;
                            cout<< "\nPresione <enter> para continuar...";
                            getchar();
                            string continuar;
                            getline(cin, continuar);
                            

                        } else {
                            iproducto->cancelarInformacion();
                        }
                    } catch(exception* e) {
                        system("clear");
                        msj = e -> what();
                        delete e;
                        break;
                    }
                    break;

                /* 8) Resumen facturación de 1 día dada la fecha. */

                case 8:
                    try {
                        msj = "";
                        system("clear");
                        cout << "--------------------" << "Resumen facturación de 1 día dada la fecha" << "-------------------- \n \n";
                        int dia = 0;
                        int mes = 0;
                        int anio = 0;
                        obtenerFecha(dia, mes, anio);
                        while (!esValidaFecha(dia, mes, anio)) {
                            cout << "\nFecha ingresada no válida. \n\n";
                            obtenerFecha(dia, mes, anio);
                        }
                        DtFecha fecha = DtFecha(dia, mes, anio);
                        iventa -> ingresarFecha(fecha);
                        float total_facturado = 0;
                        map<int, DtFactura> facturas_fecha;
                        facturas_fecha = iventa -> getFacturasYTotalFecha(total_facturado);
                        map<int, DtFactura>::iterator itf;
                        for (itf = facturas_fecha.begin(); itf != facturas_fecha.end(); ++itf) {
                            cout << (itf -> second) << "\n\n";
                        }
                        cout<< "\nPresione <enter> para continuar...";
                        getchar();
                        string cont;
                        getline(cin, cont);
                        system("clear");
                        cout << "--------------------" << "Resumen facturación de 1 día dada la fecha" << "-------------------- \n \n";
                        cout << "Total facturado en la fecha " << fecha << " : $ " << total_facturado << "\n";
                        cout << "\nPresione <enter> para continuar...";
                        string continuar;
                        getline(cin, continuar);
                    } catch(exception* e) {
                        system("clear");
                        msj = e -> what();
                        delete e;
                        break;
                    }
                    break;

                /* 9) Venta a domicilio. */
                case 9:
                    try {
                        system("clear");
                        cout << "--------------------" << "Venta a domicilio" << "-------------------- \n \n";
                        string telefono = conseguirTelefono();
                        bool esta_cliente = iventa -> ingresarTelefono(telefono);
                        if (!esta_cliente) {
                            cout << "\nNo existe un cliente asociado a este teléfono. "
                                << "Ingrese los datos correspondientes. \n";
                            altaCliente(telefono, icliente, msj);
                        }
                        cout << "\nEstos son los productos disponibles. \n";
                        map<int, DtProducto> productos_disponibles = iventa -> obtenerProductosDisponibles();
                        map<int, DtProducto>::iterator it;
                        for (it = productos_disponibles.begin(); it != productos_disponibles.end(); ++it){
                            cout << (it -> second).getCodigo()
                                << " - "
                                << (it -> second).getDescripcion()
                                << "\n";
                        }
                        bool quiero_agregar = true;
                        while (quiero_agregar) {
                            cout << "\nIngrese el código del producto.\n"
                                << " Código: ";
                            int codigo;
                            cin >> codigo;
                            es_valido_codigo(codigo, productos_disponibles);
                            cout << "\nIngrese la cantidad que quiere de dicho producto.\n"
                                << " Cantidad: ";
                            int cantidad;
                            cin >> cantidad;
                            es_valida_cantidad(cantidad);
                            it = productos_disponibles.find(codigo);
                            DtProductoCantidad prod_y_cant = DtProductoCantidad((it -> second), cantidad);
                            iventa -> almacenarProducto(prod_y_cant);
                            cout << "\n¿Desea agregar más productos? Ingrese S o N. \n";
                            quiero_agregar = confirmacion();
                        }
                        cout << "\n¿Desea que el pedido sea entregado? Ingrese S o N. \n";
                        bool quiero_recibir = confirmacion();
                        bool quiero_repartidor = false;
                        if (quiero_recibir) {
                            map<int, Repartidor*> repartidores_disponibles = iventa -> obtenerRepartidores();
                            map<int, Repartidor*>::iterator it_repartidores;
                            cout << "\nRepartidores disponibles.\n";
                            for (it_repartidores = repartidores_disponibles.begin(); it_repartidores != repartidores_disponibles.end(); ++it_repartidores){
                                cout << " " << (it_repartidores -> second) -> getNumero()
                                    << ") "
                                    << (it_repartidores -> second) -> getNombre()
                                    << " - "
                                    << (it_repartidores -> second) -> getTransporte()
                                    << "\n";
                            }
                            cout << "\nIngrese el número del repartidor que desea. \n"
                                << " Número: ";
                            int numero_repartidor;
                            cin >> numero_repartidor;
                            es_valido_numero_repartidor(numero_repartidor, repartidores_disponibles);
                            iventa -> elegirRepartidor(numero_repartidor);
                            quiero_repartidor = true;
                        }
                        cout << "\n¿Desea confirmar su pedido? Ingrese S o N. \n";
                        bool quiero_confirmar = confirmacion();
                        if (quiero_confirmar) {
                            float descuento = conseguirDescuento();
                            iventa -> crearVentaADomicilio(quiero_repartidor, descuento);
                            DtFactura* factura = iventa -> generarFacturaADomicilio();
                            system("clear");
                            cout << "--------------------" << "Venta a domicilio" << "-------------------- \n \n";
                            cout << "           Factura de la venta \n"
                                << "--------------------------------------------";
                            if(quiero_repartidor) {
                                DtFacturaDomicilio* ptr_factura_domicilio = nullptr;
                                ptr_factura_domicilio = dynamic_cast<DtFacturaDomicilio*>(const_cast<DtFactura*>(factura));
                                if (ptr_factura_domicilio != nullptr) {
                                    DtFacturaDomicilio factura_domicilio = *ptr_factura_domicilio;
                                    cout << factura_domicilio
                                        << "\n--------------------------------------------";
                                    cout<< "\n\nPresione <enter> para continuar...";
                                    getchar();
                                    string continuar;
                                    getline(cin, continuar);
                                    delete ptr_factura_domicilio;
                                } else
                                    throw new invalid_argument("La venta es local.");
                            } else {
                                cout << *factura
                                    << "\n--------------------------------------------";
                                cout<< "\n\nPresione <enter> para continuar...";
                                getchar();
                                string continuar;
                                delete factura;
                                getline(cin, continuar);
                            }
                            msj = "Venta realizada con éxito";
                        } else {
                            iventa -> cancelarVentaADomicilio();
                            msj = "Venta cancelada";
                        }
                    } catch(exception* e) {
                        system("clear");
                        msj = e -> what();
                        delete e;
                        break;
                    }
                    break;
                /* 10) Ventas de un mozo. */
                case 10:
                    try {
                        system("clear");
                        cout << "--------------------" << "Ventas de un mozo" << "-------------------- \n \n";
                        set<int> ids = iempleado->getIds();
                        set<int>::iterator it;
                        cout << "Estos son los mozos disponibles. \n";
                        for(it = ids.begin(); it != ids.end(); ++it)
                            cout << " " << (*it) << ") " << (iempleado -> getNombreMozo(*it)) << "\n";
                        int id_mozo, dia_ini, mes_ini, anio_ini, dia_fin, mes_fin, anio_fin;
                        cout << "\nSeleccione el ID del mozo. \n"
                            << " ID: ";
                        cin >> id_mozo;
                        cout << "\nIngrese la fecha desde la cual ver las ventas (dd/mm/aaaa): "; cin >> dia_ini; cin.get(); cin >> mes_ini; cin.get(); cin >> anio_ini;
                        cout << "\nIngrese la fecha hasta la cual ver las ventas (dd/mm/aaaa): "; cin >> dia_fin; cin.get(); cin >> mes_fin; cin.get(); cin >> anio_fin;
                        DtFecha fecha_ini = DtFecha(dia_ini, mes_ini, anio_ini);
                        DtFecha fecha_fin = DtFecha(dia_fin, mes_fin, anio_fin);
                        iempleado->seleccionarIdyFechas(id_mozo, fecha_ini, fecha_fin);
                        map<int, DtFactura> ventas_facturadas = iempleado->getVentasFacturadas();
                        map<int, DtFactura>::iterator map_it;
                        if (ventas_facturadas.empty())
                            cout << "\nNo hay ventas facturadas en ese rango de fechas. \n";
                        for(map_it = ventas_facturadas.begin(); map_it != ventas_facturadas.end(); ++map_it) {
                            //Ver que imprimir
                            cout << map_it->second;
                        }
                        cout<< "\nPresione <enter> para continuar...";
                        getchar();
                        string continuar;
                        getline(cin, continuar);
                        msj = "";
                    } catch(exception* e) {

                    }
                    break;

                /* 0) Volver a pantalla principal. */
                case 0:
                        msj = "";
                    break;

                default: {
                    msj = "Número inválido. Ingrese valor entre 0 y 10.";
                }
                break;
                }//fin switch opcion_administrador
            } catch(exception* e) {
                system("clear");
                msj = e -> what();
                delete e;
                break;
            }
            break;

        /* 2) Mozo. */
        case 2: {
            try {
                system("clear");
                cout << "--------------------" << "Mozo" << "-------------------- \n \n"
                    << " - Elija la opción deseada -  \n \n"
                    << " 1) Agregar producto a una venta. \n"
                    << " 2) Facturación de una venta. \n"
                    << " 3) Iniciar venta en mesas. \n"
                    << " 4) Quitar producto de una venta. \n"
                    << " 0) Volver a pantalla principal. \n \n"
                    << " Opción: ";
                cin >> opcion_mozo;
                switch(opcion_mozo) {

                /* 1) Agregar producto a una venta. (Hay Diagrama de Comunicacion) */

                case 1:
                    try {
                        msj = "";
                        system("clear");
                        cout << "--------------------" << "Agregar producto a una venta" << "-------------------- \n \n";
                        set<int> mesas = imesa -> getNumeroMesas();
                        cout << "Estas son las mesas disponibles. \n";
                        set<int>::iterator it_quitar;
                        cout << " ";
                        for (it_quitar = mesas.begin(); it_quitar != mesas.end(); ++it_quitar)
                            cout << *it_quitar << " ";
                        cout << "\n\n";
                        int numero_mesa = conseguirNumeroMesa();
                        iventa -> ingresarNumeroMesa(numero_mesa);
                        bool quiero_agregar = true;
                        bool quiero_confirmar;
                        while (quiero_agregar) {
                            map<int, DtProducto> productos = iventa -> obtenerProductosDisponibles();
                            map<int, DtProducto>::iterator it;
                            cout << "\nEstos son los productos disponibles. \n";
                            for (it = productos.begin(); it != productos.end(); ++it) {
                                cout << (it -> second) << "\n";
                            }
                            cout << "\nIngrese el código del producto a agregar. \n"
                                    << " Código: ";
                            int codigo;
                            cin >> codigo;
                            while (!(iproducto -> ingresarCodigoProductoAConsultar(codigo))) {
                                cout << "\nEl código no está asociado a ningún producto disponible. Ingrese otro código. \n Código: ";
                                cin >> codigo;
                            }
                            DtProducto prod = productos[codigo];
                            int cantidad = conseguirCantidad();
                            DtProductoCantidad producto_cantidad = DtProductoCantidad(prod, cantidad);
                            iventa -> seleccionarProdYCant(producto_cantidad);
                            cout << "\n¿Desea agregar el producto a la venta? Ingrese S o N.\n";
                                quiero_confirmar = confirmacion();
                                if (quiero_confirmar) {
                                    iventa -> agregarProductoAVenta();
                                    cout << "\nSe agregó/agregaron el/los producto/s correctamente. \n";
                                } else {
                                    iventa -> cancelarProductoAVenta();
                                    cout << "\nEl/los producto/s no se agregó/agregaron. \n";
                                }
                                cout << "\n¿Desea agregar más productos a la venta? Ingrese S o N.\n";
                                quiero_agregar = confirmacion();
                        }
                    } catch(exception* e) {
                        system("clear");
                        msj = e -> what();
                        delete e;
                        break;
                    }
                    break;

                /* 2) Facturación de una venta. (Hay Diagrama de Comunicacion) */
                case 2:
                    try {
                        msj = "";
                        system ("clear");
                        cout << "--------------------" << "Facturación de una venta" << "-------------------- \n \n";
                        set<int> mesas = imesa -> getNumeroMesas();
                        cout << "Estas son las mesas disponibles. \n";
                        set<int>::iterator it_quitar;
                        cout << " ";
                        for (it_quitar = mesas.begin(); it_quitar != mesas.end(); ++it_quitar)
                            cout << *it_quitar << " ";
                        cout << "\n\n";
                        int num_mesa = conseguirNumeroMesa();
                        iventa -> ingresarNumeroMesa(num_mesa);
                        float porcentaje = conseguirDescuento();
                        iventa -> ingresarPorcentajeDescuento(porcentaje);
                        DtFactura* factura = iventa -> generarFactura();
                        DtFacturaLocal* ptr_factura_local = dynamic_cast<DtFacturaLocal*>(factura);
                        system("clear");
                        cout << "--------------------" << "Facturación de una venta" << "-------------------- \n \n";
                        cout << "           Factura de la venta \n"
                            << "--------------------------------------------";
                        if (ptr_factura_local != nullptr) {
                            DtFacturaLocal factura_local = *ptr_factura_local;
                            cout << factura_local
                                << "\n--------------------------------------------\n";
                            cout << "\nPresione <enter> para continuar...";
                            getchar();
                            string continuar;
                            getline(cin, continuar);
                            msj = "Venta facturada correctamente.";
                        } else
                            throw new invalid_argument("La venta es a domicilio.");
                    } catch(exception* e) {
                        system("clear");
                        msj = e -> what();
                        delete e;
                        break;
                    }
                    break;

                /* 3) Iniciar venta en mesas */
                case 3:
                    try {
                        system("clear");
                        cout << "--------------------" << "Iniciar venta en mesas" << "-------------------- \n \n";
                        set<int> ids = iempleado->getIds();
                        set<int>::iterator it_ini;
                        cout << "Estos son los mozos disponibles. \n";
                        for(it_ini = ids.begin(); it_ini != ids.end(); ++it_ini)
                            cout << " " << (*it_ini) << ") " << (iempleado -> getNombreMozo(*it_ini)) << "\n";
                        int nro = 0;
                        cout << "\nSeleccione su ID de mozo. \n"
                            << " ID: ";
                        cin >> nro;

                        set<int> mesas_mozo = imesa->getMesasMozoSinVentas(nro);
                        cout << "\nSus mesas sin ventas son: ";
                        set<int>::iterator it;
                        for (it = mesas_mozo.begin(); it != mesas_mozo.end(); ++it){
                            cout << *it << " ";
                        }
                        cout << "\n\n";
                        cout << "Ingrese los números de las mesas en las que desea iniciar la venta. \n";
                        bool quiere_agregar_mas_mesas = true;
                        int num_mesa = 0;
                        set<int> mesas_seleccionadas;
                        do {
                            cout << " Número de mesa: ";
                            cin >> num_mesa;
                            if(mesas_mozo.find(num_mesa) != mesas_mozo.end()) {
                                mesas_seleccionadas.insert(num_mesa);
                                cout << "\n¿Desea seguir agregando mesas? Ingrese S o N. \n";
                                if(confirmacion()) {
                                    quiere_agregar_mas_mesas = true;
                                    cout << "\n";
                                } else
                                    quiere_agregar_mas_mesas = false;
                            } else {
                                cout << "\nIngrese un número de mesa válido.";
                                quiere_agregar_mas_mesas = true;
                            }
                        }while(quiere_agregar_mas_mesas);
                        imesa->seleccionarMesasVenta(mesas_seleccionadas);
                        set<int> mesas_seleccionadas_en_cont = imesa->getMesasSeleccionadas();
                        set<int>::iterator it_mesas_seleccionadas_en_cont;
                        system("clear");
                        cout << "--------------------" << "Iniciar venta en mesas" << "-------------------- \n \n";
                        cout << "Estas son las mesas seleccionadas: ";
                        for(it_mesas_seleccionadas_en_cont = mesas_seleccionadas_en_cont.begin(); it_mesas_seleccionadas_en_cont != mesas_seleccionadas_en_cont.end(); ++it_mesas_seleccionadas_en_cont)
                            cout << *it_mesas_seleccionadas_en_cont << " ";
                        cout << "\n";
                        cout << "\n¿Desea confirmar la creación de la venta? Ingrese S o N. \n";
                        if(confirmacion()) {
                            imesa->iniciarVenta();
                            msj = "Venta iniciada correctamente";
                        } else {
                            imesa->cancelarVenta();
                            msj = "Venta cancelada";
                        }
                    } catch(exception* e) {
                        system("clear");
                        msj = e -> what();
                        delete e;
                        break;
                    }
                    break;

                /* 4) Quitar producto de una venta. (Hay Diagrama de Comunicacion) */
                case 4:
                    try {
                        msj = "";
                        system("clear");
                        cout << "--------------------" << "Quitar producto de una venta" << "-------------------- \n \n";
                        set<int> mesas = imesa -> getNumeroMesas();
                        cout << "Estas son las mesas disponibles. \n";
                        set<int>::iterator it_quitar;
                        cout << " ";
                        for (it_quitar = mesas.begin(); it_quitar != mesas.end(); ++it_quitar)
                            cout << *it_quitar << " ";
                        cout << "\n\n";
                        int num_mesa = conseguirNumeroMesa();
                        map<int, DtProducto> productos_disponibles = iventa -> getProductosVenta(num_mesa);
                        bool quiero_quitar = true;
                        bool quiero_confirmar;
                        while (quiero_quitar) {
                            map<int, DtProducto>::iterator it;
                            cout << "\nEstos son los productos disponibles. \n";
                            for (it = productos_disponibles.begin(); it != productos_disponibles.end(); ++it)
                                cout << (it -> second) << "\n";
                            cout << "Ingrese el código del producto a quitar. \n"
                                << " Código: ";
                            int codigo;
                            cin >> codigo;
                            while (!(iproducto -> ingresarCodigoProductoAConsultar(codigo))) {
                                cout << "\nEl código no esta asociado a ningún producto disponible. Ingrese otro código. \n Código: ";
                                cin >> codigo;
                            }
                            DtProducto prod = productos_disponibles[codigo];
                            int cantidad = conseguirCantidad();
                            DtProductoCantidad producto_cantidad = DtProductoCantidad(prod, cantidad);
                            iventa -> seleccionarProdYCant(producto_cantidad);
                            cout << "\n¿Desea quitar el producto de la venta? Ingrese S o N.\n";
                            quiero_confirmar = confirmacion();
                            if (quiero_confirmar) {
                                iventa -> eliminarProductoDeVenta();
                                cout << "Se quitó el producto correctamente. \n";
                            } else {
                                iventa -> cancelarEliminarProductoDeVenta();
                                cout << "El producto no se eliminó. \n";
                            }
                            cout << "\n¿Desea quitar más productos de la venta? Ingrese S o N.\n";
                            quiero_quitar = confirmacion();
                        }
                    } catch(exception* e) {
                        system("clear");
                        msj = e -> what();
                        delete e;
                        break;
                    }
                    break;

                /* 0) Salir. */
                case 0:
                    msj = "";
                    break;

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
                    << " 0) Volver a pantalla principal. \n \n"
                    << " Opción: ";
                cin >> opcion_repartidor;
                switch(opcion_repartidor) {

                /* 1) Modificar estado de un pedido. */
                case 1:
                    try {
                        system("clear");
                        cout << "--------------------" << "Modificar estado de pedido" << "-------------------- \n \n";
                        cout << "Ingrese su id de empleado: ";
                        int id;
                        cin >> id;
                        iempleado -> ingresarIdRepartidor(id);

                        map<int, DtDireccion> pedidos = iempleado -> getVentasRepartidor();
                        map<int, DtDireccion>::iterator it;
                        if (pedidos.empty())
                            msj = "No hay pedidos para este repartidor";
                        else {
                            cout << "Sus pedidos son: \n";
                            for (it = pedidos.begin(); it != pedidos.end(); ++it){
                                cout << "Venta nro. " << it->first << " ( " << it->second << ") \n";
                            }
                            cout << "Ingrese el numero del pedido cuyo estado quiere modificar: ";
                            int numero;
                            cin >> numero;
                            while (pedidos.find(numero) == pedidos.end()){
                                cout << "Error. Ese numero no pertence a ninguno de sus pedidos. \n";
                                cout << "Por favor, ingrese otro numero: ";
                                cin >> numero;
                            }
                            iempleado -> ingresarNumeroPedido(numero);
                            system("clear");
                            cout << "-----------------" << "Modificar estado de pedido nro. " << numero << "----------------- \n \n"
                                << " - Elija la opción deseada -  \n \n"
                                << " 1) Avanzar etapa. \n"
                                << " 2) Cancelar pedido. \n"
                                << " 0) Volver a pantalla principal. \n \n"
                                << " Opción: ";
                            int opcion;
                            cin >> opcion;
                            switch(opcion){
                                case 1:
                                    iempleado -> avanzarEtapaPedido();
                                    msj = "Etapa modificada correctamente ";
                                    break;
                                case 2:
                                    iempleado -> cancelarPedido();
                                    msj = "Pedido cancelado correctamente ";
                                    break;
                                case 0:
                                    msj = "No se realizaron cambios en los pedidos ";
                                    break;
                                default:
                                    cout << "Numero invalido. Ingrese un numero entre 0 y 2. ";
                                    break;
                            }
                        }
                    } catch(exception* e) {
                        system("clear");
                        msj = e -> what();
                        delete e;
                        break;
                    }
                    break;

                /* 0) Salir. */
                case 0:
                    msj = "No se realizaron cambios en los pedidos";
                    break;

                default: {
                    msj = "Número inválido. Ingrese valor entre 0 y 1.";
                }
                break;
                }//fin switch
            } catch(exception* e) {
                system("clear");
                msj = e -> what();
                delete e;
                break;
            }
            break;

        /* 4) Cliente. */
        case 4:
            try {

                system("clear");
                cout << "--------------------" << "Cliente" << "-------------------- \n \n"
                    << " - Elija la opción deseada -  \n \n"
                    << " 1) Consultar actualizaciones de pedidos. \n"
                    << " 0) Volver a pantalla principal. \n \n"
                    << " Opción: ";
                cin >> opcion_cliente;
                switch(opcion_cliente) {

                /* 1) Consultar actualizaciones de pedidos. */
                case 1:
                    try {
                        system("clear");
                        cout << "--------------------" << "Consultar actualizaciones de pedidos" << "-------------------- \n \n";
                        string tel_cliente = conseguirTelefono();
                        vector<DtActualizacion> act_cliente = iventa->getActualizacionesCliente(tel_cliente);
                        vector<DtActualizacion>::iterator it_act;
                        cout << "Actualizaciones de sus pedidos: \n";
                        for (it_act = act_cliente.begin(); it_act != act_cliente.end(); it_act++)
                            cout << *it_act << "\n";
                    } catch(exception* e) {
                        system("clear");
                        msj = e -> what();
                        delete e;
                        break;
                    }
                    break;

                /* 0) Salir. */
                case 0:
                    msj = "";
                    break;

                default: {
                    msj = "Número inválido. Ingrese valor entre 0 y 1.";
                }
                break;
                }//fin switch opcion_cliente
            } catch(exception* e) {

            }
            break;

        /* 5) Cargar datos de prueba. */
        case 5:
            try {
                //Cargo productos
                cargarDatosDePrueba();
                msj = "Datos cargados correctamente.";
            } catch(exception* e) {
                system("clear");
                msj = e -> what();
                delete e;
                break;
            }
            break;


        /* 0) Salir. */
        case 0:
            system("clear");
            cout << "\n-------------------------------------------------------- \n";
            cout << "\n GRACIAS POR USAR NUESTRO PROGRAMA, HASTA LA PRÓXIMA :) \n \n";
            cout << "-------------------------------------------------------- \n \n";
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
