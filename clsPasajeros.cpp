#include <iostream>
#include <cstring>
#include "clsPasajeros.h"
#include "cargarCadena.h"

using namespace std;

Pasajero::Pasajero(int d, const char *n, const char *a, Fecha fN, int nC){
    idInt = d;
    strcpy(nombre, n);
    strcpy(apellido, a);
    fechaNacimiento = fN;
    nivelCiudadania = nC;
}

void Pasajero::setIdInt(int id){
    idInt = id;
}

void Pasajero::setNombre(const char *n){
    strcpy(nombre, n);
}

void Pasajero::setApellido(const char *a){
    strcpy(apellido, a);
}

void Pasajero::setFechaNacimiento(Fecha fechaNac){
    fechaNacimiento = fechaNac;
}

void Pasajero::setNivCiudadania(int n){
    nivelCiudadania = n;
}

int Pasajero::getIdInt(){
    return idInt;
}

const char* Pasajero::getNombre(){
    return nombre;
}

const char* Pasajero::getApellido(){
    return apellido;
}

Fecha Pasajero::getFechaNacimiento(){
    return fechaNacimiento;
}

int Pasajero::getNivelCiudadania(){
    return nivelCiudadania;
}

void Pasajero::Cargar(int id){
    if(id == -1){
        cout << "ID intergalactico: ";
        cin >>idInt;
    }else{
        idInt = id;
    }
    cout << "Nombre: ";
    cargarCadena(nombre, 50);
    cout << "Apellido: ";
    cargarCadena(apellido, 50);
    cout << "Fecha de nacimiento: ";
    fechaNacimiento.cargarFecha();
    cout << "Nivel de ciudadania (1- Ciudadano, 2- Miembro del consejo, 3-Embajador): ";
    cin >> nivelCiudadania;
}

void Pasajero::Mostrar(){
    cout << "ID Intergalactico: " << idInt << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "Fecha de nacimiento: ";
    fechaNacimiento.mostrarFecha();
    if(nivelCiudadania == 1){
        cout << "Nivel de ciudadania: Ciudadano" << endl;
    }else if(nivelCiudadania == 2){
        cout << "Nivel de ciudadania: Miembro del consejo" << endl;
    }else{
        cout << "Nivel de ciudadania: Embajador" << endl;
    }
}
