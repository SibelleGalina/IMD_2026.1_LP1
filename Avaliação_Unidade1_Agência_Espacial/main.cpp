#include <iostream>
#include <string>
#include <vector>

//detecção de sistema windows com garantia contra erro conflitante do namespace
#ifdef _WIN32
    #define NOMINMAX
    #define WIN32_LEAN_AND_MEAN   
    #include <windows.h>
#endif

#include "agencia.h"

using namespace std;


//DECLARAÇÃO DE VETORES ***********************************
vector<Astronauta> listaAstronautas;
vector<Voo> listaVoos;

//CONSTRUTORES DAS CLASSES
Astronauta::Astronauta(string cpf, int idade, string nome) {
    this->cpf = cpf;
    this->idade = idade;
    this->nome = nome;
    this->vivo = true;
    this->disponível = true;
}

Voo::Voo(int codigo) {
    this->codigo = codigo;
    this->estado = "planejado";
}

int main() {
//configuração para acentuação no terminal
    #ifdef _WIN32
      SetConsoleOutputCP(65001);
      SetConsoleCP(65001);
    #endif
    
    string comando;
    while (cin >> comando) {
        if (comando == "FIM") {
        break;
    }
        if (comando == "CADASTRAR_ASTRONAUTA") {
            string cpf, nome;
            int idade;
            cin >> cpf;
            cin >> idade;
            getline(cin >> ws, nome);
            cadastrarAstronauta(cpf, idade, nome);
        }
        else if(comando == "CADASTRAR_VOO") {
            int codigo;
            cin >> codigo;
            cadastrarVoo(codigo);
        }
        else if(comando == "ADICIONAR_ASTRONAUTA"){
            string cpf;
            int codigo;
            cin >> cpf;
            cin >> codigo;
            adicionarAstronauta(cpf, codigo);
        }
        else if (comando == "REMOVER_ASTRONAUTA"){
            string cpf;
            int codigo;
            cin >> cpf;
            cin >> codigo;
            removerAstronauta(cpf, codigo);
        }
        else if (comando == "LANCAR_VOO"){
            int codigo;
            cin >> codigo;
            lancarVoo(codigo);
        }
        else if (comando == "EXPLODIR_VOO"){
            int codigo;
            cin >> codigo;
            explodirVoo(codigo);
        }
        else if (comando == "FINALIZAR_VOO"){
            int codigo;
            cin >> codigo;
            finalizarVoo(codigo);
        }
        else if (comando == "LISTAR_VOOS"){
            listarVoos();
        }
        else if (comando == "LISTAR_MORTOS"){
            listarMortos();
        }
    }

    return 0;
}
//=======================================================================================
//===                     DECLARAÇÃO DE FUNÇÕES A PARTIR DAQUI                        ===
//=======================================================================================

//************** CADASTRO DE ASTRONAUTAS ************************************************
void cadastrarAstronauta(string cpf, int idade, string nome){
    bool existe = false;
//percorrendo lista de astronautas para verificar duplicidade
    for (int i = 0; i < listaAstronautas.size(); i++) {
        if (listaAstronautas[i].cpf == cpf) {
            existe = true;
            break;
        }
    }
//tratando duplicidade e adicionando novo astronauta
    if (existe) {
        cout << "Erro: CPF já cadastrado." << endl;
    } else {
        Astronauta novo(cpf, idade, nome);
        listaAstronautas.push_back(novo);
        cout << "Cadastro do(a) Astronauta " << nome << " concluído.\n";
    }
}

//************** CADASTRO DE VOOS *******************************************************
void cadastrarVoo(int codigo){
    bool existe = false;
//percorrendo lista de voos para verificar duplicidade
    for (int i = 0; i < listaVoos.size(); i++) {
        if (listaVoos[i].codigo == codigo) {
            existe = true;
            break;
        }
    }
//tratando duplicidade e adicionando novo astronauta
    if (existe) {
        cout << "Erro: Voo " << codigo << " já cadastrado." << endl;
    } else {
        Voo novo(codigo);
        listaVoos.push_back(novo);
        cout << "Cadastro do Voo " << codigo << " concluído.\n";
    }
}

