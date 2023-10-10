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
    string numDependende, nomeDependente, CPFDependente, dtaNascimentoDependete;

    Cliente *depende_de;

    Dependente (string _numDependende, string _nomeDependente, string _CPFDependente, string _dtaNascimentoDependete, Cliente _depende_de){
        numDependende = _numDependende;
        nomeDependente = _nomeDependente;
        CPFDependente = _CPFDependente;
        dtaNascimentoDependete =_dtaNascimentoDependete;
        depende_de = &_depende_de;

    }
};

class Evento{
    public:    
    //string data, local, tipoEvento, durancaoEvento; 
    virtual double calcularDuracaoEvento() = 0;
    virtual string dataEvento() = 0;
    virtual string localEvento() = 0;
    virtual string tipo_de_evento() = 0;

  
};

class Roteiro : public Evento{
    public:
      


};

class Desclocamento : public Evento{
    public:

};

class Pernoite : public Evento{
    public:
    double valorPernoiote;
    double precoPernoite;
    int numQuarto;

};   
    

class Pacote{
    public:
    string nome;
    vector<Evento*> eventos;
    
    //Método de permissão de cadastro de eventos
    void adicionaEvento(Evento* _evento){
        eventos.push_back(_evento);
    }
    




};



int main (){





return 0;
}