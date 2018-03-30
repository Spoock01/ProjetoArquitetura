#ifndef LEITORDEARQUIVOS
#define LEITORDEARQUIVOS
#define MEMORIA  "memoria.txt"
#define PROGRAMA "programa.txt"

void openFile(FILE *memoria, FILE *programa);
int isValid(FILE *memoria, FILE *programa);
int leMemoria(FILE *arquivo);
int lePrograma(FILE *arquivo);
int getSizeMemoria();
int getSizePrograma();
int getPosicaoMemoria(int posicao);
int setPosicaoMemoria(int posicao, int valor);


#endif // LEITORDEARQUIVOS
