#include <iostream>
#include <cstring>
#include "clsArchivoPasajeros.h"
#include "cargarCadena.h"
using namespace std;

ArchivoPasajeros::ArchivoPasajeros(const char *n){
    strcpy(nombre, n);
}

Pasajero ArchivoPasajeros::leerRegistro(int pos){

    FILE *p = fopen(nombre,"rb");
    Pasajero obj;
    if(p == nullptr){
        obj.setIdInt(-2);
        return obj;
    }
    obj.setIdInt(-1);
    fseek(p,  sizeof obj * pos, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);

    return obj;

}

bool ArchivoPasajeros::grabarRegistro(Pasajero obj){

    FILE *p = fopen(nombre, "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoPasajeros::modificarRegistro(Pasajero obj, int pos){

    FILE *p = fopen(nombre, "rb+");
    if(p == nullptr){
        return false;
    }
    fseek(p, sizeof obj * pos, 0);
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

int ArchivoPasajeros::contarRegistros(){

    FILE *p = fopen(nombre, "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p,0,2);
    int cant = ftell(p)/sizeof(Pasajero);
    fclose(p);
    return cant;
}

int ArchivoPasajeros::buscarRegistro(int idI){

    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++){
        Pasajero obj = leerRegistro(i);
        if(obj.getIdInt() == idI){
            return i;
        }
    }

    return -1;
}

void ArchivoPasajeros::listarRegistros(){

    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++){
        Pasajero obj = leerRegistro(i);
        obj.Mostrar();
    }
}

void ArchivoPasajeros::altaPasajero(){
    Pasajero obj;
    int id;
    cout << "Ingrese el ID del pasajero: ";
    cin >> id;
    if(id <= 0){
        cout << "Error: No se puede ingresar un ID igual o menor a cero" << endl;
        return;
    }
    ArchivoPasajeros arcPas;
    int pos = arcPas.buscarRegistro(id);
    if(pos >= 0){
        cout << endl << "Error: Ya existe pasajero con ese ID" << endl;
        return;
    }
    obj.Cargar(id);
    if(arcPas.grabarRegistro(obj)==false){
        cout<<"Error al grabar el registro"<<endl;
    }
}

void ArchivoPasajeros::buscarPorId(){
    int id;
    cout<<"Ingrese el ID del pasajero: ";
    cin>>id;
    ArchivoPasajeros arcPas;
    int pos = arcPas.buscarRegistro(id);
    if(pos < 0){
        cout << "El legajo ingresado no existe en el archivo" << endl;
        return;
    }
    Pasajero obj = arcPas.leerRegistro(pos);
    obj.Mostrar();
}

void ArchivoPasajeros::modificarNombre(){

    int id;
    cout<<"Ingrese el ID del pasajero: ";
    cin>>id;
    ArchivoPasajeros arcPas;
    int pos = arcPas.buscarRegistro(id);
    if(pos < 0){
        cout << "El legajo ingresado no existe en el archivo" << endl;
        return;
    }
    Pasajero obj;
    obj = arcPas.leerRegistro(pos);
    char nomAux[50];
    cout << "Ingresar nuevo nombre: ";
    cargarCadena(nomAux, 50);
    obj.setNombre(nomAux);
    arcPas.modificarRegistro(obj, pos);
}
