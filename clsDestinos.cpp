#include <iostream>
#include <cstring>
#include "clsDestinos.h"
#include "cargarCadena.h"

using namespace std;

Destinos::Destinos(){

}

void Destinos::setIdDest(int id){
    idDestino = id;
}

void Destinos::setNombre(const char *n){
    strcpy(nombre, n);
}

void Destinos::setDistancia(int d){
    distancia = d;
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
