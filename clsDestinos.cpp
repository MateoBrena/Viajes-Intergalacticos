#include <iostream>
#include <cstring>
#include "clsDestinos.h"
#include "cargarCadena.h"

using namespace std;

Destinos::Destinos(){
    estado = true;
}

void Destinos::setIdDest(int id){
    idDestino = id;
}

void Destinos::setNombre(const char *n){
    strcpy(nombre, n);
}

void Destinos::setDistancia(int d){
    if(d <= 0){
        cout << "No se puede ingresar una distancia negativa" << endl;
        return;
    }
    distancia = d;
}

void Destinos::setEstado(bool e){
    estado = e;
}

int Destinos::getIdDest(){
    return idDestino;
}

const char * Destinos::getNombre(){
    return nombre;
}

int Destinos::getDistancia(){
    return distancia;
}

bool Destinos::getEstado(){
    return estado;
}

void Destinos::Cargar(int id){
    if(id == -1){
        cout << "ID Destino: ";
        cin >>idDestino;
    }else{
        idDestino = id;
    }
    cout << "Nombre: ";
    cargarCadena(nombre, 50);
    cout << "Distancia (En anios luz): ";
    cin >> distancia;
}

void Destinos::Mostrar(){
    cout << "ID destino: "<< idDestino << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Distancia (en anios luz): " << distancia << endl;
}
