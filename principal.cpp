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

//comienzo
#if 0
/* Chequea que la fecha obtenida de la entrada estandar sea valida */
static bool esValidaFecha(int dia, int mes, int anio) {
    return ((1 <= dia) && (dia <= 31)) &&
        ((1 <= mes) && (mes <= 12)) &&
        (0 < anio);

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

                    } catch() {

                    }
                    break;

                /* 2) Alta empleado. */
                case 2:
                    try {

                    } catch() {

                    }
                    break;

                /* 3) Alta producto. */
                case 3:
                    try {

                    } catch() {

                    }
                    break;

                /* 4) Asignar automáticamente mozos a mesas. */
                case 4:
                    try {

                    } catch() {

                    }
                    break;

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
                case 6:
                    try {

                    } catch() {

                    }
                    break;

                /* 7) Información de un producto. */
                case 7:
                    try {

                    } catch() {

                    }
                    break;

                /* 8) Resumen facturación de 1 día dada la fecha. */
                case 8:
                    try {

                    } catch() {

                    }
                    break;

                /* 9) Venta a domicilio. */
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
                                string confirmacion;
                                bool error = false;
                                do {
                                    cin >> confirmacion;
                                    if (confirmacion == "S") {
                                        quiero_agregar = true;
                                        error = false;
                                    } else {
                                        if (confirmacion == "N") {
                                            quiero_agregar = false;
                                            error = false;
                                        } else {
                                            cout << "\nCaracter inválido. Ingrese S o N.\n";
                                            error = true;
                                        }
                                    }
                                } while (error);
                            }
                            cout << "\nDesea que el pedido sea entregado? Ingrese S o N. \n"
                            cin >> confirmacion;
                            error = false;
                            bool quiero_recibir = false;
                            do {
                                cin >> confirmacion;
                                if (confirmacion == "S") {
                                    quiero_recibir = true;
                                    error = false;
                                } else {
                                    if (confirmacion == "N") {
                                        quiero_recibir = false;
                                        error = false;
                                    } else {
                                        cout << "\nCaracter inválido. Ingrese S o N.\n";
                                        error = true;
                                    }
                                }
                            } while (error);
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
                            cin >> confirmacion;
                            error = false;
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
                            if (quiero_confirmar) {
                                /////
                                ////
                                ////
                                ////
                                ////
                                ///
                                //HACER LO DE ANTES COMO UNA FUNCION, LO DE ARRIBAAAAA!!!1
                            }




                    } catch() {

                    }
                    break;

                /* 10) Ventas de un mozo. */
                case 10:
                    try {

                    } catch() {

                    }
                    break;

                /* 0) Salir. */
                case 0:
                    try {

                    } catch() {

                    }
                    break;

                default: {
                    msj = "Número inválido. Ingrese valor entre 0 y 10.";
                }
                break;

            } catch() {

            }
            break;

        /* 2) Mozo. */
        case 2:
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
                case 1:
                    try {

                    } catch() {

                    }
                    break;

                /* 2) Facturacón de una venta. */
                case 2:
                    try {

                    } catch() {

                    }
                    break;

                /* 3) Iniciar venta en mesas. */
                case 3:
                    try {

                    } catch() {

                    }
                    break;

                /* 4) Quitar producto de una venta. */
                case 4:
                    try {

                    } catch() {

                    }
                    break;

                /* 0) Salir. */
                case 0:
                    try {

                    } catch() {

                    }
                    break;

                default: {
                    msj = "Número inválido. Ingrese valor entre 0 y 4.";
                }
                break;

            } catch() {

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
                case 1:
                    try {

                    } catch() {

                    }
                    break;

                /* 0) Salir. */
                case 0:
                    try {

                    } catch() {

                    }
                    break;

                default: {
                    msj = "Número inválido. Ingrese valor entre 0 y 1.";
                }
                break;

            } catch() {

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
                case 1:
                    try {

                    } catch() {

                    }
                    break;

                /* 0) Salir. */
                case 0:
                    try {

                    } catch() {

                    }
                    break;

                default: {
                    msj = "Número inválido. Ingrese valor entre 0 y 1.";
                }
                break;

            } catch() {

            }
            break;

        /* 5) Cargar datos de prueba. */
        case 5:
            try {

            } catch() {

            }
            break;

        /* 0) Salir. */
        case 0:
            try {

            } catch() {

            }
            break;

        default: {
            msj = "Número inválido. Ingrese valor entre 0 y 5.";
        }
        break;

    } //fin switch
    return 0;
} //fin main
#endif

int main(){
    return 0;
}
