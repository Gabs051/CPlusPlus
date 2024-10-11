#include "Resultados.h"
#include <string>
using namespace std;

Resultados::Resultados(){

}

Resultados::~Resultados(){

}

double Resultados::getNota1() const{
    return nota1;
}

void Resultados::setNota1(double _nota1){
    nota1 = _nota1;
}

double Resultados::getNota2() const{
    return nota2;
}

void Resultados::setNota2(double _nota2){
    nota2 = _nota2;
}

int Resultados::getFaltas() const{
    return faltas;
}

void Resultados::setFaltas(int _faltas){
    faltas = _faltas;
}

double Resultados::getMedia() const{
    return (nota1 + nota2) /2;
}

string Resultados::getAprovacao(){
    return aprovacao;
}

void Resultados::setAprovacao(){
    double media = (nota1 + nota2) /2;
    if(media >= 7){
        aprovacao = "aprovado";
    } else {
        aprovacao = "reprovado";
    }
}
