#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MensagemErro.h"

#define NUM_LINHAS 50
#define TAMANHO_INSTRUCAO 10
#define TAMANHO_MEMORIA 100

char arrayPrograma[NUM_LINHAS][TAMANHO_INSTRUCAO];
int arrayMemoria[TAMANHO_MEMORIA];
int sizeArrayMemoria, sizeArrayPrograma;

int isValid(FILE *memoria, FILE *programa){

    /**
        VERIFICANDO SE OS ARQUIVOS SAO VALIDOS.
        RETORNA 1 CASO NENHUM DOS PONTEIROS SEHA NULL.s
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

int getPosicaoMemoria(int posicao){

    /**
        RETORNA O CONTEUDO DA POSICAO DO ARRAY DE MEMORIA
    */

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

char *getInstrucao(int IR){

    return arrayPrograma[IR];
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
