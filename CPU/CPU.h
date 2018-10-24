#ifndef CPU_H
#define CPU_H
#include "LeitorDeArquivos.h"

char *fetchInstrucao(int IR);
void init_program(int size);
void grafPrint();
int decodificaInstrucao(char *instrucao);
void executaInstrucao(char *instrucao, int *PC, int execInstrucao);




#endif // CPU_H
