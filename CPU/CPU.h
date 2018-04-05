#ifndef CPU_H
#define CPU_H

char *fetchInstrucao(int IR);
int decodificaInstrucao(char *instrucao);
void executaInstrucao(char *instrucao, int *PC, int execInstrucao);

#endif // CPU_H
