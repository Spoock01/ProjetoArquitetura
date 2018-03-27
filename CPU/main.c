#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORIA  "memoria.txt"
#define PROGRAMA "programa.txt"
#define NUM_LINHAS 50
#define TAMANHO_INSTRUCAO 10
#define TAMANHO_MEMORIA 100



void printArray(char *array, int tamanho){

    int i;

    for(i = 0; i < tamanho; i++){
        printf("%s\n", array[i]);
    }

}

int leMemoria(FILE *memoria, int *array){

    int posicao = 0;
    char string[TAMANHO_INSTRUCAO];


    // LENDO ARQUIVO DE MEMORIA

    while(!feof(memoria)){

        fgets(string, sizeof(string), memoria);
        array[posicao++] = (int) atoi(string);

    }

    return posicao - 1; // RETORNANDO TAMANHO DO ARRAY DE MEMORIA

}


int isValid(FILE *memoria, FILE *programa){

    // VERIFICANDO SE OS ARQUIVOS SAO VALIDOS
    return (memoria == NULL || programa  == NULL) ? 0 : 1;

}

int main()
{

    FILE *memoria = fopen(MEMORIA, "r");
    FILE *programa = fopen(PROGRAMA, "r");

    int arrayMemoria[TAMANHO_MEMORIA], sizeArrayMemoria;
    char arrayPrograma[NUM_LINHAS][TAMANHO_INSTRUCAO];


    if(!isValid(memoria, programa)){

        printf("Ocorreu um erro ao abrir arquivos de memoria e/ou programa!\n"
               "O programa sera encerrado!\n");
        return 0;

    }


    if(sizeArrayMemoria = leMemoria(memoria, arrayMemoria) > 0){

        printf("Ocorreu um erro ao ler o arquivo de memoria\n"
               "O programa sera encerrado!\n");
        return 0;
    }





    return 0;
}
