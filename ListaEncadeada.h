//Autor: Thiago Riquelmo Marques Nascimento

#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED

#include <iostream>

#include "Nodo.h"

using namespace std;

class ListaEncadeada {
public:
    Nodo * inicio;
    unsigned tamanho;
    //criar lista vazia
    ListaEncadeada() { inicio = NULL; tamanho=0;}
    
    ~ListaEncadeada() {

    }

    void insere(Cliente cliente){
        Nodo * novoNodoPtr = new Nodo(cliente);//alocando memoria
        Nodo * aux = inicio;

        if(tamanho == 0){
            inicio = novoNodoPtr;
            tamanho++;
            return;
        }

        while(aux){
            if(aux->prox == NULL){
                aux->prox = novoNodoPtr;
                tamanho++;
                break;
            }
            aux = aux->prox;
        }
        

    }

    //inserir nodo na posicao dada
    void inserir_posicao( Cliente cliente, int posicao) {
        Nodo * novoNodoPtr = new Nodo(cliente);//alocando memoria
        Nodo * anteriorPtr = inicio;

        if(posicao == 0) {
            novoNodoPtr->prox = inicio;
            inicio = novoNodoPtr;
            tamanho++;
            return;
        }

        //aqui posicao nao e 0
        for(int i=0; i<posicao-1; i++) {
            anteriorPtr = anteriorPtr->prox;
        }

        novoNodoPtr->prox = anteriorPtr->prox;
        anteriorPtr->prox = novoNodoPtr;
        tamanho++;
    }

    Cliente * busca(int valor){
        Nodo * nodoPtr = inicio;
        int acessos = 0;

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
        
        cout<< "\nO menor valor e "<< aux.chave << "!"<<endl;
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

    void swap(Nodo * pos1, Nodo *pos2){
        Cliente aux;
        //trocando os valores de lugar
        aux = pos1->cliente;
        pos1->cliente = pos2->cliente;
        pos2->cliente = aux;
    }

    void imprime() const {
        Nodo * nodoPtr = inicio;

        cout << endl << "Do inicio ao fim" << endl;

        while(nodoPtr) {
            cout << "<" << nodoPtr->cliente.chave << "," << nodoPtr->cliente.nome << "> ";
            nodoPtr = nodoPtr->prox;
        }
        cout << endl;
    }

    void imprime_invertido(Nodo * nodoPtr){
        if(nodoPtr == NULL){
            return;
        }
        imprime_invertido(nodoPtr->prox);
        cout << "<" << nodoPtr->cliente.chave << "," << nodoPtr->cliente.nome << "> ";
    }
};

#endif
