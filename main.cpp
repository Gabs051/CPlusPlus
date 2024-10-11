#include <iostream>
#include <vector>
#include "Pessoa.h"
#include "Aluno.h"
#include "Admin.h"
#include "Professor.h"
#include <limits>
#include <chrono>
#include <thread>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

vector <Aluno> alunos;
vector <Professor> professores;
vector <Admin> administradores;

void printWithDelay(const string &text, int delay){
    for(char c : text){
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
}

void cadastrarAluno(){
    string nome, endereco, email, cpf, telefone;
    float nota1, nota2;
    int faltas;

    printWithDelay("<--------------------CADASTRO DE ALUNOS-------------------->\n", 30);
    printWithDelay("Digite o nome do aluno: ", 5);
    cin.ignore();
    getline(cin, nome);

    printWithDelay("Digite o endereco do aluno: ", 5);
    cin.ignore();
    getline(cin, endereco);

    printWithDelay("Digite o email do aluno: ", 5);
    cin >> email;

    printWithDelay("Digite o cpf do aluno: ", 5);
    cin >> cpf;

    printWithDelay("Digite o telefone do aluno: ", 5);
    cin.ignore();
    getline(cin, telefone);

    printWithDelay("Digite a nota1 do aluno: ", 5);
    cin >> nota1;

    printWithDelay("Digite a nota2 do aluno: ", 5);
    cin >> nota2;

    printWithDelay("Digite a quantidade de faltas do aluno: ", 5);
    cin >> faltas;

    Aluno aluno(nome, endereco, email, cpf, telefone);
    aluno.setNota1(nota1);
    aluno.setNota2(nota2);
    aluno.setFaltas(faltas);

    aluno.setAprovacao();
    alunos.push_back(aluno);

    ofstream outFile("alunos.db", ios::app); // Modo append

    if (!outFile) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return; // Encerra a função se houver erro
    }

    // Escreve os dados do aluno no arquivo
    outFile << aluno.getNome() << ","
            << aluno.getEndereco() << ","
            << aluno.getEmail() << ","
            << aluno.getCpf() << ","
            << aluno.getTelefone() << ","
            << aluno.getNota1() << ","
            << aluno.getNota2() << ","
            << aluno.getFaltas() << ","
            << aluno.getAprovacao() << "\n";

    // Fechando o arquivo
    outFile.close();

    cout << "Dados do aluno salvos com sucesso! Pressione 'enter' para continuar." << endl;
    cin.ignore();
}

void cadastrarProfessor(){
    string nome, endereco, email, cpf, telefone;

    printWithDelay("Digite o nome do professor: ", 5);
    cin.ignore();
    getline(cin, nome);

    printWithDelay("Digite o endereco do professor: ", 5);
    cin.ignore();
    getline(cin, endereco);

    printWithDelay("Digite o email do professor: ", 5);
    cin >> email;

    printWithDelay("Digite o cpf do professor: ", 5);
    cin >> cpf;

    printWithDelay("Digite o telefone do professor: ", 5);
    cin.ignore();
    getline(cin, telefone);

    Professor professor(nome, endereco, email, cpf, telefone);
}

void cadastrarAdmnistrador(){
    string nome, endereco, email, cpf, telefone;

    printWithDelay("Digite o nome do administrador: ", 5);
    cin.ignore();
    getline(cin, nome);

    printWithDelay("Digite o endereco do administrador: ", 5);
    cin.ignore();
    getline(cin, endereco);

    printWithDelay("Digite o email do administrador: ", 5);
    cin >> email;

    printWithDelay("Digite o cpf do administrador: ", 30);
    cin >> cpf;

    printWithDelay("Digite o telefone do administrador: ", 5);
    cin.ignore();
    getline(cin, telefone);

    Professor professor(nome, endereco, email, cpf, telefone);
}

void limpaTela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif // _WIN32
}

void exibirAluno(){
    if (alunos.empty()) {  // Adicionado para verificar se a lista está vazia
        cout << "Nenhum aluno cadastrado.\n";
        return;
    }
    for(size_t i=0; i<alunos.size(); i++){
        cout << "\nNOME:          " + alunos[i].getNome() +
                "\nFALTAS:        " + to_string(alunos[i].getFaltas()) +
                "\nMEDIA:         " + to_string(alunos[i].getMedia()) +
                "\nAPROVACAO:     " + alunos[i].getAprovacao() + "\n";
    }
}

