#ifndef ALUNO_H
#define ALUNO_H
#include "Pessoa.h"
#include <iostream>
#include "Resultados.h"

using namespace std;

class Aluno : public Pessoa, public Resultados{
    public:
        Aluno(string, string, string, string, string);
        virtual ~Aluno();

    protected:

    private:
};

#endif // ALUNO_H
