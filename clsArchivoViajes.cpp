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
        if(obj.getEstado()){
            obj.Mostrar();
            cout << endl;
        }
    }
}

void ArchivoViajes::altaViaje(){

    int idCap;
    cout << "Ingrese el ID del capitan: ";
    cin >> idCap;
    ArchivoCapitanes arcCap;
    int posC = arcCap.buscarRegistro(idCap);
    Capitan obj2 = arcCap.leerRegistro(posC);
    if(posC < 0 || obj2.getEstado() == false){
        cout << endl << "Error: No existe capitan con ese ID o fue dado de baja" << endl;
        return;
    }
    int idDes;
    cout << "Ingrese el ID del destino: ";
    cin >> idDes;
    ArchivoDestinos arcDes;
    int posD = arcDes.buscarRegistro(idDes);
    Destinos obj3 = arcDes.leerRegistro(posD);
    if(posD < 0 || obj3.getEstado() == false){
        cout << endl << "Error: No existe destino con ese ID o fue dado de baja" << endl;
        return;
    }
    ArchivoViajes arcVia;
    int cant = arcVia.contarRegistros();
    if(cant <0) cant = 0;
    int id = cant + 1;
    Viajes obj;
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
        cout << "El ID ingresado no existe en el archivo" << endl;
        return;
    }
    Viajes obj = arcVia.leerRegistro(pos);
    obj.Mostrar();
}

void ArchivoViajes::modificarIdCapitan(){
    int id;
    cout<<"Ingrese el ID del viaje: ";
    cin>>id;
    ArchivoViajes arcVia;
    int pos = arcVia.buscarRegistro(id);
    if(pos < 0){
        cout << "El ID ingresado no existe en el archivo" << endl;
        return;
    }
    Viajes obj = arcVia.leerRegistro(pos);
    int idAux;
    cout << "Ingrese el nuevo ID de capitan: ";
    cin >> idAux;
    ArchivoCapitanes arcCap;
    int posC = arcCap.buscarRegistro(idAux);
    Capitan obj2 = arcCap.leerRegistro(posC);
    if(posC < 0 || obj2.getEstado() == false){
        cout << "No existe capitan con el ID ingresado o fue dado de baja" << endl;
        return;
    }
    obj.setIdCapitan(idAux);
    arcVia.modificarRegistro(obj, pos);
}

void ArchivoViajes::modificarIdDestino(){
    int id;
    cout<<"Ingrese el ID del viaje: ";
    cin>>id;
    ArchivoViajes arcVia;
    int pos = arcVia.buscarRegistro(id);
    if(pos < 0){
        cout << "El ID ingresado no existe en el archivo" << endl;
        return;
    }
    Viajes obj = arcVia.leerRegistro(pos);
    int idAux;
    cout << "Ingrese el nuevo ID de destino: ";
    cin >> idAux;
    ArchivoDestinos arcDes;
    int posD = arcDes.buscarRegistro(idAux);
    Destinos obj2 = arcDes.leerRegistro(posD);
    if(posD < 0 || obj2.getEstado() == false){
        cout << "No existe destino con el ID ingresado o fue dado de baja" << endl;
        return;
    }
    obj.setIdDestino(idAux);
    arcVia.modificarRegistro(obj, pos);
}

void ArchivoViajes::modificarTiempoViaje(){
    int id;
    cout<<"Ingrese el ID del viaje: ";
    cin>>id;
    ArchivoViajes arcVia;
    int pos = arcVia.buscarRegistro(id);
    if(pos < 0){
        cout << "El ID ingresado no existe en el archivo" << endl;
        return;
    }
    Viajes obj = arcVia.leerRegistro(pos);
    int tAux;
    cout << "Ingrese el nuevo tiempo de viaje: ";
    cin >> tAux;
    obj.setTiempoViaje(tAux);
    arcVia.modificarRegistro(obj, pos);
}

void ArchivoViajes::bajaViaje(){
    ArchivoViajes arcVia;
    cout<<"Ingrese el ID del viaje: ";
    int id;
    cin>>id;
    int pos = arcVia.buscarRegistro(id);
    if(pos < 0){
        cout<<"El ID ingresado no existe en el archivo"<<endl;
        return;
    }
    Viajes obj;
    obj = arcVia.leerRegistro(pos);
    if(obj.getEstado() == false){
        cout<<"El viaje ya se encuentra dado de baja"<<endl;
        return;
    }
    obj.setEstado(false);
    if(arcVia.modificarRegistro(obj, pos)){
        cout<<"Baja realizada correctamente"<<endl;
    }else{
        cout<<"Error al realizar la baja"<<endl;
    }
}
