#include <stdio.h>
#include <stdlib.h>
#include "ordvetor.h"

VETORORD * VETORD_create(int n, COMP * compara){
    VETORORD * vetor = malloc(sizeof(VETORORD)); //ponteiro do tipo VETORORD
    vetor -> N = n; 
    vetor -> P = 0; 
    vetor -> elems = malloc(n * sizeof( void *)); //alocando memoria para vetor de elementos do tipo void

    for (int i = 0; i < n; i ++ ){ //alocando como null todas as posicoes do vetor
        vetor -> elems[i] = NULL;
    } 
    vetor -> comparador = compara; //ponteiro aponta para o valor desejado
    return vetor; //retorna um ponteiro com o endereço do vetor criado
}

void VETORD_add(VETORORD * vetor, void * newelem){
    if (vetor -> P < vetor -> N){ //verifica se há espaço para o o elemento ser adicionado
        if (vetor -> P == 0){ //caso não haja elementos no vetor, entao sera atribuida a primeira posicao
            vetor -> elems[0] = newelem;
        }else{

            int i; //variavel de iteracao
            int p = vetor -> P; //variavel da quantidade de elementos
            vetor -> elems[p] = newelem; //adicinando novo elemento
            
            for(i = p; i > 0; i--){ //itera pelas posicoes do vetor

                if(vetor->comparador(vetor->elems[i-1], vetor->elems[i]) == -1){ //se a posição adicionada é menor que a anterior
                    void* aux = vetor->elems[i-1]; //ponteiro auxiliar que guarda o valor da posicao anterior
                    vetor->elems[i-1] = vetor->elems[i]; //posicao atual recebe o valor da posicao anterior
                    vetor->elems[i] = aux; //posicao atual recebe o valor do auxiliar
                }else break;
            }
        }
        vetor -> P++; //aumenta quantidade de elementos
    }
}
void * VETORD_remove(VETORORD * vetor){
    void * lixo = vetor->elems[0]; //ponteiro que aponta para o endereco do valor a ser removido

    for (int i= 0; i < vetor -> P; i ++){ //iterando pelo valor
        vetor -> elems[i] = vetor -> elems[i+1]; //atualizando a posicao do vetor com os valores posteriores ao apagado
    }
    vetor -> P--;
    return lixo; //retorna o ponteiro do valor removido
}
