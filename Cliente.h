//Autor: Thiago Riquelmo Marques Nascimento

#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

using namespace std;

class Cliente{
public:
    unsigned chave;
    string nome;

    Cliente(unsigned novaChave, string novoNome){
        chave = novaChave;
        nome = novoNome;
    }

    Cliente(){
        chave = -1;
        nome = "dummy";
    }

    ~Cliente() {}

};

#endif
