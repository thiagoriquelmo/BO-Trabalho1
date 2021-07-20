//Autor: Thiago Riquelmo Marques Nascimento

#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include "Cliente.h"

using namespace std;

class Nodo {
public:
    Nodo *prox;
    Nodo *ante;
    Cliente cliente;
    
    Nodo(){
        prox = NULL;
        ante = NULL;
    }
    
    Nodo(const Cliente &novoCliente){
        prox = NULL;
        ante = NULL;
        cliente = novoCliente;
    }
    
    ~Nodo() {}
};
#endif
