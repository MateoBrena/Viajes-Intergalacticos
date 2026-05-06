#include <iostream>
#include "clsPasajes.h"
using namespace std;

Pasajes::Pasajes(int idP, int idPj, int idV, Fecha fC){
    idPasaje = idP;
    idPasajero = idPj;
    idViaje = idV;
    fechaCompra = fC;
    estado = true;
}

void Pasajes::setIdPasaje(int idPj){
    idPasajero = idPj;
}

void Pasajes::setIdPasajero(int idP){
    idPasajero = idP;
}

void Pasajes::setIdViaje(int idV){
    idViaje = idV;
}

void Pasajes::setFechaCompra(Fecha fC){
    fechaCompra = fC;
}

void Pasajes::setEstado(bool e){
    estado = e;
}

int Pasajes::getIdPasaje(){
    return idPasaje;
}

int Pasajes::getIdPasajero(){
    return idPasajero;
}

int Pasajes::getIdViaje(){
    return idViaje;
}

Fecha Pasajes::getFechaCompra(){
    return fechaCompra;
}

bool Pasajes::getEstado(){
    return estado;
}

void Pasajes::Cargar(int idPj, int idP, int idV){
    idPasaje =idPj;
    if(idP == -1){
        cout << "ID de pasajero: ";
        cin >>idPasajero;
    }else{
        idPasajero = idP;
    }
    if(idV == -1){
        cout << "ID de viaje: ";
        cin >>idViaje;
    }else{
        idViaje = idV;
    }
    cout << "Fecha de compra: ";
    fechaCompra.cargarFecha();
}

void Pasajes::Mostrar(){
    cout << "ID Pasaje: " << idPasaje << endl;
    cout << "ID Pasajero: " << idPasajero << endl;
    cout << "ID Viaje: " << idViaje << endl;
    cout << "Fecha de compra: ";
    fechaCompra.mostrarFecha();
}