//************** ADICIONAR ASTRONAUTAS A UM VOO *****************************************
void adicionarAstronauta(string cpf, int codigo){
    int indiceAstronauta = -1;
    int indiceVoo = -1;
//procurando astronauta
    for (int i = 0; i < listaAstronautas.size(); i++) {
        if (listaAstronautas[i].cpf == cpf) {
            indiceAstronauta = i;
            break;
        }
    }
//procurando voo
    for (int i = 0; i < listaVoos.size(); i++){
        if (listaVoos[i].codigo == codigo) {
            indiceVoo = i;
            break;
        }
    }
//tratando resultado negativo
    if (indiceAstronauta == -1 || indiceVoo == -1) {
        cout << "Erro: Astronauta ou Voo não cadastrado. Verifique o registro correto no Banco de Dados da Agência." << endl;
//verificando status válidos
    } else {
        Astronauta &astronauta = listaAstronautas[indiceAstronauta];
        Voo &voo = listaVoos[indiceVoo];

        if (voo.estado != "planejado") {
            cout << "Erro: Impossível registrar astronautas em Voo não planejado. Verifique o status do Voo " << codigo << " no Banco de Dados da Agência." << endl;
        }
        else if (!astronauta.vivo) {
            cout << "Erro: Impossível adicionar ao Voo. O astronauta " << astronauta.nome << " está morto. " << endl;
        }
//verificando duplicidade e adicionando astronauta no voo
        else {
            bool cadastroDuplicado = false;
            for (int i = 0; i < voo.cpfsPassageiros.size(); i++) {
                string cpfVerificado = voo.cpfsPassageiros[i];
                if (cpfVerificado == cpf) cadastroDuplicado = true;
            }

            if(cadastroDuplicado) {
            cout << "Erro: Astronauta " << astronauta.nome << " já cadastrado neste voo." << endl;
            } else {
                voo.cpfsPassageiros.push_back(cpf);
                cout << "Astronauta " << astronauta.nome << " adicionado ao Voo " << codigo << " com sucesso.\n";
            }
        }
    }
}

//************** REMOVER ASTRONAUTAS DE UM VOO *******************************************
void removerAstronauta(string cpf, int codigo){
//procurando voo cadastrado
    int indiceVoo = -1;
    for (int i = 0; i < listaVoos.size(); i++) {
        if (listaVoos[i].codigo == codigo) {
            indiceVoo = i;
            break;
        }
    }
//trata e encerra a função se o voo não estiver cadastrado
    if (indiceVoo == -1) {
        cout << "Erro: Impossível remover astronauta. Voo " << codigo << " não cadastrado." << endl;
        return;
    }
//trata e encerra a função se o voo não estiver planejado
    Voo &voo = listaVoos[indiceVoo];
    if (voo.estado != "planejado") {
        cout << "Erro: Impossível remover astronauta. Voo " << codigo << " não planejado." << endl;
        return;
    }
//procurando astronauta
    bool encontrado = false;
    int indiceEncontrado = -1;

    for (int i = 0; i < voo.cpfsPassageiros.size(); i++) {
        if (voo.cpfsPassageiros[i] == cpf) {
            encontrado = true;
            indiceEncontrado = i;
            break;
        }
    }
//tratando resultado negativo e removendo astronauta
    if (!encontrado) {
        cout << "Erro:  Impossível remover. Astronauta de CPF n." << cpf << " não está cadastrado neste voo." << endl;
    }
    else {
        voo.cpfsPassageiros.erase(voo.cpfsPassageiros.begin() + indiceEncontrado);
        cout << "Astronauta de CPF n." << cpf << " removido com sucesso do Voo " << codigo << ".\n";
    }   
}

