#include "clsMenu.h"
#include <iostream>

using namespace std;

Menu::Menu(){

}

void Menu::menuModificarPasajeros(){

    int opc;
    while(true){
        system("cls");
        cout<<"SUBMENU DE MODIFICAR PASAJEROS"<<endl;
        cout<<"====================="<<endl;
        cout<<"1 - Modificar Nombre"<<endl;
        cout<<"2 - Modificar Apellido"<<endl;
        cout<<"3 - Modificar Fecha de nacimiento"<<endl;
        cout<<"4 - Modificar nivel de ciudadania"<<endl;
        cout<<"0 - Volver al menu de pasajero"<<endl;
        cout<<"====================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                gestorPasajeros.modificarNombre();
                break;
            case 2:
                //gestorPasajeros.buscarPorId();
                break;
            case 3:
                //gestorPasajeros.listarRegistros();
                break;
            case 4:
                //gestorPasajeros.modificarRegistro();
                break;
            case 0:
                return;
        }
        system("pause>nul");
    }

}

void Menu::menuPasajeros(){

    int opc;
    while(true){
        system("cls");
        cout<<"SUBMENU DE PASAJEROS"<<endl;
        cout<<"====================="<<endl;
        cout<<"1 - Alta Pasajero"<<endl;
        cout<<"2 - Buscar Pasajero"<<endl;
        cout<<"3 - Listar Pasajeros"<<endl;
        cout<<"4 - Modificar Pasajero"<<endl;
        cout<<"5 - Baja de Pasajero"<<endl;
        cout<<"0 - Volver al menu principal"<<endl;
        cout<<"====================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                gestorPasajeros.altaPasajero();
                break;
            case 2:
                gestorPasajeros.buscarPorId();
                break;
            case 3:
                gestorPasajeros.listarRegistros();
                break;
            case 4:
                menuModificarPasajeros();
                break;
            case 5:
                //gestorPasajeros.bajaPasajero();
                break;
            case 0:
                return;
        }
        system("pause>nul");
    }

}

void Menu::menuCapitanes(){

    int opc;
    while(true){
        system("cls");
        cout<<"SUBMENU DE CAPITANES"<<endl;
        cout<<"====================="<<endl;
        cout<<"1 - Alta Capitan"<<endl;
        cout<<"2 - Buscar Capitan"<<endl;
        cout<<"3 - Listar Capitanes"<<endl;
        cout<<"4 - Modificar Capitan"<<endl;
        cout<<"5 - Baja de Capitan"<<endl;
        cout<<"0 - Volver al menu principal"<<endl;
        cout<<"====================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                gestorCapitanes.altaCapitan();
                break;
            case 2:
                gestorCapitanes.buscarPorId();
                break;
            case 3:
                gestorCapitanes.listarRegistros();
                break;
            case 4:
                //gestorCapitanes.modificarRegistro();
                break;
            case 5:
                //gestorCapitanes.bajaCapitan();
                break;
            case 0:
                return;
        }
        system("pause>nul");
    }

}

void Menu::menuViajes(){

    int opc;
    while(true){
        system("cls");
        cout<<"SUBMENU DE VIAJES"<<endl;
        cout<<"====================="<<endl;
        cout<<"1 - Alta Viaje"<<endl;
        cout<<"2 - Buscar Viaje"<<endl;
        cout<<"3 - Listar Viajes"<<endl;
        cout<<"4 - Modificar Viaje"<<endl;
        cout<<"5 - Baja de Viaje"<<endl;
        cout<<"0 - Volver al menu principal"<<endl;
        cout<<"====================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                gestorViajes.altaViaje();
                break;
            case 2:
                gestorViajes.buscarPorId();
                break;
            case 3:
                gestorViajes.listarRegistros();
                break;
            case 4:
                //gestorViajes.modificarRegistro();
                break;
            case 5:
                //gestorViajes.bajaViaje();
                break;
            case 0:
                return;
        }
        system("pause>nul");
    }

}

void Menu::menuDestinos(){

    int opc;
    while(true){
        system("cls");
        cout<<"SUBMENU DE DESTINOS"<<endl;
        cout<<"====================="<<endl;
        cout<<"1 - Alta Destino"<<endl;
        cout<<"2 - Buscar Destino"<<endl;
        cout<<"3 - Listar Destinos"<<endl;
        cout<<"4 - Modificar Destino"<<endl;
        cout<<"5 - Baja de Destino"<<endl;
        cout<<"0 - Volver al menu principal"<<endl;
        cout<<"====================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                gestorDestinos.altaDestino();
                break;
            case 2:
                gestorDestinos.buscarPorId();
                break;
            case 3:
                gestorDestinos.listarRegistros();
                break;
            case 4:
                //gestorDestinos.modificarRegistro();
                break;
            case 5:
                //gestorDestinos.bajaDestino();
                break;
            case 0:
                return;
        }
        system("pause>nul");
    }

}

void Menu::menuPasajes(){

    int opc;
    while(true){
        system("cls");
        cout<<"SUBMENU DE PASAJES"<<endl;
        cout<<"====================="<<endl;
        cout<<"1 - Alta Pasaje"<<endl;
        cout<<"2 - Buscar Pasaje"<<endl;
        cout<<"3 - Listar Pasajes" << endl;
        cout<<"4 - Modificar Pasaje"<<endl;
        cout<<"5 - Baja de Pasaje"<<endl;
        cout<<"0 - Volver al menu principal"<<endl;
        cout<<"====================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                gestorPasajes.altaPasaje();
                break;
            case 2:
                gestorPasajes.buscarPorId();
                break;
            case 3:
                gestorPasajes.listarRegistros();
                break;
            case 4:
                //gestorPasajes.modificarRegistro();
                break;
            case 5:
                //gestorPasajes.bajaPasaje();
                break;
            case 0:
                return;
        }
        system("pause>nul");
    }

}

void Menu::iniciar(){

    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"====================="<<endl;
        cout<<"1 - Pasajeros"<<endl;
        cout<<"2 - Capitanes"<<endl;
        cout<<"3 - Viajes"<<endl;
        cout<<"4 - Destinos"<<endl;
        cout<<"5 - Pasajes"<<endl;
        cout<<"6 - Reportes"<<endl;
        cout<<"0 - Salir"<<endl;
        cout<<"====================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                menuPasajeros();
                break;
            case 2:
                menuCapitanes();
                break;
            case 3:
                menuViajes();
                break;
            case 4:
                menuDestinos();
                break;
            case 5:
                menuPasajes();
                break;
            case 6:
                cout << "Submenu Reportes" << endl;
                break;
            case 0:
                return;
        }
        system("pause>nul");
    }
}
