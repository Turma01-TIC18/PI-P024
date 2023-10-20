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
        string meio_de_transporte;

        Deslocamento(string _nome, string _descricao, string _meio_de_transporte)
            : Evento(_nome, _descricao) {
                meio_de_transporte = _meio_de_transporte;
            } 
    
};

class Pernoite : public Evento {
    public:
        string hotel;
        string data_checkin;
        string data_checkout;

        Pernoite(string _nome, string _descricao, string _hotel, string _data_checkin, string _data_checkout)
            : Evento(_nome, _descricao) {
                hotel = _hotel;
                data_checkin = _data_checkin;
                data_checkout = _data_checkout;
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
        vector<Reserva> reservas; 
        vector<Dependente*> dependentes; 

        Cliente(string _nome, string _cpf) {
            nome = _nome;
            cpf = _cpf;
        }

        void adicionarDependente(Dependente* _dependente) {
            dependentes.push_back(_dependente);
        }

        void fazerReserva(Pacote* _pacote, string _data) {
            Reserva reserva(this, _pacote, _data);
            reservas.push_back(reserva);
        }

};



/*
    Foi criada uma classe reservas para conseguir facilitar a busca por clientes e pacotes associados aos mesmos(0..n). Cada pacote deverá ter um vector de eventos (agregação)
    O cliente poderá ter dependentes(composição) através de acicionarDependetes. As classes roteiro, deslocamento e pernoite herdam a classe evento.
*/