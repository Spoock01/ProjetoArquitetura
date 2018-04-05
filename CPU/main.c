#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "MensagemErro.h"
#include "LeitorDeArquivos.h"
#include "CPU.h"

int main(){

    int PC = 1, IR = 0, instrucao = 1;
    FILE *memoria = fopen(MEMORIA, "r");
    FILE *programa = fopen(PROGRAMA, "r");

    openFile(memoria, programa);

    while(PC > 0){

        char *linhaComando = fetchInstrucao(IR);
        PC = IR + 1;
        instrucao = decodificaInstrucao(linhaComando);
        executaInstrucao(linhaComando, &PC, instrucao);
        IR = PC;

    }

    return 0;
}
