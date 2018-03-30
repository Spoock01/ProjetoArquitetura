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
int posicaoMemoria(int posicao);


#endif // LEITORDEARQUIVOS
