#include <iostream>
#include <cstring>
#include "clsArchivoViajes.h"
#include "clsArchivoPasajeros.h"
#include "clsArchivoPasajes.h"
using namespace std;

ArchivoPasajes::ArchivoPasajes(const char *n){
    strcpy(nombre, n);
}

Pasajes ArchivoPasajes::leerRegistro(int pos){

    FILE *p = fopen(nombre,"rb");
    Pasajes obj;
    if(p == nullptr){
        obj.setIdPasaje(-2);
        return obj;
    }
    obj.setIdPasaje(-1);
    fseek(p,  sizeof obj * pos, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);

    return obj;

}

bool ArchivoPasajes::grabarRegistro(Pasajes obj){

    FILE *p = fopen(nombre, "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoPasajes::modificarRegistro(Pasajes obj, int pos){

    FILE *p = fopen(nombre, "rb+");
    if(p == nullptr){
        return false;
    }
    fseek(p, sizeof obj * pos, 0);
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

int ArchivoPasajes::contarRegistros(){

    FILE *p = fopen(nombre, "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p,0,2);
    int cant = ftell(p)/sizeof(Pasajes);
    fclose(p);
    return cant;
}

int ArchivoPasajes::buscarRegistro(int idP){

    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++){
        Pasajes obj = leerRegistro(i);
        if(obj.getIdPasaje() == idP){
            return i;
        }
    }

    return -1;
}

void ArchivoPasajes::listarRegistros(){

    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++){
        Pasajes obj = leerRegistro(i);
        obj.Mostrar();
    }
}

void ArchivoPasajes::altaPasaje(){
    int idPas;
    cout << "Ingrese el ID del pasajero: ";
    cin >> idPas;
    ArchivoPasajeros arcPas;
    int posP = arcPas.buscarRegistro(idPas);
    if(posP < 0){
        cout << endl << "Error: No existe pasajero con ese ID" << endl;
        return;
    }
    int idVia;
    cout << "Ingrese el ID del viaje: ";
    cin >> idVia;
    ArchivoViajes arcVia;
    int posV = arcVia.buscarRegistro(idVia);
    if(posV < 0){
        cout << endl << "Error: No existe viaje con ese ID" << endl;
        return;
    }
    ArchivoPasajes arcPasj;
    int cant = contarRegistros();
    if(cant <0) cant =0;
    int id = cant + 1;
    Pasajes obj;
    obj.Cargar(id, idPas, idVia);
    if(arcPasj.grabarRegistro(obj)==false){
        cout<<"Error al grabar el registro"<<endl;
    }
}

void ArchivoPasajes::buscarPorId(){
    int id;
    cout<<"Ingrese el ID del pasaje: ";
    cin>>id;
    ArchivoPasajes arcPas;
    int pos = arcPas.buscarRegistro(id);
    if(pos < 0){
        cout << "El id de pasaje ingresado no existe en el archivo" << endl;
        return;
    }
    Pasajes obj = arcPas.leerRegistro(pos);
    obj.Mostrar();
}
