#include "memoria.h"
#include <stdio.h>
#include <stdlib.h>

ident MEMORIA_GLOBAL[TAMANHO_MAXIMO] = {'\0'};

bool ESPACO_VALIDO(int strt, int end) {
  for (int i = strt; i < end; i++) {
    if (MEMORIA_GLOBAL[i] != '\0') {
      return false;
    }
  }
  return true;
}

ident* aloca_mem(ident size) {
  for (int i = 0; i < TAMANHO_MAXIMO; i++) {
    if (MEMORIA_GLOBAL[i] != '\0') {
      i += MEMORIA_GLOBAL[i];
      continue;
    } else if (!ESPACO_VALIDO(i, i + size)) {
      continue;
    } else {
      MEMORIA_GLOBAL[i] = size;
      return &MEMORIA_GLOBAL[i + 1];
    }
  }
  return NULL;
}

void libera_mem(void* endereco) {
  ident* ident_end = (ident*)endereco;

  ident size = ident_end[-1];
  ident_end[-1] = '\0';

  for (int i = 0; i < size; i++) {
    ident_end[i] = '\0';
  }
}