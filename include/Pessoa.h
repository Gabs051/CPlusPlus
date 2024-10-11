#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>
using namespace std;


class Pessoa{
    public:
        Pessoa(string, string, string, string, string);
        virtual ~Pessoa();

        string getNome();
        string getEndereco();
        string getEmail();
        string getCpf();
        string getTelefone();

    protected:

    private:
        string nome;
        string endereco;
        string email;
        string cpf;
        string telefone;

        void setNome(string);
        void setEndereco(string);
        void setEmail(string);
        void setCpf(string);
        void setTelefone(string);
};

#endif // PESSOA_H
