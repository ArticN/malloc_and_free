// main.c
#include <stdio.h>
#include "lista_encadeada.h"

int main() {
    Node* head = NULL;

    adicionar_no(&head, 10);
    adicionar_no(&head, 20);
    adicionar_no(&head, 30);
    adicionar_no(&head, 40);

    printf("Lista encadeada: ");
    mostrar(head);
    printf("------------------------\n");
    
    liberar(&head, 20);
    printf("Lista depois de remover o 20: ");
    mostrar(head);
    printf("------------------------\n");
    limpar_lista(&head);

    if (head == NULL) {
        printf("A lista foi limpa e esta vazia.\n");
    }

    return 0;
}
