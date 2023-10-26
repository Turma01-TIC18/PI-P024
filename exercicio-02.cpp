#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Evento {
    public:
        string nome;
        string descricao;

        Evento(string _nome, string _descricao) {
            nome = _nome;
            descricao = _descricao;
        }
    
};

class Roteiro : public Evento {
    public:
        vector<string> destinos;
        
        Roteiro(string _nome, string _descricao, vector<string> _destinos)
            : Evento(_nome, _descricao) {
                destinos = _destinos;
        }
    
};

class Deslocamento : public Evento {
    public:
        string meioDeTransporte;

        Deslocamento(string _nome, string _descricao, string _meioDeTransporte)
            : Evento(_nome, _descricao) {
                meioDeTransporte = _meioDeTransporte;
            }
        
};

class Pernoite : public Evento {
    public:
        string hotel;
        string dataCheckin;
        string dataCheckout;

        Pernoite(string _nome, string _descricao, string _hotel, string _dataCheckin, string _dataCheckout)
            : Evento(_nome, _descricao) {
                hotel = _hotel;
                dataCheckin = _dataCheckin;
                dataCheckout = _dataCheckout;
            }
        
};

class Dependente {
    public:
        string nome;
        int idade;

        Dependente(string _nome, int _idade) {
            nome = _nome;
            idade = _idade;
        }

};

class Pacote {
    public:
        string nome;
        string descricao;
        vector<Evento*> eventos; 

        Pacote(string _nome, string _descricao) {
            nome = _nome;
            descricao = _descricao;
        }
    
};

class Cliente;

class Reserva {

    public:
        Cliente* cliente;
        Pacote* pacote;
        string data;
        Reserva(Cliente* _cliente, Pacote* _pacote, string _data) {
            cliente = _cliente;
            pacote = _pacote;
            data = _data;
        }
        
};

class Cliente {
    public:
        string nome;
        string cpf;
        vector<Reserva> reservas; // Relacionamento de composição com Reserva
        vector<Dependente*> dependentes; // Relacionamento de agregação
        
        Cliente(string _nome, string _cpf) {
            nome = _nome;
            cpf = _cpf;
        }

        void adicionarDependente(Dependente* _dependente) {
            dependentes.push_back(_dependente);
        }

        void fazerReserva(Pacote* _pacote, string _data) {
            Reserva reserva(this, _pacote,_data);
            reservas.push_back(reserva);
        }

};

class AgenciaViagens {
private:
    vector<Evento*> eventos;
    vector<Pacote*> pacotes;
    vector<Cliente*> clientes;
public:
    void cadastrarEvento(Evento* _evento) {
        eventos.push_back(_evento);
    }

    Pacote* criarPacote(string _nome, string _descricao) {
        Pacote* pacote = new Pacote(_nome, _descricao);
        pacotes.push_back(pacote);
        return pacote;
    }

    Cliente* criarCliente(string _nome, string _cpf) {
        Cliente* cliente = new Cliente(_nome, _cpf);
        clientes.push_back(cliente);
        return cliente;
    }

    Evento* criarEventos(string _nome, string _descricao) {
        Evento* evento = new Evento(_nome, _descricao);
        eventos.push_back(evento);
        return evento;
    }

    void venderPacote(Cliente* _cliente, Pacote* _pacote, string _data) {
        _cliente->fazerReserva(_pacote, _data);
    }

    vector<Cliente*> listarClientes() {
        return clientes;
    }

    vector<Pacote*> listarPacotes() {
        return pacotes;
    }

    vector<Evento*> listarEventos() {
        return eventos;
    }

    vector<Pacote*> pacotesContratadosPorCliente(Cliente* _cliente) {
        vector<Pacote*> contratados;
        for (const Reserva& reserva : _cliente->reservas) {
            contratados.push_back(reserva.pacote);
        }
        return contratados;
    }

    vector<Cliente*> clientesQueContrataramPacote(Pacote* _pacote) {
        vector<Cliente*> contratantes;
        for (Cliente* cliente : clientes) {
            for (const Reserva& reserva : cliente->reservas) {
                if (reserva.pacote == _pacote) {
                    contratantes.push_back(cliente);
                    break;
                }
            }
        }
        return contratantes;
    }

    vector<Reserva> reservasDeCliente(Cliente* _cliente) {
        vector<Reserva> reservasCliente;
        for (const Reserva& reserva : _cliente->reservas) {
            reservasCliente.push_back(reserva);
        }
        return reservasCliente;
    }

};

int main() {

    AgenciaViagens agencia;
 
    agencia.cadastrarEvento(new Roteiro("Roteiro 10", "Descrição do roteiro 10", {"Destino 10", "Destino 20"}));
    agencia.cadastrarEvento(new Deslocamento("Deslocamento 10", "Descrição do deslocamento 10", "Avião"));
    agencia.cadastrarEvento(new Pernoite("Pernoite UM", "Descrição da pernoite UM", "Hotel Paraíso", "2023-10-18", "2023-10-22"));

    
    Pacote* pacote10 = agencia.criarPacote("Pacote 10", "Férias no Caribe");
    pacote10->eventos.push_back(agencia.listarEventos()[0]);

    
    Cliente* cliente10 = agencia.criarCliente("Franklin", "9030064552-20");
    Dependente* dependente1 = new Dependente("Filho 1", 16);
    Dependente* dependente2 = new Dependente("Filho 2", 8);
    cliente10->adicionarDependente(dependente1);
    cliente10->adicionarDependente(dependente2);

    agencia.venderPacote(cliente10, pacote10, "2023-10-18");
    
    cout << "Clientes: " << endl;
    for (Cliente* cliente : agencia.listarClientes()) {
        cout << "Nome: " << cliente->nome << ", CPF: " << cliente->cpf << endl;
        for (Dependente* dependente : cliente->dependentes) {
            cout << "  Dependente: " << dependente->nome << ", Idade: " << dependente->idade << endl;
        }
    }

    cout << "\nPacotes:" << endl;
    for (Pacote* pacote : agencia.listarPacotes()) {
        cout << "Nome: " << pacote->nome << ", Descrição: " << pacote->descricao << endl;
    }

    
    cout << "\nPacotes contratados por cliente1:" << endl;
    for (Pacote* pacote : agencia.pacotesContratadosPorCliente(cliente10)) {
        cout << "Nome: " << pacote->nome << ", Descrição: " << pacote->descricao << endl;
    }

    
    cout << "\nClientes que contrataram pacote1:" << endl;
    for (Cliente* cliente : agencia.clientesQueContrataramPacote(pacote10)) {
        cout << "Nome: " << cliente->nome << ", CPF: " << cliente->cpf << endl;
    }

    
    cout << "\nReservas de cliente1:" << endl;
    for (Reserva reserva : agencia.reservasDeCliente(cliente10)) {
        cout << "Pacote: " << reserva.pacote->nome << ", Data: " << reserva.data << endl;
    }

    cout << " " << endl;
   

    return 0;
}
