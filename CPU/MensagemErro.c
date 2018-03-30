#include <stdio.h>
#include <stdlib.h>

void mostraErro(int constanteErro){

    switch(constanteErro){

    case 0:
        printf("Ocorreu um erro ao abrir arquivos de memoria e/ou programa!\n"
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

    }

}

