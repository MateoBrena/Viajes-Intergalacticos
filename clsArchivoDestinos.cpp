#include <iostream>
#include <cstring>
#include "clsArchivoDestinos.h"
using namespace std;

ArchivoDestinos::ArchivoDestinos(const char *n){
    strcpy(nombre, n);
}

Destinos ArchivoDestinos::leerRegistro(int pos){

    FILE *p = fopen(nombre,"rb");
    Destinos obj;
    if(p == nullptr){
        obj.setIdDest(-2);
        return obj;
    }
    obj.setIdDest(-1);
    fseek(p,  sizeof obj * pos, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);

    return obj;

}

bool ArchivoDestinos::grabarRegistro(Destinos obj){

    FILE *p = fopen(nombre, "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoDestinos::modificarRegistro(Destinos obj, int pos){

    FILE *p = fopen(nombre, "rb+");
    if(p == nullptr){
        return false;
    }
    fseek(p, sizeof obj * pos, 0);
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

int ArchivoDestinos::contarRegistros(){

    FILE *p = fopen(nombre, "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p,0,2);
    int cant = ftell(p)/sizeof(Destinos);
    fclose(p);
    return cant;
}

int ArchivoDestinos::buscarRegistro(int idD){

    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++){
        Destinos obj = leerRegistro(i);
        if(obj.getIdDest() == idD){
            return i;
        }
    }

    return -1;
}

void ArchivoDestinos::listarRegistros(){

    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++){
        Destinos obj = leerRegistro(i);
        obj.Mostrar();
    }
}

void ArchivoDestinos::altaDestino(){
    Destinos obj;
    int id;
    cout << "Ingrese el ID del destino: ";
    cin >> id;
    if(id <= 0){
        cout << "Error: No se puede ingresar un ID igual o menor a cero" << endl;
        return;
    }
    ArchivoDestinos arcDes;
    int pos = arcDes.buscarRegistro(id);
    if(pos >= 0){
        cout << endl << "Error: Ya existe un destino con ese ID" << endl;
        return;
    }
    obj.Cargar(id);
    if(arcDes.grabarRegistro(obj)==false){
        cout<<"Error al grabar el registro"<<endl;
    }
}

void ArchivoDestinos::buscarPorId(){
    int id;
    cout<<"Ingrese el ID de destino a buscar: ";
    cin>>id;
    ArchivoDestinos arcDes;
    int pos = arcDes.buscarRegistro(id);
    if(pos < 0){
        cout << "El legajo ingresado no existe en el archivo" << endl;
        return;
    }
    Destinos obj = arcDes.leerRegistro(pos);
    obj.Mostrar();
}
