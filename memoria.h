#ifndef MEMORIA_H
#define MEMORIA_H

#include <stdbool.h>
#define TAMANHO_MAXIMO 8192

typedef unsigned char byte;

byte* memoria_alocar(byte tamanho);
void memoria_liberar(void* endereco);
bool espaco_disponivel(int inicio, int fim);

#endif