//************** LANÇAMENTO DE VOO  ******************************************************
void lancarVoo(int codigo){
//procurando voo cadastrado
    int indiceVoo = -1;
    for (int i = 0; i < listaVoos.size(); i++){
        if (listaVoos[i].codigo == codigo) {
            indiceVoo = i;
            break;
        }
    }
//tratando resultado negativo de Voo não cadastrado
    if (indiceVoo == -1) {
        cout << "Erro: Voo " << codigo << " não cadastrado." << endl;
        return;    
    }

    Voo &voo = listaVoos[indiceVoo];
//tratando resultado negativo de Voo não planejado ou vazio
    if (voo.estado != "planejado") {
        cout << "Erro: Impossível lançar Voo não planejado. Verifique o status do Voo " << codigo << " no Banco de Dados da Agência." << endl;
    } else if (voo.cpfsPassageiros.size() == 0){
       cout << "Erro: Lista de Passageiros vazia. O Voo " << codigo << " não possui astronautas registrados para voar." << endl;
       return;
    }
//comparando cpfs e verificando status para viajar
        bool todosProntos = true;

        for (int i = 0; i < voo.cpfsPassageiros.size(); i++) {
            string cpfBusca = voo.cpfsPassageiros[i];
            for (int j = 0; j < listaAstronautas.size(); j++) {
                if (listaAstronautas[j].cpf == cpfBusca) {
                    if (!listaAstronautas[j].vivo || !listaAstronautas[j].disponível) {
                        todosProntos = false;
                    }
                }
            }
        }

        if (!todosProntos) {
            cout << "Erro: Astronauta(s) com status incompatível para viagem espacial." << endl;
        } else {
//Mudando estado do voo
            voo.estado = "em curso";
//Mudando disponibilidade dos astronautas
            for (int i = 0; i < voo.cpfsPassageiros.size(); i++) {
                string cpfBusca = voo.cpfsPassageiros[i];
                for (int j = 0; j < listaAstronautas.size(); j++) {
                    if (listaAstronautas[j].cpf == cpfBusca) {
                        listaAstronautas[j].disponível = false;
                    }
                }
            }
//confirmação de lançamento do voo
            cout << "Voo " << codigo << " lançado com sucesso!\n";
        }
    }

//************** EXPLOSÃO DE VOO  ********************************************************
void explodirVoo(int codigo){
//procurando voo cadastrado
    int indiceVoo = -1;
    for (int i = 0; i < listaVoos.size(); i++){
        if (listaVoos[i].codigo == codigo) {
            indiceVoo = i;
            break;
        }
    }
//tratando resultado negativo de Voo não cadastrado
    if (indiceVoo == -1) {
        cout << "Erro: Voo " << codigo << " não cadastrado." << endl;
        return;    
    }

    Voo &voo = listaVoos[indiceVoo];
//tratando resultado negativo de Voo que não está em curso
    if (voo.estado != "em curso") {
        cout << "Erro: Voo " << codigo << " não está em curso. Impossível explodir." << endl;
        return;
    } else{
//Mudando estado do voo
        voo.estado = "finalizado com explosao";
//Mudando estados dos astronautas
        for (int i = 0; i < voo.cpfsPassageiros.size(); i++) {
            string cpfBusca = voo.cpfsPassageiros[i];
            for (int j = 0; j < listaAstronautas.size(); j++) {
                if (listaAstronautas[j].cpf == cpfBusca) {
                    listaAstronautas[j].disponível = false;
                    listaAstronautas[j].vivo = false;
                }
            }
        }
//confirmação de explosão do voo
        cout << "Falha Crítica! Ocorreu uma explosão no Voo " << codigo << ". Todos os tripulantes estão mortos.\n";
    }
}

//************** FINALIZAÇÃO BEM SUCEDIDA ************************************************
void finalizarVoo(int codigo){
//procurando voo cadastrado
    int indiceVoo = -1;
    for (int i = 0; i < listaVoos.size(); i++){
        if (listaVoos[i].codigo == codigo) {
            indiceVoo = i;
            break;
        }
    }
//tratando resultado negativo de Voo não cadastrado
    if (indiceVoo == -1) {
        cout << "Erro: Voo " << codigo << " não cadastrado." << endl;
        return;    
    }

    Voo &voo = listaVoos[indiceVoo];
//tratando resultado negativo de Voo não em curso
    if (voo.estado != "em curso") {
        cout << "Erro: Voo " << codigo << " não está em curso. Impossível finalizar." << endl;
        return;
    } else{
//Mudando estado do voo
        voo.estado = "finalizado com sucesso";
// Mudando estados dos astronautas
        for (int i = 0; i < voo.cpfsPassageiros.size(); i++) {
            string cpfBusca = voo.cpfsPassageiros[i];
            for (int j = 0; j < listaAstronautas.size(); j++) {
                if (listaAstronautas[j].cpf == cpfBusca) {
                    listaAstronautas[j].disponível = true;
                }
            }
        }
//confirmação de finalização bem sucedida
        cout << "O Voo " << codigo << " finalizou com sucesso!\n";
    }
}

