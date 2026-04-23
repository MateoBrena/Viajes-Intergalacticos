#ifndef CLSMENU_H_INCLUDED
#define CLSMENU_H_INCLUDED

#include "clsArchivoPasajeros.h"
#include "clsArchivoCapitanes.h"
#include "clsArchivoDestinos.h"
#include "clsArchivoViajes.h"
#include "clsArchivoPasajes.h"
#include <iostream>

using namespace std;

class Menu {

    private:
        ArchivoPasajeros gestorPasajeros;
        ArchivoCapitanes gestorCapitanes;
        ArchivoDestinos gestorDestinos;
        ArchivoViajes gestorViajes;
        ArchivoPasajes gestorPasajes;
        void menuModificarPasajeros();
        void menuPasajeros();
        void menuCapitanes();
        void menuViajes();
        void menuDestinos();
        void menuPasajes();
        //void menuBajas();

    public:
        Menu();
        void iniciar();
};

#endif // CLSMENU_H_INCLUDED
