#include <stdio.h>
#include "lista_encadeada.h"

int main() {

    for (int i = 0; i < MAX_NOS; i++) {
        espacos_livres[i] = 0;
    }

    adicionar_no(10);
    adicionar_no(20);
    adicionar_no(30);
    adicionar_no(40);

    printf("Lista encadeada: ");
    mostrar_lista();
    printf("------------------------\n");

    remover_no(20);
    printf("Lista apos remover o valor 20: \n");
    mostrar_lista();
    printf("------------------------\n");

    limpar_lista();
    printf("Lista apos ser completamente limpa: \n");
    mostrar_lista();

    return 0;
}