//************** FUNÇÃO AUXILIAR DA LISTAGEM DE VOOS === IMPRIMIR PASSAGEIROS *************
//loop pra pegar os cpfs na lista de passageiros da categoria do voo e comparar com cpfs da lista de astronautas pra pegar o nome lá e imprimir tudo
void imprimirPassageiros(Voo &voo){
	for (int j = 0; j < voo.cpfsPassageiros.size(); j++) {
        string cpfBusca = voo.cpfsPassageiros[j];
        for (int k = 0; k < listaAstronautas.size(); k++) {
            if (listaAstronautas[k].cpf == cpfBusca) {
                cout << "- " << listaAstronautas[k].nome << " (CPF " << listaAstronautas[k].cpf << ")\n";
            }
        }
    }
}

//************** LISTAGEM DE VOOS ********************************************************
void listarVoos() {
//comentários só no primeiro, pois lógica é a mesma pro resto    
//Voos planejados (impressão da categoria)
    cout << "=================================\n";
    cout << "         Voos Planejados         \n";
    cout << "=================================\n";
//loop pra achar o estado correto
    for (int i = 0; i < listaVoos.size(); i++) {
        if (listaVoos[i].estado == "planejado") { // 
            Voo &voo = listaVoos[i];
//impressão das informações           
            cout << "Código de Voo: " << voo.codigo << "\n";
            cout << "Lista de Passageiros:" << "\n";
            imprimirPassageiros(voo); //Chama função auxiliar de impressão
            cout << "\n";
        }
    }
//Voos em curso    
    cout << "=================================\n";
    cout << "          Voos em Curso          \n";
    cout << "=================================\n";
    for (int i = 0; i < listaVoos.size(); i++) {
        if (listaVoos[i].estado == "em curso") {
            Voo &voo = listaVoos[i];
            
            cout << "Código de Voo: " << voo.codigo << "\n";
            cout << "Lista de Passageiros:" << "\n";
            imprimirPassageiros(voo);
            cout << "\n";
        }
    }
//Voos bem sucedidos
    cout << "=================================\n";
    cout << "   Voos Finalizados com Sucesso  \n";
    cout << "=================================\n";
    for (int i = 0; i < listaVoos.size(); i++) {
        if (listaVoos[i].estado == "finalizado com sucesso") { // 
            Voo &voo = listaVoos[i];
            
            cout << "Código de Voo: " << voo.codigo << "\n";
            cout << "Lista de Passageiros:" << "\n";
            imprimirPassageiros(voo);
            cout << "\n";
        }
    }
//Voos com explosão
    cout << "=================================\n";
    cout << "   Voos Finalizados com Explosão  \n";
    cout << "=================================\n";
    for (int i = 0; i < listaVoos.size(); i++) {
        if (listaVoos[i].estado == "finalizado com explosao") { // 
            Voo &voo = listaVoos[i];
            
            cout << "Código de Voo: " << voo.codigo << "\n";
            cout << "Lista de Passageiros:" << "\n";
            imprimirPassageiros(voo);
            cout << "\n";
        }
    }
}

//************** LISTAGEM DE MORTOS *****************************************************
void listarMortos(){
    cout << "=================================\n";
    cout << "   Lista de Astronautas Mortos   \n";
    cout << "=================================\n";
    for (int i = 0; i < listaAstronautas.size(); i++) {
//verifica status de vida
        if (listaAstronautas[i].vivo == false) { // 
            Astronauta &astronauta = listaAstronautas[i];
//imprime cpf e nome
            cout << "- " << astronauta.nome << "- (CPF " << astronauta.cpf << ")\n";
            cout << "Lista de Voos que participou:\n";
//percorre lista de voos pra verificar status planejado
            for (int j = 0; j < listaVoos.size(); j++) {
                Voo &voo = listaVoos[j];
                if (voo.estado != "planejado") {
                    for (int k = 0; k < voo.cpfsPassageiros.size(); k++) {
                        if (voo.cpfsPassageiros[k] == astronauta.cpf) {
                            cout << voo.codigo << "\n"; //imprime código dos voos que participou
                        }
                    }
                }
            }
        }
    }
}