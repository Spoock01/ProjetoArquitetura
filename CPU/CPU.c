#include "LeitorDeArquivos.h"
#include "MensagemErro.h"
#include <string.h>


#define SIZE_REGISTRADORES 10


int registrador[10] = {1,1,0,0,0,0,0,0,0,0};
int reg1, reg2;
int finalFlag = -1;
char *re1, *re2;

void printRegistradores(){

    int i;

    for(i = 0; i < SIZE_REGISTRADORES; i++){
        printf("%d ", registrador[i]);
    }

    printf("\n");

}

int *getFlag(){

    /**
        Flag responsavel por finalizar laço
        de execucao do codigo.
        Se for 0, encerra.
    */

    return &finalFlag;
}

char *fetchInstrucao(int IR){

    return getInstrucao(IR);

}

void funcaoADD(char *instrucao){

    //BUSCANDO PRIMEIRO REGISTRADOR
    re1 = strchr(instrucao,' ');
    re1++;

    /*
        REG1 RECEBERA O VALOR DO REGISTRADOR
        ONDE O RESULTADO DA OPERACAO SERA
        SALVO
    */
    ++re1;
    reg1 = *re1 - '0';

    //BURSCANDO SEGUNDO REGISTRADOR
    //OU ENDERECO DE MEMORIA
    re2 = strchr(instrucao,',');
    re2++;

    if (*re2 == 'r'){   /**CASO SEJAM 2 REGISTRADORES*/

        /*
            PEGANDO VALOR DO REGISTRADOR
            DEPOIS DA LETRA 'R' E CONVERTENDO
            PARA INTEIRO

            EX: R1 ==> (reg1 = 1)
        */

        ++re2;
        reg2 = *re2 - '0';

        /*
            SOMANDO OS VALORES DOS REGISTRADORES E
            ARMAZENANDO O RESULTADO NO REG1
        */

        registrador[reg1] = registrador[reg1] + registrador[reg2];

    }else if(*re2 == 'c'){  /**CASO SEJA CONSTANTE*/

        //REG2 SERA UM INTEIRO COM VALOR CONSTANTE
        ++re2;
        reg2 = *re2 - '0';

        registrador[reg1] = registrador[reg1] + reg2;

    } else if(*re2 - '0' >= 0 && *re2 - '0' <= 9){  /**CASO SEJA UM INTEIRO*/

        reg2 = *re2 - '0';

        registrador[reg1] = registrador[reg1] + getPosicaoMemoria(reg2);

    }else{
        mostraErro(ERRO_FUNCAO_ADD);
    }
}

int decodificaInstrucao(char *instrucao){

    switch(instrucao[0]){

    case 'A':

        funcaoADD(instrucao);
        printRegistradores();
        break;

    }

    return 1;
}
