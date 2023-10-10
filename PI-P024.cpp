#include <iostream>
#include  <vector>

using namespace std;

class Cliente{
    public:
    string nome, CPF, dtaNascimento;

    Cliente (string _nome, string _CPF, string _dtaNascimento){
         nome = _nome;
         CPF = _CPF;
         dtaNascimento = _dtaNascimento;

    }

};

class Dependente{
    public: 
    string numero, nome, CPF, dataNascimento;

    Cliente *depende_de;

    Dependente (int _numero, string _nome, string _CPF, string _dtaNascimento, Cliente _depende_de){
        numero = _numero;
        nome = _nome;
        CPF = _CPF;
        dataNascimento =_dtaNascimento;
        depende_de = &_depende_de;

    }
};

class Evento{
    public:    
    string duracao; 
    //string nome;deslocar para uma das heranças
    //string tipo;deslocar para uma das heranças         
    //string data, local, tipoEvento, durancaoEvento; 
    virtual double calcularDuracaoEvento() = 0;
    virtual string dataEvento() = 0;
    virtual string localEvento() = 0;
    virtual string tipo_de_evento() = 0;
  

  
};

class Roteiro : public Evento{
    public:

};

class Deslocamento : public Evento{
    public:
    string tipo;  
    string trajeto;


};

class Pernoite : public Evento{
    public:
    double valor;
    int numQuarto;    

};   
    

class Pacote{
    public:
    string nome;
    vector<Evento*> eventos;
    
    Pacote (string _nome, string _eventos);
    //Método de permissão de cadastro de eventos
    void adicionaEvento(Evento* _evento){
        eventos.push_back(_evento);
    }

    void listarEventos (Evento* _evento){
        cout << "Eventos de " << nome << endl;

        for (Evento* e: eventos){
            //cout << e-> nome ; to do

        }

    }

};



int main (){
Pacote pct1();




return 0;
}