//**************************************************************//
// Engenharia Inform�tica - Algoritmos e Estruturas de Dados    //
// Projeto - Gest�o de Filas de Espero                          //
// Data- 12/06/2015                                             //
// Docente - S�rgio Correia                                     //
// �lvaro Benjamim - 16372                                      //
// Frederico Balc�o - 15307                                     //
// Fifo.c                                                       //
//**************************************************************//


#include "Fifo.h"

/*
 * Descri��o: Cria uma fila de espera
 * RetorNo:
 *    FIFO * fila criada
 */
FIFO *criar_fifo()
{
    FIFO *fifo = (FIFO *)malloc(sizeof(FIFO));
    fifo->primeiro = NULL;
    fifo->ultimo = NULL;
    return fifo;
}

/*
 * Descri��o: verifica se a fila de espera 'fifo' esta vazia
 * Par�metros:
 *    FIFO *fifo fila de espera
 */
int empty_queue(FIFO *fifo)
{
    return fifo->primeiro == NULL;
}

/*
 * Descri��o: Imprime a fila de espera 'fifo'
 * Par�metros:
 *    FIFO *fifo fila de espera
 */

void lista_fifo(FIFO *fifo)
{
    No *lista;

    /* fila vazia */
    if (empty_queue(fifo))
    {
        Cols(7);MolduraCols(1);MolduraEspaco(15); printf("[VAZIA]");MolduraEspaco(19);MolduraCols(1);Lines(1);
        Cols(7); MolduraQID(); MolduraLines(40); MolduraQIE();

        return;
    }

    /* fila n�o est� vazia... */
    /* ... percorrer fifo e imprimir cada n� */
int i=0;
    lista = fifo->primeiro;
    do
    {

          if(i==3){
        Cols(8);system("Pause");
        system("cls");
        Lines(8);
        Cols(7); MolduraQSE(); MolduraLines(40); MolduraQSD();
        i=0;
    }

    if(i<2){
        Print_Item(TipoFifo, lista->dados);

        if(lista->next!=NULL){
            Cols(7); MolduraQED(); MolduraLines(40); MolduraQEE();
        }
        lista = lista->next;

        i++;
    }
    else if(i==2){
        Print_Item(TipoFifo, lista->dados);
        if(lista->next!=NULL){
        Cols(7); MolduraQID(); MolduraLines(40); MolduraQIE();
        }
        lista = lista->next;
        i++;
    }

    }
    while (lista != NULL);
    Cols(7); MolduraQID(); MolduraLines(40); MolduraQIE();

}

/*
 * Descri��o: Adiciona o elemento 'c' No fim da fila 'fifo'
 * Par�metros:
 *    FIFO *fifo fila de espera onde se vai adicionar o elemento
 */
void ADD_FIFO(FIFO *fifo, char balc) //adicionar na fila normal
{
    No *Novo_No;
    Item *item;

    /* cria Novo n� e coloca-o a apontar para NULL porque vamos inserir sempre No fim */
    Novo_No = (No *)malloc(sizeof(No));
    fifo->maior = Novo_No;
    Novo_No->next = NULL;

    if (empty_queue(fifo))
    {
        item = InsereItem(balc, 1);
        Novo_No->dados = item;
        Novo_No->dados->prioridade = Normal;

        /* inser��o na fila com ela vazia */
        fifo->primeiro = Novo_No;
        fifo->ultimo = fifo->primeiro;
    }

    else
    {
        No *lista;
        int senha=0;

        lista = fifo->primeiro;
        do
        {
            if(senha <= lista->dados->Id)
            {
                senha = lista->dados->Id + 1;
            }
            lista = lista->next;
        }
        while (lista != NULL);

        item = InsereItem(balc, senha);
        Novo_No->dados = item;
        Novo_No->dados->prioridade = Normal;

        /* fila n�o est� vazia... */
        fifo->ultimo->next = Novo_No;
        fifo->ultimo = Novo_No;
    }
}

