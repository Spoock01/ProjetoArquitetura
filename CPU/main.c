#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MensagemErro.h"
#include "LeitorDeArquivos.h"

int PC, IR, MAR, MBR;

int main()
{

    FILE *memoria = fopen(MEMORIA, "r");
    FILE *programa = fopen(PROGRAMA, "r");

    int arrayMemoria[TAMANHO_MEMORIA], sizeArrayMemoria, sizeArrayPrograma;

    if(!isValid(memoria, programa))
        mostraErro(ERRO_ABERTURA_ARQUIVO);

    if((sizeArrayMemoria = leMemoria(memoria, arrayMemoria)) <= 1)
        mostraErro(ERRO_LEITURA_MEMORIA);

    if((sizeArrayPrograma = lePrograma(programa)) <= 1)
        mostraErro(ERRO_LEITURA_PROGRAMA);







    return 0;
}
