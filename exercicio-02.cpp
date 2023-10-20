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
   //implementar
        
};

class Pernoite : public Evento {
   //implementar
        
};

class Dependente {
    //implementar

};

class Pacote {
    //implementar
    
};

class Cliente;

class Reserva {

   //implementar
        
};

class Cliente {
    //implementar

};

class AgenciaViagens {
//implementar

};

int main() {
    //implementar
    //implementar
    //implementar
    
   

    return 0;
}
