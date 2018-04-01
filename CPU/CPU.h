#ifndef CPU_H
#define CPU_H

#define ADD 1
#define COMP 2
#define COPY 3
#define ESCREVAL 4
#define GETINT 5
#define JE 6
#define JG 7
#define JL 8
#define JUMP 9
#define LOAD 10
#define MOVE 11
#define PRINT 12
#define MUL 13
#define RET 14
#define SUB 15
#define STORE 16

int *getFlag();
char *fetchInstrucao(int IR);
int decodificaInstrucao(char *string);


#endif // CPU_H
