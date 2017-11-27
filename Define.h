// Projeto - Gest�o de Filas de Espero                          //
// Data- 12/06/2015                                             //
// Docente - S�rgio Correia                                     //
// �lvaro Benjamim - 16372                                      //
// Frederico Balc�o - 15307                                     //
// Define.h                                                     //
//**************************************************************//
#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

/*-----------------------------------------------*/
/* Defines usados no programa                    */
/*-----------------------------------------------*/
#define Desiste 0                               //senha desistente
#define SemPrioridade 1                         //senha sem prioridade
#define ComPrioridade 2                         //senha com prioridade
#define Nenhum 3                                //para um Print
#define Maximo 0                                //tempo maximo
#define Minimo 1                                //tempo minimo
#define Insere 'I'                              //insere
#define ERRO 'E'                                //erro das datas iniciais e finais
#define Verifica 'V'                            //verifica as datas inicias e finais
#define INICIAL 0                               //para inicial (data, senha...)
#define FINAL 1                                 //para final (data, senha...)
#define D_ANO 0                                 //para verifica��o das datas
#define D_Mes 1                                 //para verifica��o das datas
#define D_Dia 2                                 //para verifica��o das datas
#define key(A) (A)                              //para ordena��o (usado o algoritmo SelectionSort)
#define minimum(A, B) (A < B) ? A : B           //para ordena��o
#define pq(A) a[l-1+A]                          //para ordena��o
#define Q 2		                                //para ordena��o (cutoff do quicksort e mergesort)
#define Almoco 0                                //para Pausa
#define Domingo 1                               //para Pausa

#endif // DEFINE_H_INCLUDED
