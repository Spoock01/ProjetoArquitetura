#ifndef LEITORDEARQUIVOS
#define LEITORDEARQUIVOS
#define MEMORIA "memoria.txt"
#define PROGRAMA "programa.txt"
#include <stdio.h>
#include "MensagemErro.h"


void openFile(FILE *memoria, FILE *programa);
int isValid(FILE *memoria, FILE *programa);
int leMemoria(FILE *arquivo);
int lePrograma(FILE *arquivo);
int getSizeMemoria(void);
int getSizePrograma(void);
int getPosicaoMemoria(int posicao, int *ciclos, int *miss, tCache *cache, int *hit);
int setPosicaoMemoria(int posicao, int valor);
char *getInstrucao(int IR, int *ciclos,int *miss, tCache *cache, int *hit);
void salvarRegistradoresArquivo();


#endif
