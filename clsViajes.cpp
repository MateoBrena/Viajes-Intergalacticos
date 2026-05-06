#include <iostream>
#include "clsViajes.h"
using namespace std;

Viajes::Viajes(int id, int idC, int idD, int tV){
    idViaje = id;
    idCapitan = idC;
    idDestino = idD;
    tiempoViaje = tV;
    estado = true;
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
    if(tV <= 0){
        cout << "Tiempo de viaje ingresado invalido" << endl;
        return;
    }
    tiempoViaje = tV;
}

void Viajes::setEstado(bool e){
    estado = e;
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

bool Viajes::getEstado(){
    return estado;
}
void Viajes::Cargar(int id, int idC, int idD){
    idViaje = id;
    if(idC == -1){
        cout << "ID de capitan: ";
        cin >>idCapitan;
    }else{
        idCapitan = idC;
    }
    if(idD == -1){
        cout << "ID de destino: ";
        cin >>idDestino;
    }else{
        idDestino = idD;
    }
    cout << "Ingrese el tiempo de viaje: ";
    cin >> tiempoViaje;

}

void Viajes::Mostrar(){
    cout << "ID viaje: " << idViaje << endl;
    cout << "ID capitan: " << idCapitan << endl;
    cout << "ID destino: " << idDestino << endl;
    cout << "Tiempo de viaje: " << tiempoViaje << endl;
}
