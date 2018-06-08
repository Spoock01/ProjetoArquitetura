#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MensagemErro.h"
#define MEMORIA "memoria.txt"
#define NUM_LINHAS 50
#define TAMANHO_INSTRUCAO 50
#define TAMANHO_MEMORIA 100

char arrayPrograma[NUM_LINHAS][TAMANHO_INSTRUCAO];
int arrayMemoria[TAMANHO_MEMORIA];
int sizeArrayMemoria, sizeArrayPrograma;
int indexCacheInsertion = 0;

int isValid(FILE *memoria, FILE *programa){

    /**
        VERIFICANDO SE OS ARQUIVOS SAO VALIDOS.
        RETORNA 1 CASO NENHUM DOS PONTEIROS SEJA NULL.
    */
    return (memoria == NULL || programa  == NULL) ? 0 : 1;

}

int lePrograma(FILE *programa){

        char string[TAMANHO_INSTRUCAO];     // ARRAY AUXILIAR
        int i = 0;

        while(!feof(programa)){

            fgets(string, sizeof(string), programa);
            if(strcmp(string, ""))
                strcpy(arrayPrograma[i++], string); // COPIANDO STRING DO ARQUIVO PARA ARRAY

        }

        return i;
}

int leMemoria(FILE *memoria){

    int posicao = 0;
    char string[TAMANHO_INSTRUCAO];

    // LENDO ARQUIVO DE MEMORIA

    while(!feof(memoria)){

        fgets(string, sizeof(string), memoria);
        arrayMemoria[posicao++] = (int) atoi(string);

    }

    return posicao; // RETORNANDO TAMANHO DO ARRAY DE MEMORIA

}

int getPosicaoMemoria(int posicao, int *ciclos, int *miss, tCache *cache, int *hit){

    /*
        RETORNA O CONTEUDO DA POSICAO DO ARRAY DE MEMORIA
    */
    *ciclos = *ciclos + 1;

    /** =======  BUSCA DE OPERANDO EM CACHE ========= */

    int i;

    for(i = 0; i < cache->size; i++){

        if(cache->myCache[i].tag == CACHE_OPERAND && cache->myCache[i].posMemoria == posicao){
            *hit = *hit + 1;
            return cache->myCache[i].valMemoria;// Cache Hit
        }

    }

    /* Cache Miss */
    *miss = *miss + 1;

    cache->myCache[indexCacheInsertion].tag = CACHE_OPERAND;
    cache->myCache[indexCacheInsertion].posMemoria = posicao;
    cache->myCache[indexCacheInsertion].valMemoria = arrayMemoria[posicao];
    cache->myCache[indexCacheInsertion].instrucao = "";

    indexCacheInsertion = ((indexCacheInsertion + 1) % cache->size);

    /*  A operacao acima simula a insercao em cache
        utilizando a ideia do algoritmo FIFO, ou seja,
        a primeira posicao de cache ocupada sera a primeira
        a ser removida caso a cache fique cheia.
    */


    /** =======  FIM DA BUSCA DE OPERANDO EM CACHE   */

    return arrayMemoria[posicao];

}

void setPosicaoMemoria(int posicao, int valor){
    arrayMemoria[posicao] = valor;
}

int getSizeMemoria(){

    /**
        RETORNA O TAMANHO DA MEMORIA
    */

    return sizeArrayMemoria;
}

int getSizePrograma(){

    /**
        RETORNA A QUANTIDADE DE INSTRUCOES
        DO ARQUIVO DE PROGRAMA
    */

    return sizeArrayPrograma;
}

char *getInstrucao(int IR, int *ciclos, int *miss, tCache *cache, int *hit){
    *ciclos = *ciclos + 1;

    /** ===ADICIONANDO BUSCA DAS INSTRUCOES EM CACHE====== */
    int i;

    for(i = 0; i < cache->size; i++){
        /*
            Caso a posicao da cache seja instrucao
            e tambem seja a instrucao procurada
        */


        if(cache->myCache[i].tag == CACHE_INSTRUCTION && cache->myCache[i].posMemoria == IR){
            *hit = *hit + 1;

            return cache->myCache[i].instrucao; // Ocorreu Hit
        }

    }

    // Se deu miss
    *miss = *miss + 1;

    cache->myCache[indexCacheInsertion].tag = CACHE_INSTRUCTION;
    cache->myCache[indexCacheInsertion].posMemoria = IR;
    cache->myCache[indexCacheInsertion].valMemoria = -1;
    cache->myCache[indexCacheInsertion].instrucao = arrayPrograma[IR];

    indexCacheInsertion = ((indexCacheInsertion + 1) % cache->size);

    /*  A operacao acima simula a insercao em cache
        utilizando a ideia do algoritmo FIFO, ou seja,
        a primeira posicao de cache ocupada sera a primeira
        a ser removida caso a cache fique cheia.
    */



    /** ===== FIM DA BUSCA NA CACHE ============ */


    return arrayPrograma[IR];
}

void salvarRegistradoresArquivo(){

    //Abrindo para leitura e escrita
    FILE *memoria = fopen(MEMORIA, "w+");
    int i;

    for(i = 0; i < sizeArrayMemoria; i++)
        fprintf(memoria, "%d\n", arrayMemoria[i]);

}

void openFile(FILE *memoria, FILE *programa){

    /**
        isValid    ==> VERIFICA SE OS ARQUIVOS EXISTEM

        leMemoria  ==> VERIFICA SE O ARQUIVO DE MEMORIA
                       EH VALIDO.

        lePrograma ==> VERIFICA SE O ARQUIVO COM O PROGRAMA
                       EM ASSEMBLY EH VALIDO
    */

    if(!isValid(memoria, programa))
        mostraErro(ERRO_ABERTURA_ARQUIVO);

    if((sizeArrayMemoria = leMemoria(memoria)) <= 1)
        mostraErro(ERRO_LEITURA_MEMORIA);

    if((sizeArrayPrograma = lePrograma(programa)) <= 1)
        mostraErro(ERRO_LEITURA_PROGRAMA);
}















