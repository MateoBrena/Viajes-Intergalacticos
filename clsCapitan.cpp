#include <iostream>
#include <cstring>
#include "clsCapitan.h"
#include "cargarCadena.h"

using namespace std;

Capitan::Capitan(int d, const char *n, const char *a, Fecha fN, int r){
    idInt = d;
    strcpy(nombre, n);
    strcpy(apellido, a);
    fechaNacimiento = fN;
    rango = r;
    estado = true;
}

void Capitan::setIdInt(int id){
    idInt = id;
}

void Capitan::setNombre(const char *n){
    strcpy(nombre, n);
}

void Capitan::setApellido(const char *a){
    strcpy(apellido, a);
}

void Capitan::setFechaNacimiento(Fecha fechaNac){
    fechaNacimiento = fechaNac;
}

void Capitan::setRango(int r){
    if(r <= 0 || r > 3){
        cout << "Rango ingresado es invalido" << endl;
        return;
    }
    rango = r;
}

void Capitan::setEstado(bool e){
    estado = e;
}

int Capitan::getIdInt(){
    return idInt;
}

const char* Capitan::getNombre(){
    return nombre;
}

const char* Capitan::getApellido(){
    return apellido;
}

Fecha Capitan::getFechaNacimiento(){
    return fechaNacimiento;
}

int Capitan::getRango(){
    return rango;
}

bool Capitan::getEstado(){
    return estado;
}

void Capitan::Cargar(int id){
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
    cout << "Rango (1- Novato, 2-Experimentado, 3-Veterano): ";
    cin >> rango;
    while(rango <= 0 || rango > 3){
        cout << "Nivel de rango invalido. Vuelva a ingresar." << endl;
        cout << "Nivel de rango (1- Novato, 2-Experimentado, 3-Veterano): ";
        cin >> rango;
    }

}

void Capitan::Mostrar(){
    cout << "ID Intergalactico: " << idInt << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "Fecha de nacimiento: ";
    fechaNacimiento.mostrarFecha();
    if(rango == 1){
        cout << "Rango: Novato" << endl;
    }else if(rango == 2){
        cout << "Rango: Experimentado" << endl;
    }else{
        cout << "Rango: Veterano" << endl;
    }
}
