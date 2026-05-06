#ifndef CLSREPORTES_H_INCLUDED
#define CLSREPORTES_H_INCLUDED

class Reportes {
    private:

    public:
        Reportes();
        void cantidadPasajerosXViaje();
        void cantidadViajesCapVeteranos();
        void destinoMasVisitado();
        void mesMasVendido();
        int buscarPlanetaPorNombre(char *n);
        bool comprobarViajesCapitan(int idC, int idP);
        void capitanesPlanetasxTeclado();
};

#endif // CLSREPORTES_H_INCLUDED
