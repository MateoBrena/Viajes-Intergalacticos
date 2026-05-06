#include <iostream>
#include <cstring>
#include "clsArchivoCapitanes.h"
#include "clsArchivoPasajeros.h"
#include "cargarCadena.h"
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
        if(obj.getEstado()){
            obj.Mostrar();
            cout << endl;
        }
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
    ArchivoPasajeros arcPas;
    int pos = arcCap.buscarRegistro(id);
    int pos2 = arcPas.buscarRegistro(id);
    if(pos >= 0 || pos2 >= 0){
        cout << endl << "Error: Ya existe persona con ese ID" << endl;
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

void ArchivoCapitanes::modificarNombre(){

    int id;
    cout<<"Ingrese el ID del capitan: ";
    cin>>id;
    ArchivoCapitanes arcCap;
    int pos = arcCap.buscarRegistro(id);
    if(pos < 0){
        cout << "El ID ingresado no existe en el archivo" << endl;
        return;
    }
    Capitan obj;
    obj = arcCap.leerRegistro(pos);
    char nomAux[50];
    cout << "Ingrese el nuevo nombre: ";
    cargarCadena(nomAux, 50);
    obj.setNombre(nomAux);
    arcCap.modificarRegistro(obj, pos);
}

void ArchivoCapitanes::modificarApellido(){

    int id;
    cout<<"Ingrese el ID del capitan: ";
    cin>>id;
    ArchivoCapitanes arcCap;
    int pos = arcCap.buscarRegistro(id);
    if(pos < 0){
        cout << "El ID ingresado no existe en el archivo" << endl;
        return;
    }
    Capitan obj;
    obj = arcCap.leerRegistro(pos);
    char apAux[50];
    cout << "Ingrese el nuevo apellido: ";
    cargarCadena(apAux, 50);
    obj.setApellido(apAux);
    arcCap.modificarRegistro(obj, pos);
}

void ArchivoCapitanes::modificarFechaNacimiento(){

    int id;
    cout<<"Ingrese el ID del capitan: ";
    cin>>id;
    ArchivoCapitanes arcCap;
    int pos = arcCap.buscarRegistro(id);
    if(pos < 0){
        cout << "El ID ingresado no existe en el archivo" << endl;
        return;
    }
    Capitan obj;
    obj = arcCap.leerRegistro(pos);
    Fecha faux;
    cout << "Ingrese la nueva fecha de nacimiento: " << endl;
    faux.cargarFecha();
    obj.setFechaNacimiento(faux);
    arcCap.modificarRegistro(obj, pos);
}

void ArchivoCapitanes::modificarRango(){

    int id;
    cout<<"Ingrese el ID del capitan: ";
    cin>>id;
    ArchivoCapitanes arcCap;
    int pos = arcCap.buscarRegistro(id);
    if(pos < 0){
        cout << "El ID ingresado no existe en el archivo" << endl;
        return;
    }
    Capitan obj;
    obj = arcCap.leerRegistro(pos);
    int rAux;
    cout << "Ingrese el nuevo nivel de rango: (1-Novato, 2-Experimentado, 3-Veterano): ";
    cin >> rAux;
    obj.setRango(rAux);
    arcCap.modificarRegistro(obj, pos);
}

void ArchivoCapitanes::bajaCapitan(){
    ArchivoCapitanes arcCap;
    cout<<"Ingrese el ID del capitan: ";
    int id;
    cin>>id;
    int pos = arcCap.buscarRegistro(id);
    if(pos < 0){
        cout<<"El ID ingresado no existe en el archivo"<<endl;
        return;
    }
    Capitan obj;
    obj = arcCap.leerRegistro(pos);
    if(obj.getEstado() == false){
        cout<<"El capitan ya se encuentra dado de baja"<<endl;
        return;
    }
    obj.setEstado(false);
    if(arcCap.modificarRegistro(obj, pos)){
        cout<<"Baja realizada correctamente"<<endl;
    }else{
        cout<<"Error al realizar la baja"<<endl;
    }
}
