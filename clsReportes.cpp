#include <iostream>
#include <cstring>
#include "clsArchivoPasajeros.h"
#include "clsArchivoCapitanes.h"
#include "clsArchivoDestinos.h"
#include "clsArchivoViajes.h"
#include "clsArchivoPasajes.h"
#include "clsReportes.h"
#include "cargarCadena.h"

using namespace std;

Reportes::Reportes(){

}

void Reportes::cantidadPasajerosXViaje(){

    ArchivoViajes arcVia;
    int cantV = arcVia.contarRegistros();
    if(cantV <= 0){
        cout<<"No hay ningun viaje cargado."<<endl;
        return;
    }
    int *ids;
    ids = new int[cantV];
    if(ids==NULL){
        cout<<"ERROR DE ASIGNACION DE MEMORIA";
        return;
    }
    Viajes obj;
    for(int i=0; i<cantV; i++){
        obj = arcVia.leerRegistro(i);
        ids[i] = obj.getIdViaje();
    }
    int *pXid;
    pXid = new int[cantV]();
    if(pXid==NULL){
        cout<<"ERROR DE ASIGNACION DE MEMORIA";
        return;
    }
    ArchivoPasajes arcPas;
    int cantP = arcPas.contarRegistros();
    if(cantP <= 0){
        cout<<"No hay ningun pasaje cargado."<<endl;
        return;
    }
    Pasajes obj2;
    for(int i=0; i<cantV; i++){
        for(int j=0; j<cantP; j++){
            obj2 = arcPas.leerRegistro(j);
            if(ids[i] == obj2.getIdViaje()){
                pXid[i]++;
            }
        }
    }

    for(int i=0; i<cantV;i++){
        cout << "Viaje con ID " << ids[i] << " tiene " << pXid[i] << " pasajeros." << endl;
    }
    delete[] ids;
    delete[] pXid;
}

void Reportes::cantidadViajesCapVeteranos(){

    ArchivoCapitanes arcCap;
    int cantC = arcCap.contarRegistros();
    if(cantC <= 0){
        cout<<"No hay ningun capitan cargado."<<endl;
        return;
    }
    Capitan obj;
    int cantCapR3 = 0;
    for(int i=0; i<cantC;i++){
        obj = arcCap.leerRegistro(i);
        if(obj.getRango() == 3){
            cantCapR3++;
        }
    }
    if(cantCapR3 <= 0){
        cout << "No hay capitanes con rango veterano." << endl;
        return;
    }
    int *idsCap;
    idsCap = new int[cantCapR3];
    if(idsCap==NULL){
        cout<<"ERROR DE ASIGNACION DE MEMORIA";
        return;
    }
    int asignados = 0;
    for(int i=0; i<cantC;i++){
        obj = arcCap.leerRegistro(i);
        if(obj.getRango() == 3){
            idsCap[asignados] = obj.getIdInt();
            asignados++;
        }
    }
    ArchivoViajes arcVia;
    int cantV = arcVia.contarRegistros();
    if(cantV <= 0){
        cout<<"No hay ningun viaje cargado."<<endl;
        return;
    }
    int cantViajesR3=0;
    Viajes obj2;
    for(int i=0; i<cantV; i++){
        for(int j=0; j<cantCapR3; j++){
            obj2 = arcVia.leerRegistro(i);
            if(obj2.getIdCapitan() == idsCap[j]){
                cantViajesR3++;
            }
        }
    }

    cout << "Cantidad de viajes de capitanes veteranos: " << cantViajesR3;
    delete[] idsCap;
}

