#include "Pessoa.h"

Pessoa::Pessoa(string _nome, string _endereco, string _email, string _cpf, string _telefone){
    nome = _nome;
    endereco = _endereco;
    email = _email;
    cpf = _cpf;
    telefone = _telefone;
}

Pessoa::~Pessoa(){

}

void Pessoa::setNome(string _nome){
    nome = _nome;
}

string Pessoa::getNome(){
    return nome;
}

void Pessoa::setEndereco(string _endereco){
    endereco = _endereco;
}

string Pessoa::getEndereco(){
    return endereco;
}

void Pessoa::setEmail(string _email){
    email = _email;
}

string Pessoa::getEmail(){
    return email;
}

void Pessoa::setCpf(string _cpf){
    cpf = _cpf;
}

string Pessoa::getCpf(){
    return cpf;
}

void Pessoa::setTelefone(string _telefone){
    telefone = _telefone;
}

string Pessoa::getTelefone(){
    return telefone;
}

