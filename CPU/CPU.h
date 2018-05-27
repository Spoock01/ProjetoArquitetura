#ifndef CPU_H
#define CPU_H
#include "LeitorDeArquivos.h"

char *fetchInstrucao(int IR);
void initCache();
int decodificaInstrucao(char *instrucao);
void executaInstrucao(char *instrucao, int *PC, int execInstrucao);

#endif // CPU_H
