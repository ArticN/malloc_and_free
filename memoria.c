#include "memoria.h"
#include <stdio.h>
#include <stdlib.h>

byte MEMORIA[TAMANHO_MAXIMO] = {0};

bool espaco_disponivel(int inicio, int fim) {
    for (int i = inicio; i < fim; i++) {
        if (MEMORIA[i] != 0) {
            return false;
        }
    }
    return true;
}

byte* memoria_alocar(byte tamanho) {
    for (int i = 0; i < TAMANHO_MAXIMO; i++) {
        if (MEMORIA[i] != 0) {
            i += MEMORIA[i];
            continue;
        } else if (!espaco_disponivel(i, i + tamanho)) {
            continue;
        } else {
            MEMORIA[i] = tamanho;
            return &MEMORIA[i + 1];
        }
    }
    return NULL;
}

void memoria_liberar(void* endereco) {
    byte* inicio = (byte*)endereco;

    byte tamanho = inicio[-1];
    inicio[-1] = 0;

    for (int i = 0; i < tamanho; i++) {
        inicio[i] = 0;
    }
}
