#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "Pessoa.h"
#include <iostream>
using namespace std;

class Professor : public Pessoa
{
    public:
        Professor(string, string, string, string, string);
        virtual ~Professor();

    protected:

    private:
};

#endif // PROFESSOR_H