void Reportes::destinoMasVisitado(){

    ArchivoDestinos arcDes;
    int cantD = arcDes.contarRegistros();
    int *idsDes;
    idsDes = new int[cantD];
    if(idsDes==NULL){
        cout<<"ERROR DE ASIGNACION DE MEMORIA";
        return;
    }
    Destinos obj;
    for(int i=0; i<cantD; i++){
        obj = arcDes.leerRegistro(i);
        if(obj.getEstado()){
            idsDes[i] = obj.getIdDest();
        }
    }
    ArchivoViajes arcVia;
    int cantV = arcVia.contarRegistros();
    ArchivoPasajes arcPasj;
    int cantPas = arcPasj.contarRegistros();
    int *pjXDes;
    pjXDes = new int[cantD]{};
    if(pjXDes==NULL){
        cout<<"ERROR DE ASIGNACION DE MEMORIA";
        return;
    }
    for(int i=0; i<cantPas; i++){
        Pasajes obj = arcPasj.leerRegistro(i);
        for(int j=0; j<cantV; j++){
            Viajes obj2 = arcVia.leerRegistro(j);
            if((obj.getIdViaje() == obj2.getIdViaje()) && (obj.getEstado() && obj2.getEstado())){
                for(int k=0; k<cantD; k++){
                    if(obj2.getIdDestino() == idsDes[k]){
                        pjXDes[k]++;
                    }
                }
            }
        }
    }

    int *posDes;
    posDes = new int[cantD];

    for(int i=0; i<cantD; i++){
        posDes[i] = i;
    }

    bool huboIntercambio;
    for (int i = 0; i < cantD - 1; i++) {
        huboIntercambio = false;
        for (int j = 0; j < cantD - i - 1; j++) {
            if (pjXDes[posDes[j]] > pjXDes[posDes[j + 1]]) {

                int temp = posDes[j];
                posDes[j] = posDes[j + 1];
                posDes[j + 1] = temp;

                huboIntercambio = true;
            }
        }
        if (!huboIntercambio) break;
    }

    cout << "Destino mas vendido: " << endl << endl;
    arcDes.buscarPorId(idsDes[posDes[cantD-1]]);
    //cout << "Cantidad de pasajes vendidos: " <<

    delete[] idsDes;
    delete[] pjXDes;
    delete[] posDes;

}

void Reportes::mesMasVendido(){

    const int cantMeses = 12;
    int meses[cantMeses]{1,2,3,4,5,6,7,8,9,10,11,12};
    int pasXMes[cantMeses]{};
    int posMes[cantMeses]{0,1,2,3,4,5,6,7,8,9,10,11};
    string nombMeses[cantMeses]={"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio","Julio","Agosto","Septiembre","Octubre",
    "Noviembre","Diciembre"};
    ArchivoPasajes arcPasj;
    int cantPas = arcPasj.contarRegistros();
    for(int i=0; i<cantPas; i++){
        Pasajes obj = arcPasj.leerRegistro(i);
        for(int j=0; j<cantMeses; j++){
            if(obj.getFechaCompra().getMes() == meses[j]){
                pasXMes[j]++;
            }
        }

    }

    bool huboIntercambio;
    for (int i = 0; i < cantMeses - 1; i++) {
        huboIntercambio = false;
        for (int j = 0; j < cantMeses - i - 1; j++) {
            if (pasXMes[posMes[j]] > pasXMes[posMes[j + 1]]) {

                int temp = posMes[j];
                posMes[j] = posMes[j + 1];
                posMes[j + 1] = temp;

                huboIntercambio = true;
            }
        }
        if (!huboIntercambio) break;
    }

    cout << "El mes con mayor ventas es el mes: " << nombMeses[meses[posMes[cantMeses-1]]-1] << endl;
    cout << "Cantidad de pasajes vendidos: " << pasXMes[posMes[cantMeses-1]] << endl;

}

int Reportes::buscarPlanetaPorNombre(char *n){

    ArchivoDestinos arcDes;
    int cantDes = arcDes.contarRegistros();
    for(int i=0; i<cantDes; i++){
        Destinos obj = arcDes.leerRegistro(i);
        if(strcmp(obj.getNombre(), n)==0){
            return obj.getIdDest();
        }
    }
    return -1;
}

bool Reportes::comprobarViajesCapitan(int idC, int idP){
    ArchivoViajes arcVia;
    int cantVia = arcVia.contarRegistros();
    for(int i=0; i<cantVia; i++){
        Viajes obj = arcVia.leerRegistro(i);
        if(obj.getIdCapitan() == idC && obj.getIdDestino() == idP){
            return true;
        }
    }

    return false;
}

void Reportes::capitanesPlanetasxTeclado(){

    char nombrePlaneta[50];
    cout << "Ingrese el nombre del planeta: ";
    cargarCadena(nombrePlaneta,50);
    int idPlaneta = buscarPlanetaPorNombre(nombrePlaneta);
    if(idPlaneta == -1){
        cout << "El nombre ingresado no existe en el archivo." << endl;
        return;
    }
    ArchivoCapitanes arcCap;
    int cantCap = arcCap.contarRegistros();
    for(int i=0; i<cantCap; i++){
        Capitan obj = arcCap.leerRegistro(i);
        if(comprobarViajesCapitan(obj.getIdInt(), idPlaneta) == true){
            obj.Mostrar();
        }
    }

}
