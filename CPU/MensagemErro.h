#ifndef MensagemErro
#define MensagemErro

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

void mostraErro(int constanteErro);


#endif // MensagemErro
