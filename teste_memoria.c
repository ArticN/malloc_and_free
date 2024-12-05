#include <stdio.h>
#include "memoria.h"

void testar_alocacao_simples() {
    printf("Teste: Alocação Simples\n");
    byte* bloco = memoria_alocar(10);
    if (bloco != NULL) {
        printf("  Alocação de 10 bytes bem-sucedida.\n");
    } else {
        printf("  Falha na alocação de 10 bytes.\n");
    }
    memoria_liberar(bloco);
    printf("  Memória liberada.\n");
}

void testar_alocacao_sucessiva() {
    printf("\nTeste: Alocação Sucessiva\n");
    byte* bloco1 = memoria_alocar(5);
    byte* bloco2 = memoria_alocar(15);
    byte* bloco3 = memoria_alocar(30);

    if (bloco1 && bloco2 && bloco3) {
        printf("  Alocação de múltiplos blocos bem-sucedida.\n");
    } else {
        printf("  Falha na alocação de múltiplos blocos.\n");
    }

    memoria_liberar(bloco1);
    memoria_liberar(bloco2);
    memoria_liberar(bloco3);
    printf("  Todos os blocos liberados.\n");
}

void testar_liberacao_aleatoria() {
    printf("\nTeste: Liberação Aleatória\n");
    byte* bloco1 = memoria_alocar(10);
    byte* bloco2 = memoria_alocar(20);
    byte* bloco3 = memoria_alocar(30);

    printf("  Liberando bloco do meio.\n");
    memoria_liberar(bloco2);

    byte* bloco4 = memoria_alocar(15);
    if (bloco4 != NULL) {
        printf("  Reutilização de espaço liberado bem-sucedida.\n");
    } else {
        printf("  Falha na reutilização de espaço liberado.\n");
    }

    memoria_liberar(bloco1);
    memoria_liberar(bloco3);
    memoria_liberar(bloco4);
    printf("  Todos os blocos liberados.\n");
}

void testar_espaco_insuficiente() {
    printf("\nTeste: Espaço Insuficiente\n");
    for (int i = 0; i < TAMANHO_MAXIMO / 50; i++) {
        if (memoria_alocar(50) == NULL) {
            printf("  Falha na alocação: espaço insuficiente detectado corretamente.\n");
            break;
        }
    }
}
