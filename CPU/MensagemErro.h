#ifndef MensagemErro
#define MensagemErro
#include "ConstantesEMacros.h"

void mostraErro(int constanteErro);

typedef struct cache{
    int tag;
    int posMemoria, valMemoria;
    char *instrucao;
} cacheData;

typedef struct tCache{
    cacheData *myCache;
    int size;
} tCache;

#endif
