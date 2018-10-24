// Define Main

#define TWO 2

// Define Leitura do Arquivo

#define ERRO_ABERTURA_ARQUIVO 0
#define ERRO_LEITURA_MEMORIA 1
#define ERRO_LEITURA_PROGRAMA 2
#define ERRO_FUNCAO_ADD 3
#define ERRO_FUNCAO_CMP 4
#define ERRO_SUB_STORE 5
#define ERRO_JUMP_J_EGL 6
#define ERRO_FUNCAO_SUB 7
#define ERRO_FUNCAO_MULT 8
#define ERRO_FUNCAO_MOVE 9
#define ERRO_STORE 10
#define ERRO_FUNCAO_LOAD 11
#define CACHE_INSTRUCTION 0
#define CACHE_OPERAND 1
#define SIZE_REGISTRADORES 10
#define EXIT_PROGRAM 0
#define NUM_LINHAS 200
#define TAMANHO_INSTRUCAO 200
#define TAMANHO_MEMORIA 200

// Define CPU

#define RET 0
#define ADD 1
#define COMP 2
#define ESCREVA 3
#define GETINT 4
#define JE 5
#define JG 6
#define JL 7
#define JUMP 8
#define LOAD 9
#define MOVE 10
#define PRINT 11
#define MUL 12
#define SUB 13
#define STORE 14
#define REGISTRADOR 'r'
#define CHAR_TO_INT(r) (r - '0');
#define SEARCH_SPACE(instrucao) strchr(instrucao, ' ');
#define STRING_TO_INT(r) ((int) atoi(r));
#define MEMORIA "memoria.txt"

