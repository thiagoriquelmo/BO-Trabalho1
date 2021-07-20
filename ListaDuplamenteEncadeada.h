//Autor: Thiago Riquelmo Marques Nascimento

#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED

#include <iostream>

#include "Nodo.h"

using namespace std;

class ListaDuplamenteEncadeada{
public:
    Nodo *inicio;
    Nodo *fim;
    unsigned tamanho;

    //criar lista vazia
    ListaDuplamenteEncadeada() {
        inicio = NULL;
        fim = NULL;
        tamanho = 0;
    }
    
    ~ListaDuplamenteEncadeada(){

    }

    //inserir nodo no fim
    void insere(const Cliente &cliente){
        Nodo *novoNodo = new Nodo(cliente); 
        Nodo *anteriorNodo = fim;

        if ((inicio == NULL) && (fim == NULL)){
            novoNodo->ante = NULL;
            novoNodo->prox = NULL;
            inicio = novoNodo;
            fim = novoNodo;
            tamanho++;
        }

        else{
            novoNodo->ante = anteriorNodo;
            novoNodo->prox = NULL;
            anteriorNodo->prox = novoNodo;
            fim = novoNodo;
            tamanho++;
        }        
    }

    //inserir nodo na posicao dada
    void inserir_posicao( Cliente cliente, int posicao) {
        Nodo * novoNodoPtr = new Nodo(cliente);//alocando memoria
        Nodo * anteriorPtr = inicio;

        if(posicao == 0) {
            anteriorPtr->ante = novoNodoPtr;
            novoNodoPtr->prox = anteriorPtr;
            inicio = novoNodoPtr;
            tamanho++;
            return;
        }

        if(posicao == tamanho){
            fim->prox = novoNodoPtr;
            novoNodoPtr->ante = fim;
            fim = novoNodoPtr;
            tamanho++;
            return;
        }

        //aqui posicao nao e 0
        for(int i=0; i<posicao-1; i++) {
            anteriorPtr = anteriorPtr->prox;
        }

        novoNodoPtr->prox = anteriorPtr->prox;
        novoNodoPtr->ante = anteriorPtr;
        anteriorPtr->prox->ante = novoNodoPtr;
        anteriorPtr->prox = novoNodoPtr;
        tamanho++;
    }

    Cliente * busca(int valor){
        Nodo * nodoPtr = inicio;
        unsigned acessos = 0;

        while(nodoPtr) {
            acessos++;
            if(nodoPtr->cliente.chave == valor){
                cout<< "O numero de acessos foi de "<< acessos <<"vezes!"<<endl;
                return &(nodoPtr->cliente);
            }
            nodoPtr = nodoPtr->prox;
        }

        cout<< "O numero de acessos foi de "<< acessos <<"vezes!"<<endl;
        return NULL;
    }

    void busca_menor(){
        Nodo * nodoPtr = inicio;
        int acessos = 0, posicao=0;
        Cliente aux;
        aux = nodoPtr->cliente;

        while(nodoPtr){
            acessos++;
            if (nodoPtr->prox){
                if(aux.chave > nodoPtr->prox->cliente.chave){
                    aux = nodoPtr->prox->cliente;
                    posicao = acessos;
                }
            }
                        
            nodoPtr = nodoPtr->prox;
        }
        
        cout<< "\n O menor valor e "<< aux.chave << "!"<<endl;
        cout<< "A posicao deste valor e "<< posicao << "!"<<endl;
        cout<< "O numero de acessos foi de "<< acessos <<"vezes!"<<endl;
    }

    Nodo * findNodo(int pos){
        Nodo * aux = inicio;
        int cont=0;
        while (aux)
        {
            if (pos == cont)
            {
                return aux;
            }
            
            cont++;
            aux = aux->prox;
        }
        
    }

    void swap(Nodo *pos1, Nodo *pos2){
        Cliente aux;
        //trocando os valores de lugar
        aux = pos1->cliente;
        pos1->cliente = pos2->cliente;
        pos2->cliente = aux;
    }
    
    void imprime(){
        Nodo * auxNodoIni = inicio;
        
        cout << endl << "Do inicio ao fim" << endl;

        while(auxNodoIni){
            cout << "<" << auxNodoIni->cliente.chave << "," << auxNodoIni->cliente.nome << "> ";

            auxNodoIni = auxNodoIni->prox;
        }
        
    }

    void imprime_invertido(){
        Nodo * auxNodoFim = fim;

        cout << endl << "Do fim ao inicio" << endl;

        while (auxNodoFim){
            cout << "<" << auxNodoFim->cliente.chave << "," << auxNodoFim->cliente.nome << "> ";

            auxNodoFim = auxNodoFim->ante;
        }

        cout << endl;

    }
    
};

#endif // LISTAENCADEADA_H_INCLUDED

