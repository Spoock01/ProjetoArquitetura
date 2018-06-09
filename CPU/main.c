#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MensagemErro.h"
#include "LeitorDeArquivos.h"
#include "CPU.h"


int main(){

    int PC, IR, instrucao = 1, i;
    FILE *memoria = fopen(MEMORIA, "r");
    FILE *programa = fopen(PROGRAMA, "r");
    int cacheSize = 1;

    openFile(memoria, programa);

    for(i = 0; i < 10; i++){
        PC = 1;
        IR = 0;
        instrucao = 1;

        init_program(cacheSize);

        while(PC >= 0){

            char *linhaComando = fetchInstrucao(IR);
            PC = IR + 1;
            instrucao = decodificaInstrucao(linhaComando);
            executaInstrucao(linhaComando, &PC, instrucao);
            IR = PC;

        }
        grafPrint();
        cacheSize = cacheSize * 2;

    }
    salvarRegistradoresArquivo();

    return 0;
}
