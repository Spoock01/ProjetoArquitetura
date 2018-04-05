#include <stdio.h>
#include <stdlib.h>

void mostraErro(int constanteErro){

    switch(constanteErro){

    case 0:
        printf("Ocorreu um erro ao abrir arquivo(s) de memoria e/ou programa!\n"
               "O programa sera encerrado!\n");
        exit(0);
        break;
    case 1:
        printf("Ocorreu um erro ao ler o arquivo de memoria\n"
               "Verifique se o arquivo possui valores validos.\n"
               "O programa sera encerrado!\n");
        exit(0);
        break;
    case 2:
        printf("Ocorreu um erro ao ler o arquivo de programa\n"
               "Verifique se o arquivo possui um programa valido.\n"
               "O programa sera encerrado!\n");
        exit(0);
        break;
    case 3:
        printf("Erro de sintaxe na funcao ADD!\n"
               "O programa sera encerrado!\n");
        exit(0);
        break;
    case 4:
        printf("Erro de sintaxe na funcao CMP!\n"
               "O programa sera encerrado!\n");
        exit(0);
        break;
    case 5:
        printf("Comando nao reconhecido! Escolha entre SUB OU STORE\n"
               "O programa sera encerrado!\n");
        exit(0);
        break;
    case 6:
        printf("Comando nao reconhecido! Escolha entre JG, JE, JL ou JUMP\n"
               "O programa sera encerrado!\n");
        exit(0);
        break;
    case 7:
        printf("Erro de sintaxe na funcao SUB!\n"
               "O programa sera encerrado!\n");
        exit(0);
        break;
    case 8:
        printf("Erro de sintaxe na funcao MULT!\n"
               "O programa sera encerrado!\n");
        exit(0);
        break;
    case 9:
        printf("Erro de sintaxe na funcao MOVE!\n"
               "O programa sera encerrado!\n");
        exit(0);
        break;
    case 10:
        printf("A posicao de memoria eh invalida! Store nao realizado!\n");
        break;
    case 11:
        printf("Load de posicao invalida da memoria!\n"
               "O programa sera encerrado!\n");
        exit(0);
        break;

    }

}

