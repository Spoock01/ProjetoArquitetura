#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MensagemErro.h"

#define MEMORIA  "memoria.txt"
#define PROGRAMA "programa.txt"
#define NUM_LINHAS 50
#define TAMANHO_INSTRUCAO 10
#define TAMANHO_MEMORIA 100

char arrayPrograma[NUM_LINHAS][TAMANHO_INSTRUCAO];
int arrayMemoria[TAMANHO_MEMORIA];
int sizeArrayMemoria, sizeArrayPrograma;

int isValid(FILE *memoria, FILE *programa){

    // VERIFICANDO SE OS ARQUIVOS SAO VALIDOS
    return (memoria == NULL || programa  == NULL) ? 0 : 1;

    // RETORNA 1 CASO NENHUM DOS PONTEIROS SEHA NULL
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

int posicaoMemoria(int posicao){

    /*
        RETORNA O CONTEUDO DA POSICAO DO ARRAY DE MEMORIA
    */

    return arrayMemoria[posicao];

}

int getSizeMemoria(){
    return sizeArrayMemoria;
}

int getSizePrograma(){
    return sizeArrayPrograma;
}

void openFile(FILE *memoria, FILE *programa){
    if(!isValid(memoria, programa))
        mostraErro(ERRO_ABERTURA_ARQUIVO);

    if((sizeArrayMemoria = leMemoria(memoria)) <= 1)
        mostraErro(ERRO_LEITURA_MEMORIA);

    if((sizeArrayPrograma = lePrograma(programa)) <= 1)
        mostraErro(ERRO_LEITURA_PROGRAMA);
}
