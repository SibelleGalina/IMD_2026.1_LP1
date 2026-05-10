#ifndef AGENCIA_H
#define AGENCIA_H

#include <string>
#include <vector>

using namespace std;

//CLASSES
class Astronauta {
    public:
    string cpf, nome;
    int idade;
    bool vivo, disponível;
    Astronauta(string cpf, int idade, string nome); 
};

class Voo {
    public:
    int codigo;
    vector<string> cpfsPassageiros;
    string estado;
    Voo(int codigo);
};

//FUNÇÕES
void cadastrarAstronauta(string cpf, int idade, string nome);
void cadastrarVoo(int codigo);
void adicionarAstronauta(string cpf, int codigo);
void removerAstronauta(string cpf, int codigo);
void lancarVoo(int codigo);
void explodirVoo(int codigo);
void finalizarVoo(int codigo);
void listarVoos();
void listarMortos();
void imprimirPassageiros(Voo &voo);

#endif