//**************************************************************//
// Engenharia Inform�tica - Algoritmos e Estruturas de Dados    //
// Projeto - Gest�o de Filas de Espero                          //
// Data- 12/06/2015                                             //
// Docente - S�rgio Correia                                     //
// �lvaro Benjamim - 16372                                      //
// Frederico Balc�o - 15307                                     //
// Estatistica.h                                                //
//**************************************************************//

#ifndef ESTATISTICAS_H_INCLUDED
#define ESTATISTICAS_H_INCLUDED

#include "Fifo.h"
#include "Lista.h"
#include "Menus.h"
#include <math.h>
#include <time.h>
#include "Print.h"

int NumeroSenhas (No *, char, int,  int);                           /* Conta o numero de senhas */
double TempoSenhas (No*, char, bool,  int);                         /* Conta a diferen�a de tempo das senhas */
void AlertaTempo(Lista *,No *, char, bool );                        /* Informa��o do tempo maximo e minimo*/
void InformacaoUtilizador(FIFO *, Lista *, char, int);              /* Informa��o do utilizador*/
void InformacaoBalcao(FIFO *, Lista *, char );                      /* Informa��o do balcao */
void InformacaoSenhas(Lista *,int);                                 /* Informa��o sobre as senhas na lista */
void Entredatas(Lista *, char );                                    /* Informa��o das senhas entre datas */
void Estatistica();                                                 /* Informa��o estatistica */
void BalcaoEstatisticas();                                          /* Informa��o estatistica do balcao */



#endif // ESTATISTICAS_H_INCLUDED
