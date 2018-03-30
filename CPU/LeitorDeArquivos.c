#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORIA  "memoria.txt"
#define PROGRAMA "programa.txt"
#define NUM_LINHAS 50
#define TAMANHO_INSTRUCAO 10
#define TAMANHO_MEMORIA 100

char arrayPrograma[NUM_LINHAS][TAMANHO_INSTRUCAO];

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

int leMemoria(FILE *memoria, int *array){

    int posicao = 0;
    char string[TAMANHO_INSTRUCAO];

    // LENDO ARQUIVO DE MEMORIA

    while(!feof(memoria)){

        fgets(string, sizeof(string), memoria);
        array[posicao++] = (int) atoi(string);

    }

    return posicao; // RETORNANDO TAMANHO DO ARRAY DE MEMORIA

}
