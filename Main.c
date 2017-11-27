//**************************************************************//
// Engenharia Inform�tica - Algoritmos e Estruturas de Dados    //
// Projeto - Gest�o de Filas de Espero                          //
// Data- 12/06/2015                                             //
// Docente - S�rgio Correia                                     //
// �lvaro Benjamim - 16372                                      //
// Frederico Balc�o - 15307                                     //
// Main.c                                                       //
//**************************************************************//

#include "Gestor.h"
#include "Fifo.h"
#include "Lista.h"

/*-----------------------------------------------*/
/* Main do programa                              */
/*-----------------------------------------------*/
int main()
{
    system("mode con:cols=80 lines=30");                              //modo da janela de consola do programa definido com 80 colunas por 30 linhas (maior dimens�o de janela)

    /*Cria as FIFO's*/
    FIFOA = criar_fifo();                                             // Cria FIFO para o balcao A
    FIFOB = criar_fifo();                                             // Cria FIFO para o balcao B
    FIFOC = criar_fifo();                                             // Cria FIFO para o balcao C
    FIFOD = criar_fifo();                                             // Cria FIFO para o balcao D
    lst = criar_lista();                                              // Cria Lista com nome lst

    Menu();                                                           //chama o menu de apresenta��o do programa

    Programa();                                                       //chama a fun��o inicial do programa

    empty_queue(FIFOA);                                               //retorna o primeiro n� da fifo a NULL
    empty_queue(FIFOB);                                               //retorna o primeiro n� da fifo a NULL
    empty_queue(FIFOC);                                               //retorna o primeiro n� da fifo a NULL
    empty_queue(FIFOD);                                               //retorna o primeiro n� da fifo a NULL
    apaga_lista(lst);                                                 //apaga a lista criada com nome lst

    return 0;
}
