//Autor: Thiago Riquelmo Marques Nascimento

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Lista.h"
#include "ListaEncadeada.h"
#include "ListaDuplamenteEncadeada.h"
#include "Cliente.h"

using namespace std ;

int main(){
    srand(time(NULL));
    Lista loe;
    ListaEncadeada loe2;
    ListaDuplamenteEncadeada loe3;
    Cliente clientes[10];
    unsigned quantidade;
    int op, tamanho, intervalo;

    clientes[0].chave = 8;
    clientes[0].nome = "a";
    clientes[1].chave = 1;
    clientes[1].nome = "b";
    clientes[2].chave = 3;
    clientes[2].nome = "c";
    clientes[3].chave = 4;
    clientes[3].nome = "d";
    clientes[4].chave = 3;
    clientes[4].nome = "e";
    clientes[5].chave = 6;
    clientes[5].nome = "f";
    clientes[6].chave = 10;
    clientes[6].nome = "g";
    clientes[7].chave = 8;
    clientes[7].nome = "h";
    clientes[8].chave = 9;
    clientes[8].nome = "i";
    clientes[9].chave = 1;
    clientes[9].nome = "j";

    Cliente c11 (11,"k");
    Cliente c12 (2,"l");
    Cliente c13 (7,"m");


    cout << "\n xxx Lista Estatica xxx " << endl ;
    
    cout << "Numero clientes: " << endl ;
    cin >> quantidade;

    for(unsigned i=0; i<quantidade ; i++){
        loe.insere(clientes[i]);
    }

    loe.imprime();

    loe.inserir_posicao(c11,10);
    loe.inserir_posicao(c12,4);
    loe.inserir_posicao(c13,0);

    loe.imprime();

    loe.swap(3, 4);
    loe.swap(0, 6);
    loe.swap(6, 12);

    loe.imprime();

    loe.busca_menor();
    
    loe.imprime_invertido();


    cout << "\n xxx Lista Encadeada xxx " << endl ;

    cout << "Numero clientes: " << endl ;
    cin >> quantidade;

    for(unsigned i=0; i<quantidade ; i++){
        loe2.insere(clientes[i]);
    }

    loe2.imprime();

    loe2.inserir_posicao(c11,10);
    loe2.inserir_posicao(c12,4);
    loe2.inserir_posicao(c13,0);

    loe2.imprime();

    loe2.swap(loe2.findNodo(3), loe2.findNodo(4));
    loe2.swap(loe2.findNodo(0), loe2.findNodo(6));
    loe2.swap(loe2.findNodo(6), loe2.findNodo(12));

    loe2.imprime();

    loe2.busca_menor();    

    cout << endl << "Do fim ao inicio" << endl;
    loe2.imprime_invertido(loe2.inicio);


    cout << "\n xxx Lista Duplamente Encadeada xxx " << endl ;

    cout << "Numero clientes: " << endl ;
    cin >> quantidade;

    for(unsigned i=0; i<quantidade ; i++){
        loe3.insere(clientes[i]);
    }

    loe3.imprime();

    loe3.inserir_posicao(c11,10);
    loe3.inserir_posicao(c12,4);
    loe3.inserir_posicao(c13,0);

    loe3.imprime();

    loe3.swap(loe3.findNodo(3), loe3.findNodo(4));
    loe3.swap(loe3.findNodo(0), loe3.findNodo(6));
    loe3.swap(loe3.findNodo(6), loe3.findNodo(12));

    loe3.imprime();

    loe3.busca_menor();

    loe3.imprime_invertido();

    
    cout << "\n xxx Lista Aleatoria xxx " << endl ;

    cout << "\n Qual o tipo de lista? 1-Estatica | 2- Encadeada | 3-DuplamenteEncadeada " << endl ;
    cin >> op;

    cout << "\n Qual o tamanho da lista aleatoria? " << endl ;
    cin >> tamanho;

    cout << "\n O intervalo dos numeros vai de 0 até quanto? " << endl ;
    cin >> intervalo;

    Cliente clientesAleatorios[tamanho];
    for(unsigned i=0; i< tamanho; i++){
        clientesAleatorios[i].nome = "rand";
        clientesAleatorios[i].chave = (rand()%intervalo + 1);
    }

    Lista aleatoria;
    ListaEncadeada aleatoria2;
    ListaDuplamenteEncadeada aleatoria3;
    switch (op)
    {
    case 1:

        for(unsigned i=0; i<tamanho ; i++){
            aleatoria.insere(clientesAleatorios[i]);
        }

        aleatoria.imprime();
        aleatoria.busca_menor();
        aleatoria.imprime_invertido();
        break;
    
    case 2:

        for(unsigned i=0; i<tamanho ; i++){
            aleatoria2.insere(clientesAleatorios[i]);
        }

        aleatoria2.imprime();
        aleatoria2.busca_menor();
        cout << endl << "Do fim ao inicio" << endl;
        aleatoria2.imprime_invertido(aleatoria2.inicio);
        break;
    
    case 3:

        for(unsigned i=0; i<tamanho ; i++){
            aleatoria3.insere(clientesAleatorios[i]);
        }

        aleatoria3.imprime();
        aleatoria3.busca_menor();
        aleatoria3.imprime_invertido();
        break;
    
    default:
        break;
    }

    return 0;
}

