#include <iostream>
#include "clsViajes.h"
using namespace std;

Viajes::Viajes(int id, int idC, int idD, int tV){
    idViaje = id;
    idCapitan = idC;
    idDestino = idD;
    tiempoViaje = tV;
}

void Viajes::setIdViaje(int id){
    idViaje = id;
}

void Viajes::setIdCapitan(int idC){
    idCapitan = idC;
}

void Viajes::setIdDestino(int idD){
    idDestino = idD;
}

void Viajes::setTiempoViaje(int tV){
    tiempoViaje = tV;
}

int Viajes::getIdViaje(){
    return idViaje;
}

int Viajes::getIdCapitan(){
    return idCapitan;
}

int Viajes::getIdDestino(){
    return idDestino;
}

int Viajes::getTiempoViaje(){
    return tiempoViaje;
}

void Viajes::Cargar(int id, int idC, int idD){
    if(id == -1){
        cout << "ID Viaje: ";
        cin >>idViaje;
    }else{
        idViaje = id;
    }
    idCapitan = idC;
    idDestino = idD;
    cout << "Ingrese el tiempo de viaje: ";
    cin >> tiempoViaje;

}

void Viajes::Mostrar(){
    cout << "ID viaje: " << idViaje << endl;
    cout << "ID capitan: " << idCapitan << endl;
    cout << "ID destino: " << idDestino << endl;
    cout << "Tiempo de viaje: " << tiempoViaje << endl;
}
