#ifndef MEMORIA_H
#define MEMORIA_H

#include <stdbool.h>
#define TAMANHO_MAXIMO 8192

typedef unsigned char ident;

ident* aloca_mem(ident size);

void libera_mem(void*);
bool ESPACO_VALIDO(int strt, int end);

#endif
