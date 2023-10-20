/*Todas as classes foram separadas de acordo com sua hierarquia e o que foi discutido em aula
Cada uma das classes serão acessadas por métodos a partir do menu iniciar com um switd case
*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Evento {

};

class RoteiroEvento : public Evento { //Roteiro seria uma herança de Enveno.

};

class TempoDeslocamentoEvento : public Evento { //TempoDeslocamento uma herança de Evento.

};

class CustoPernoiteEvento : public Evento { //CustoPernoiteEvento uma herança de Envento. 

};

class PacoteTurismo { //PacoteTurismo é uma agregação de Evento.

};

class Cliente { //Cliente é uma agregação de Evento

};

class Dependente : public Cliente { //Dependente é uma herança de Cliente. 

};

Evento* cadastrarEvento() {
    
}

PacoteTurismo* criarPacote() {
   
}

Cliente* criarCliente() {
    

int main() {

    //Função principal com o switch case de seleção de entrada de informações.

    vector<Evento*> eventos;
    vector<PacoteTurismo*> pacotes;
    vector<Cliente*> clientes;

    int opcao;
    while (true) {
        cout << "Menu:\n";
        cout << "1. Cadastrar evento\n";
        cout << "2. Criar pacote de turismo\n";
        cout << "3. Criar cliente\n";
        cout << "4. Vender pacote a cliente\n";
        cout << "5. Consultar lista de clientes\n";
        cout << "6. Consultar lista de pacotes\n";
        cout << "7. Consultar pacotes contratados por cliente\n";
        cout << "8. Consultar clientes que contrataram um pacote\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                // Implementar cadastros de clientes aqui
                break;

            case 2:
                // Implementar criar pacotes aqui
                break;

            case 3:
                // Implementar adicionar clientes aqui
                break;

            case 4:
                // Implemente a venda de pacotes aqui
                break;

            case 5:
                // Implemente a consulta de clientes aqui
                break;

            case 6:
                // Implemente a consulta de pacotes aqui
                break;

            case 7:
                // Implemente a consulta de pacotes contratados por cliente aqui
                break;

            case 8:
                // Implemente a consulta de clientes que contrataram um pacote aqui
                break;

            case 0:
                return 0;
        }
    }

return 0;
}
