#include <iostream>
#include "clsFecha.h"
using namespace std;

Fecha::Fecha(int d, int m, int a){
    dia = d;
    mes = m;
    anio = a;
}

int Fecha::getDia(){
    return dia;
}

int Fecha::getMes(){
    return mes;
}

int Fecha::getAnio(){
    return anio;
}

void Fecha::setDia(int d){
    if(d > 0 && d < 32){
        dia = d;
    }else {
        dia = dia;
    }
}

void Fecha::setMes(int m){
    if(m > 0 && m < 13){
        mes = m;
    }else{
        mes = mes;
    }
}

void Fecha::setAnio(int a){
    anio = a;
}

void Fecha::cargarFecha(){
    cout << "Dia: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Anio: ";
    cin >> anio;
}

void Fecha::mostrarFecha(){
    cout << dia << "/" << mes << "/" << anio << endl;
}

Fecha::~Fecha(){

}
