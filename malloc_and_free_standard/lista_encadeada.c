// lista_encadeada.c
#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

Node* criar_no(int value) {
    Node* novo_no = (Node*)malloc(sizeof(Node));
    if (novo_no == NULL) {
        perror("Falha ao alocar memória");
        exit(EXIT_FAILURE);
    }
    novo_no->valor = value;
    novo_no->prox = NULL;
    return novo_no;
}

void adicionar_no(Node** head, int value) {
    Node* novo_no = criar_no(value);
    if (*head == NULL) {
        *head = novo_no;
    } else {
        Node* temp = *head;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo_no;
    }
}

void limpar_lista(Node** head) {
    Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->prox;
        free(temp);
    }
}

void liberar(Node** head, int value) {
    if (*head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;

    // Se o valor a ser removido for o primeiro nó
    if (temp != NULL && temp->valor == value) {
        *head = temp->prox;
        free(temp);
        printf("Nó com valor %d removido.\n", value);
        return;
    }

    // Percorre a lista em busca do nó a ser removido
    while (temp != NULL && temp->valor != value) {
        prev = temp;
        temp = temp->prox;
    }

    // Caso o valor não seja encontrado
    if (temp == NULL) {
        printf("Valor %d não encontrado na lista.\n", value);
        return;
    }

    // Remove o nó da lista
    prev->prox = temp->prox;
    free(temp);
    printf("Nó com valor %d removido.\n", value);
}

void mostrar(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->valor);
        temp = temp->prox;
    }
    printf("NULL\n");
}
