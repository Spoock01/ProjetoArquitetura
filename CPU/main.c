#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MensagemErro.h"
#include "LeitorDeArquivos.h"
#include "CPU.h"

/*
    Erro funcao SUB com constantes maiores que 9
    e com a falta de constante apos o C
    Mesmos erros com funcao ADD tambem
    Mesmos erros com funcao MULT tambem

    Mudar parametros de decodificação

*/

int PC = 1, IR = 0;

int main()
{

    FILE *memoria = fopen(MEMORIA, "r");
    FILE *programa = fopen(PROGRAMA, "r");

    openFile(memoria, programa);

    return 0;
}
