//**************************************************************//
// Engenharia Inform�tica - Algoritmos e Estruturas de Dados    //
// Projeto - Gest�o de Filas de Espero                          //
// Data- 12/06/2015                                             //
// Docente - S�rgio Correia                                     //
// �lvaro Benjamim - 16372                                      //
// Frederico Balc�o - 15307                                     //
// Lista.h                                                      //
//**************************************************************//


#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "No.h"
#include "Item.h"
#include "Print.h"

/* Estrutura que representa uma LIFO */
typedef struct
{
    No *primeiro;	                                    /* primeiro n� da lista */
    No *ultimo;		                                    /* �ltimo n� da lista */
} Lista;

void adicionarF(Lista*, Item*);                         /* Adiciona No no Fim da Lista */
Lista *criar_lista();                                   /* Cria a Lista */
void listar(Lista*);                                    /* Imprime a Lista */
int empty_queuelista(           Lista*);                /* Verifica se a Lista esta vazia */
void exch(No *, No *);                                  /* Troca os Nos da Lista */
void apaga_lista(Lista *);                              /* Apaga a Lista */
void Random(Lista *, int);                              /* Insere Aleatoria na Lista um numero de senhas */


Lista *lst;                                             /* Ponteiro para Lista */

#endif // LISTA_H_INCLUDED
