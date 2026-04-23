#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha(int d=1, int m=1, int a=2000);
        int getDia();
        int getMes();
        int getAnio();
        void setDia(int d);
        void setMes(int m);
        void setAnio(int a);
        void cargarFecha();
        void mostrarFecha();
        ~Fecha();
};

#endif // CLSFECHA_H_INCLUDED
