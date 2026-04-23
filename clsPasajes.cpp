#include <iostream>
#include "clsPasajes.h"
using namespace std;

Pasajes::Pasajes(int idP, int idPj, int idV){
    idPasaje = idP;
    idPasajero = idPj;
    idViaje = idV;
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

int Pasajes::getIdPasaje(){
    return idPasaje;
}

int Pasajes::getIdPasajero(){
    return idPasajero;
}

int Pasajes::getIdViaje(){
    return idViaje;
}

void Pasajes::Cargar(int idPj, int idP, int idV){
    idPasaje = idPj;
    idPasajero = idP;
    idViaje = idV;
}

void Pasajes::Mostrar(){
    cout << "ID Pasaje: " << idPasaje << endl;
    cout << "ID Pasajero: " << idPasajero << endl;
    cout << "ID Viaje: " << idViaje << endl;
}
