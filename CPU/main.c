#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MensagemErro.h"
#include "LeitorDeArquivos.h"
#include "CPU.h"

int PC, IR = 0, MAR, MBR;

int main()
{

    FILE *memoria = fopen(MEMORIA, "r");
    FILE *programa = fopen(PROGRAMA, "r");

    openFile(memoria, programa);

    return 0;
}