void printLargeTitle(){
    cout << "\033[31m                   (          ) (           \n";
    cout << " (       (      (  )\\ )    ( /( )\\ )     )  \n";
    cout << " )\\ )    )\\   ( )\\(()/((   )\\()(()/ )  /(  \n";
    cout << "(()/( ((((_)( )((_)/(_))\\ ((_\\ /(_)( )(_))  \n";
    cout << " /(_))_)\ _ )((_)_(_))((_) _((_(_))(_(_())\033[32m  \n";
    cout << "(_)) __(_)_\\(_| _ / __| __| \\| |_ _|_   _|  \n";
    cout << "  | (_ |/ _ \\ | _ \\__ | _|| . || |  | |    \n";
    cout << "   \\___/_/ \\_\\|___|___|___|_|\\_|___| |_|    \n";
    cout << "                                            \033[m\n";
}

void carregarAlunos() {
    ifstream inFile("alunos.db");
    if (!inFile) {
        cerr << "Erro ao abrir o arquivo de alunos!" << endl;
        return; // Encerra a função se houver erro
    }

    string linha;
    while (getline(inFile, linha)) {
        // Supondo que os dados estejam separados por vírgulas
        istringstream iss(linha);
        string nome, endereco, email, cpf, telefone, nota1Str, nota2Str, faltasStr, aprovacao;

        getline(iss, nome, ',');
        getline(iss, endereco, ',');
        getline(iss, email, ',');
        getline(iss, cpf, ',');
        getline(iss, telefone, ',');
        getline(iss, nota1Str, ',');
        getline(iss, nota2Str, ',');
        getline(iss, faltasStr, ',');
        getline(iss, aprovacao, ',');

        // Aqui você pode criar um novo objeto Aluno e adicionar à lista ou imprimir os dados
        cout << "\nNOME:        " << nome
             << "\nENDERECO:    " << endereco
             << "\nEMAIL:       " << email
             << "\nCPF:         " << cpf
             << "\nTELEFONE:    " << telefone
             << "\nNOTA1:       " << nota1Str
             << "\nNOTA2:       " << nota2Str
             << "\nFALTAS:      " << faltasStr
             << "\nAPROVACAO:   " << aprovacao
             << "\n" << endl;
        cin.ignore();
    }

    inFile.close();
}

int main(){
    int opcao, opcaoSubMenu;

    do
    {
        limpaTela();
        printLargeTitle();
        printWithDelay("####################Escolha uma opcao###################\n", 5);
        printWithDelay("[1] Cadastros\n", 5);
        printWithDelay("[2] Resultado do aluno\n", 5);
        printWithDelay("[3] Carregar alunos do arquivo\n", 5);
        printWithDelay("[0] Sair\n", 5);
        printWithDelay("########################################################\n", 5);
        printWithDelay("Resposta: ", 5);
        cin >> opcao;

        cin.clear(); // Adicionado para limpar o estado de erro
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Adicionado para ignorar até o próximo '\n'

        switch (opcao)
        {
        case 1:
            limpaTela();
            printLargeTitle();

            printWithDelay("####################Escolha uma opcao###################\n", 5);
            printWithDelay("[1] Cadastrar Aluno\n", 5);
            printWithDelay("[2] Cadastrar Professor\n", 5);
            printWithDelay("[3] Cadastrar administrador\n", 5);
            printWithDelay("[0] Sair\n", 5);
            printWithDelay("########################################################\n", 5);
            printWithDelay("Resposta: ", 5);
            cin >> opcaoSubMenu;

            switch (opcaoSubMenu)
            {
            case 1:
                limpaTela();
                printLargeTitle();
                cadastrarAluno();
                break;

            case 2:
                limpaTela();
                printLargeTitle();
                cadastrarProfessor();
                break;

            case 3:
                limpaTela();
                printLargeTitle();
                cadastrarAdmnistrador();
                break;

            case 0:
                printWithDelay("Saindo...\n", 5);
                break;

            default:
                break;
            }
            break;

        case 2:
            limpaTela();
            printLargeTitle();
            exibirAluno();
            cout << "Pressione 'enter' para continuar..." << endl; // Adicionado para instruir o usuário
            cin.ignore(); // Adicionado para esperar a entrada do usuário
            break;

        case 3: // New case for loading students
            carregarAlunos();
            cin.ignore();
            break;

        case 0:
            printWithDelay("Saindo...\n", 5);
            break;

        default:
            break;
        }
    } while (opcao != 0);

    return 0;
}
