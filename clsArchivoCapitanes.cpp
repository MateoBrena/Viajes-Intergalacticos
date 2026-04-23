#include <iostream>
#include <cstring>
#include "clsArchivoCapitanes.h"
using namespace std;

ArchivoCapitanes::ArchivoCapitanes(const char *n){
    strcpy(nombre, n);
}

Capitan ArchivoCapitanes::leerRegistro(int pos){

    FILE *p = fopen(nombre,"rb");
    Capitan obj;
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

bool ArchivoCapitanes::grabarRegistro(Capitan obj){

    FILE *p = fopen(nombre, "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoCapitanes::modificarRegistro(Capitan obj, int pos){

    FILE *p = fopen(nombre, "rb+");
    if(p == nullptr){
        return false;
    }
    fseek(p, sizeof obj * pos, 0);
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

int ArchivoCapitanes::contarRegistros(){

    FILE *p = fopen(nombre, "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p,0,2);
    int cant = ftell(p)/sizeof(Capitan);
    fclose(p);
    return cant;
}

int ArchivoCapitanes::buscarRegistro(int idI){

    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++){
        Capitan obj = leerRegistro(i);
        if(obj.getIdInt() == idI){
            return i;
        }
    }

    return -1;
}

void ArchivoCapitanes::listarRegistros(){

    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++){
        Capitan obj = leerRegistro(i);
        obj.Mostrar();
    }
}

void ArchivoCapitanes::altaCapitan(){
    Capitan obj;
    int id;
    cout << "Ingrese el ID del capitan: ";
    cin >> id;
    if(id <= 0){
        cout << "Error: No se puede ingresar un ID igual o menor a cero" << endl;
        return;
    }
    ArchivoCapitanes arcCap;
    int pos = arcCap.buscarRegistro(id);
    if(pos >= 0){
        cout << endl << "Error: Ya existe capitan con ese ID" << endl;
        return;
    }
    obj.Cargar(id);
    if(arcCap.grabarRegistro(obj)==false){
        cout<<"Error al grabar el registro"<<endl;
    }
}

void ArchivoCapitanes::buscarPorId(){
    int id;
    cout<<"Ingrese el ID del pasajero: ";
    cin>>id;
    ArchivoCapitanes arcCap;
    int pos = arcCap.buscarRegistro(id);
    if(pos < 0){
        cout << "El legajo ingresado no existe en el archivo" << endl;
        return;
    }
    Capitan obj = arcCap.leerRegistro(pos);
    obj.Mostrar();
}
