#include <iostream>
#include <cstring>
#include "clsArchivoViajes.h"
#include "clsArchivoCapitanes.h"
#include "clsArchivoPasajeros.h"
#include "clsArchivoDestinos.h"
using namespace std;

ArchivoViajes::ArchivoViajes(const char *n){
    strcpy(nombre, n);
}

Viajes ArchivoViajes::leerRegistro(int pos){

    FILE *p = fopen(nombre,"rb");
    Viajes obj;
    if(p == nullptr){
        obj.setIdViaje(-2);
        return obj;
    }
    obj.setIdViaje(-1);
    fseek(p,  sizeof obj * pos, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);

    return obj;

}

bool ArchivoViajes::grabarRegistro(Viajes obj){

    FILE *p = fopen(nombre, "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoViajes::modificarRegistro(Viajes obj, int pos){

    FILE *p = fopen(nombre, "rb+");
    if(p == nullptr){
        return false;
    }
    fseek(p, sizeof obj * pos, 0);
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

int ArchivoViajes::contarRegistros(){

    FILE *p = fopen(nombre, "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p,0,2);
    int cant = ftell(p)/sizeof(Viajes);
    fclose(p);
    return cant;
}

int ArchivoViajes::buscarRegistro(int idV){

    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++){
        Viajes obj = leerRegistro(i);
        if(obj.getIdViaje() == idV){
            return i;
        }
    }

    return -1;
}

void ArchivoViajes::listarRegistros(){

    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++){
        Viajes obj = leerRegistro(i);
        obj.Mostrar();
    }
}

void ArchivoViajes::altaViaje(){
    Viajes obj;
    int id;
    cout << "Ingrese el ID del Viaje: ";
    cin >> id;
    if(id <= 0){
        cout << "Error: No se puede ingresar un ID igual o menor a cero" << endl;
        return;
    }
    ArchivoViajes arcVia;
    int pos = arcVia.buscarRegistro(id);
    if(pos >= 0){
        cout << endl << "Error: Ya existe viaje con ese ID" << endl;
        return;
    }
    int idCap;
    cout << "Ingrese el ID del capitan: ";
    cin >> idCap;
    ArchivoCapitanes arcCap;
    int posC = arcCap.buscarRegistro(idCap);
    if(posC < 0){
        cout << endl << "Error: No existe capitan con ese ID" << endl;
        return;
    }
    int idDes;
    cout << "Ingrese el ID del destino: ";
    cin >> idDes;
    ArchivoDestinos arcDes;
    int posD = arcDes.buscarRegistro(idDes);
    if(posD < 0){
        cout << endl << "Error: No existe destino con ese ID" << endl;
        return;
    }
    obj.Cargar(id, idCap, idDes);
    if(arcVia.grabarRegistro(obj)==false){
        cout<<"Error al grabar el registro"<<endl;
    }
}

void ArchivoViajes::buscarPorId(){
    int id;
    cout<<"Ingrese el ID del viaje: ";
    cin>>id;
    ArchivoViajes arcVia;
    int pos = arcVia.buscarRegistro(id);
    if(pos < 0){
        cout << "El legajo ingresado no existe en el archivo" << endl;
        return;
    }
    Viajes obj = arcVia.leerRegistro(pos);
    obj.Mostrar();
}
