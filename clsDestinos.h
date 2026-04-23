#ifndef CLSDESTINOS_H_INCLUDED
#define CLSDESTINOS_H_INCLUDED

class Destinos {

    private:
        int idDestino;
        char nombre[50];
        int distancia;
    public:
        Destinos();
        void setIdDest(int id);
        void setNombre(const char* n);
        void setDistancia(int d);
        int getIdDest();
        const char *getNombre();
        int getDistancia();
        void Cargar(int id);
        void Mostrar();
};

#endif // CLSDESTINOS_H_INCLUDED
