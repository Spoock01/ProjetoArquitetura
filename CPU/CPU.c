#include "LeitorDeArquivos.h"
#include "MensagemErro.h"
#include <string.h>
#include <stdlib.h>
#define SIZE_REGISTRADORES 10
#define EXIT_PROGRAM 0

int registrador[10] = {0,1,2,3,4,5,6,7,8,9};
int reg1, reg2, cmp = -2;
int finalFlag = -1;
char *re1, *re2;

void printRegistradores(){

    int i;

    for(i = 0; i < SIZE_REGISTRADORES; i++){
        printf("%d ", registrador[i]);
    }

    printf("\n");

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

void funcaoCOMP(char *instrucao){

    re1 = strchr(instrucao, ' ');
    re1++;

    re2 = strchr(instrucao, ',');
    re2++;

    /*
        VERIFICANDO SE AMBOS OS PARAMETROS
        SAO REGISTRADORES
    */

    if(*re1 == 'r' && *re2 == 'r'){
        re1++;
        reg1 = *re1 - '0';

        re2++;
        reg2 = *re2 - '0';

        if(registrador[reg1] > registrador[reg2])
            cmp = 1;
        else if(registrador[reg1] == registrador[reg2])
            cmp = 0;
        else
            cmp = -1;
    }else if(*re1 == 'r' && *re2 == 'c'){
        re1++;
        reg1 = *re1 - '0';

        re2++;
        reg2 = *re2 - '0';

        if(registrador[reg1] > reg2)
            cmp = 1;
        else if(registrador[reg1] == reg2)
            cmp = 0;
        else
            cmp = -1;

    }else{
        mostraErro(ERRO_FUNCAO_CMP);
    }

}

void funcaoGetInt(char *instrucao){
    re1 = strchr(instrucao, 'r');
    re1++;
    reg1 = *re1 - '0';

    scanf("%d", &registrador[reg1]);
}

void funcaoPrint(char *instrucao){

    re1 = strchr(instrucao, ' ');
    re1++;

    printf("%s\n", re1);

}

void funcaoSub(char *instrucao){
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

        registrador[reg1] = registrador[reg1] - registrador[reg2];

    }else if(*re2 == 'c'){  /**CASO SEJA CONSTANTE*/

        //REG2 SERA UM INTEIRO COM VALOR CONSTANTE
        ++re2;
        reg2 = *re2 - '0';

        registrador[reg1] = registrador[reg1] - reg2;

    } else if(*re2 - '0' >= 0 && *re2 - '0' <= 9){  /**CASO SEJA UM INTEIRO*/

        reg2 = *re2 - '0';

        registrador[reg1] = registrador[reg1] - getPosicaoMemoria(reg2);

    }else{
        mostraErro(ERRO_FUNCAO_SUB);
    }

    printRegistradores();
}

void funcaoStore(char *instrucao){

}

void funcaoJG(char *instrucao, int *PC){
    re1 = strchr(instrucao, ' ');
    re1++;

    reg1 = (int) atoi(re1);

    *PC = reg1;
}

void funcaoJE(char *instrucao, int *PC){
    re1 = strchr(instrucao, ' ');
    re1++;

    reg1 = (int) atoi(re1);

    *PC = reg1;
}

void funcaoJL(char *instrucao, int *PC){
    re1 = strchr(instrucao, ' ');
    re1++;

    reg1 = (int) atoi(re1);

    *PC = reg1;
}

void funcaoJump(char *instrucao, int *PC){
    re1 = strchr(instrucao, ' ');
    re1++;

    reg1 = (int) atoi(re1);

    *PC = reg1;
}

void funcaoMult(char *instrucao){
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

        registrador[reg1] = registrador[reg1] * registrador[reg2];

    }else if(*re2 == 'c'){  /**CASO SEJA CONSTANTE*/

        //REG2 SERA UM INTEIRO COM VALOR CONSTANTE
        ++re2;
        reg2 = *re2 - '0';

        registrador[reg1] = registrador[reg1] * reg2;

    } else if(*re2 - '0' >= 0 && *re2 - '0' <= 9){  /**CASO SEJA UMA POSICAO DE MEMORIA*/

        reg2 = *re2 - '0';

        registrador[reg1] = registrador[reg1] * getPosicaoMemoria(reg2);

    }else{
        mostraErro(ERRO_FUNCAO_MULT);
    }
}

void funcaoEscreva(char *instrucao){
    re1 = strchr(instrucao, ' ');
    re1 += 2;

    reg1 = (int) atoi(re1);

    printf("%d\n", registrador[reg1]);
}

void funcaoRet(int *PC){
    *PC = EXIT_PROGRAM;
}

void funcaoLoad(char *instrucao){
    re1 = strchr(instrucao, 'r');
    re1++;

    reg1 = *re1 - '0';

    re2 = strchr(instrucao, ',');
    re2++;

    reg2 = (int) atoi(re2);

    registrador[reg1] = getPosicaoMemoria(reg2);

}

int decodificaInstrucao(char *instrucao, int *PC){

    switch(instrucao[0]){

    case 'A':
        funcaoADD(instrucao);
        printRegistradores();
        break;
    case 'C':
        if(instrucao[1] == 'M'){
            funcaoCOMP(instrucao);
        }
        break;
    case 'E':
        funcaoEscreva(instrucao);
        break;
    case 'G':
        funcaoGetInt(instrucao);
        break;
    case 'J':
        if(instrucao[1] == 'G')
            funcaoJG(instrucao, PC);
        else if(instrucao[1] == 'E')
            funcaoJE(instrucao, PC);
        else if(instrucao[1] == 'L')
            funcaoJL(instrucao, PC);
        else if(instrucao[1] == 'U')
            funcaoJump(instrucao, PC);
        else
            mostraErro(ERRO_JUMP_J_EGL);

        break;
    case 'L':
        funcaoLoad(instrucao);
        break;
    case 'P':
        funcaoPrint(instrucao);
        break;
    case 'S':
        if(instrucao[1] == 'U')
            funcaoSub(instrucao);
        else if(instrucao[1] == 'T')
            funcaoStore(instrucao);
        else
            mostraErro(ERRO_SUB_STORE);

        break;

    }

    return 1;
}
