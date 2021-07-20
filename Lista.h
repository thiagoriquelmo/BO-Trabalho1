//Autor: Thiago Riquelmo Marques Nascimento

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <iostream>
#include "Cliente.h"

using namespace std;

class Lista{
public:
    Cliente clientes[100];
    unsigned tamanho;

    Lista() {         
        tamanho=0;
    }
    ~Lista() {}

    void insere(Cliente cliente){
        //erro: nao tem mais espaco
        if (tamanho == 100){
            cout << "Sem espaço"<< endl;
            return;
        }

        else{
            clientes[tamanho]=cliente;
            tamanho++;
        }
        
    }

    void inserir_posicao(Cliente cliente, unsigned posicao){
        //erro: nao tem mais espaco
        if (tamanho == 100){
            cout << "Sem espaço"<< endl;
            return;
        }

        else{
            //abre espaco deslocando tudo para a direita
            for (int p = tamanho; p > posicao; p--){
                clientes[p] = clientes[p - 1];
            }
            //atualizando o cliente
            clientes[posicao]=cliente;
            tamanho++;
        }                
    }

    void swap(unsigned pos1, unsigned pos2){
        Cliente aux;
        aux = clientes[pos1];
        clientes[pos1] = clientes[pos2];
        clientes[pos2] = aux;
    }

    int busca(Cliente cliente){
        for(unsigned i=0; i < tamanho; i++){
            if(clientes[i].chave == cliente.chave){
                cout<< "O numero de acessos foi de "<< i <<"vezes!"<<endl;
                return i;
            }
        }
        return -1;
    } 

    void busca_menor(){
        Cliente aux;
        int posicao=0, acessos=0;
        for(unsigned i=0; i < tamanho; i++){
            if(i==0){
                aux = clientes[i];
            }
            else{
                if(clientes[i].chave < aux.chave){
                    aux = clientes[i];
                    posicao = i;
                }
            }
            acessos++;
        }
        cout<< "O menor valor e "<< aux.chave << "!"<<endl;
        cout<< "A posicao deste valor e "<< posicao << "!"<<endl;
        cout<< "O numero de acessos foi de " << acessos << "vezes!"<<endl;
        
    }

    void imprime(){
        cout << endl << "Do inicio ao fim" << endl;
        for(unsigned i = 0; i < tamanho; i++){
            cout<< "<" << clientes[i].chave << " , " << clientes[i].nome << "> ";
        } 
        cout<<"\n";
    }

    void imprime_invertido(){
        cout << endl << "Do fim ao inicio" << endl;
        for(int i = tamanho-1 ; i >=0 ; i--){
            cout<< "<" << clientes[i].chave << " , " << clientes[i].nome << "> ";
        }
        cout<<"\n";
    }
};

#endif
