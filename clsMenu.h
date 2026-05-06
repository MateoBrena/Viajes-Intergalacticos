#ifndef CLSMENU_H_INCLUDED
#define CLSMENU_H_INCLUDED

#include "clsArchivoPasajeros.h"
#include "clsArchivoCapitanes.h"
#include "clsArchivoDestinos.h"
#include "clsArchivoViajes.h"
#include "clsArchivoPasajes.h"
#include "clsReportes.h"
#include <iostream>

using namespace std;

class Menu {
    private:
        ArchivoPasajeros gestorPasajeros;
        ArchivoCapitanes gestorCapitanes;
        ArchivoDestinos gestorDestinos;
        ArchivoViajes gestorViajes;
        ArchivoPasajes gestorPasajes;
        Reportes reportes;
        void menuModificarPasajeros();
        void menuPasajeros();
        void menuModificarCapitanes();
        void menuCapitanes();
        void menuModificarViajes();
        void menuViajes();
        void menuModificarDestinos();
        void menuDestinos();
        void menuReportes();
        void menuPasajes();
    public:
        Menu();
        void iniciar();
};

#endif // CLSMENU_H_INCLUDED
