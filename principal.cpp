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







int main() {
    Fabrica *fabrica = Fabrica::getInstance();
    ICliente icliente = fabrica -> getICliente();
    IEmpleado iempleado = fabrica -> getIEmpleado();
    IMesa imesa = fabrica -> getIMesa();
    IProducto iproducto = fabrica -> getIProducto();
    IVenta iventa = fabrica -> getIVenta();
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
                cout << "--------------------" << Administrador << "-------------------- \n \n"
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

                    } catch() {

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
                cout << "--------------------" << Mozo << "-------------------- \n \n"
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
                cout << "--------------------" << Repartidor << "-------------------- \n \n"
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
                cout << "--------------------" << Cliente << "-------------------- \n \n"
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