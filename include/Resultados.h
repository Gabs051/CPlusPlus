#ifndef RESULTADOS_H
#define RESULTADOS_H
#include <iostream>
using namespace std;


class Resultados{
    public:
        Resultados();
        virtual ~Resultados();

        double media;

        double getNota1() const;
        void setNota1(double _nota1);

        double getNota2() const;
        void setNota2(double _nota2);

        double getMedia() const;

        int getFaltas() const;
        void setFaltas(int _faltas);

        string getAprovacao();
        void setAprovacao();

    protected:

    private:
        double nota1;
        double nota2;
        int faltas;
        string aprovacao;
};

#endif // RESULTADOS_H
