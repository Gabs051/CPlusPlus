#ifndef ADMIN_H
#define ADMIN_H
#include "Pessoa.h"
#include <iostream>
using namespace std;

class Admin : public Pessoa
{
    public:
        Admin(string, string, string, string, string);
        virtual ~Admin();

    protected:

    private:
};

#endif // ADMIN_H
