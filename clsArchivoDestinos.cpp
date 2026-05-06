#include <iostream>
#include <cstring>
#include "clsArchivoDestinos.h"
#include "cargarCadena.h"
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
        if(obj.getEstado()){
            obj.Mostrar();
            cout << endl;
        }
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

void ArchivoDestinos::buscarPorId(int id){
    if(id == -1){
        cout<<"Ingrese el ID de destino a buscar: ";
        cin>>id;
    }
    ArchivoDestinos arcDes;
    int pos = arcDes.buscarRegistro(id);
    if(pos < 0){
        cout << "El legajo ingresado no existe en el archivo" << endl;
        return;
    }
    Destinos obj = arcDes.leerRegistro(pos);
    obj.Mostrar();
}

void ArchivoDestinos::modificarNombre(){

    int id;
    cout<<"Ingrese el ID del destino: ";
    cin>>id;
    ArchivoDestinos arcDes;
    int pos = arcDes.buscarRegistro(id);
    if(pos < 0){
        cout << "El ID ingresado no existe en el archivo" << endl;
        return;
    }
    Destinos obj;
    obj = arcDes.leerRegistro(pos);
    char nomAux[50];
    cout << "Ingrese el nuevo nombre: ";
    cargarCadena(nomAux, 50);
    obj.setNombre(nomAux);
    arcDes.modificarRegistro(obj, pos);
}

void ArchivoDestinos::modificarDistancia(){

    int id;
    cout<<"Ingrese el ID del destino: ";
    cin>>id;
    ArchivoDestinos arcDes;
    int pos = arcDes.buscarRegistro(id);
    if(pos < 0){
        cout << "El ID ingresado no existe en el archivo" << endl;
        return;
    }
    Destinos obj;
    obj = arcDes.leerRegistro(pos);
    int dAux;
    cout << "Ingrese la nueva distancia: ";
    cin >> dAux;
    obj.setDistancia(dAux);
    arcDes.modificarRegistro(obj, pos);
}

void ArchivoDestinos::bajaDestino(){
    ArchivoDestinos arcDes;
    cout<<"Ingrese el ID del destino: ";
    int id;
    cin>>id;
    int pos = arcDes.buscarRegistro(id);
    if(pos < 0){
        cout<<"El ID ingresado no existe en el archivo"<<endl;
        return;
    }
    Destinos obj;
    obj = arcDes.leerRegistro(pos);
    if(obj.getEstado() == false){
        cout<<"El destino ya se encuentra dado de baja"<<endl;
        return;
    }
    obj.setEstado(false);
    if(arcDes.modificarRegistro(obj, pos)){
        cout<<"Baja realizada correctamente"<<endl;
    }else{
        cout<<"Error al realizar la baja"<<endl;
    }
}