/*
 * Descri��o: Destr�i a fila de espera 'fifo'
 * Par�metros:
 *    FIFO *fifo fila de espera
 */
void read_fifo(FIFO *fifo)
{
    No *prim;

    if (empty_queue(fifo))
    {
       return;
    }

    else
    {
        prim = fifo->primeiro;
        fifo->primeiro = prim->next;
        free(prim);
    }
}

/*
 * Descri��o: Transfere a fila de espera 'fifo_s' para a fila de espera 'fifo_e'
 * Par�metros:
 *    FIFO *fifo_s fila de espera
 *    FIFO *fifo_e fila de espera
 */
void Transferir(FIFO *fifo_s, FIFO *fifo_e, char balcao)
{
    bool priori;
    Item *item1;
    /* fila vazia */
    if (empty_queue(fifo_s))
    {
        return;
    }

    else
    {
        priori=fifo_s->ultimo->dados->prioridade;
    }

    /* fila n�o est� vazia... */
    /* ... percorrer fifo e imprimir cada n� */
    No *Novo_No;

    /* cria Novo n� e coloca-o a apontar para NULL porque vamos inserir sempre No fim */
    Novo_No = (No *)malloc(sizeof(No));
    Novo_No->next = NULL;

    if (empty_queue(fifo_e))
    {
        /* inser��o na fila com ela vazia */
        item1= InsereItem(balcao, 1);
        Novo_No->dados->prioridade = priori;
        Novo_No->dados = item1;

        fifo_e->primeiro = Novo_No;
        fifo_e->ultimo = fifo_e->primeiro;
    }

    else
    {
        No *lista;
        int senha;

        lista = fifo_e->primeiro;
        do
        {
            senha = lista->dados->Id + 1;
            lista = lista->next;
        }
        while (lista != NULL);

        item1= InsereItem(balcao, senha);
        Novo_No->dados->prioridade = priori;
        Novo_No->dados = item1;
        /* fila n�o est� vazia... */
        fifo_e->ultimo->next = Novo_No;
        fifo_e->ultimo = Novo_No;
    }

    //Apaga da primeira FIFO

    read_fifo(fifo_s);
}
/*-----------------------------------------------*/
/* Adiciona na fifo                              */
/*-----------------------------------------------*/
void ADDFIFO1(FIFO *fifo, char balc) //adicionar na fila priorit�ria
{
    No *Novo_No;
    No *aux;
    Novo_No = (No*)malloc(sizeof(No));
    fifo->maior = Novo_No;
    Item *item;

    No *aux1 = NULL;

    if (empty_queue(fifo))
    {
        Novo_No->next = NULL;
        item = InsereItem(balc, 1);
        Novo_No->dados = item;
        Novo_No->dados->prioridade = 1;

        /* inser��o na fila com ela vazia */
        fifo->primeiro = Novo_No;
        fifo->ultimo = fifo->primeiro;
    }

    else
    {
        No *lista;
        int senha=0;

        lista = fifo->primeiro;
        do
        {
            if(senha <= lista->dados->Id)
            {
                senha = lista->dados->Id + 1;
            }
            lista = lista->next;
        }
        while (lista != NULL);

        item = InsereItem(balc, senha);
        Novo_No->dados = item;
        Novo_No->dados->prioridade = 1;
        aux = fifo->primeiro;
        do
        {
            if(aux->dados->prioridade == Prioritaria)
            {
                aux1 = aux;
            }
            aux = aux->next;
        }
        while(aux != NULL);

        No *aux2;
        if(aux1 == NULL)
        {
            aux = fifo->primeiro;

            fifo->primeiro = Novo_No;
            Novo_No->next = aux;
        }

        else
        {
            aux2= aux1->next;
            aux1->next = Novo_No;
            Novo_No->next = aux2;
        }
    }
}
