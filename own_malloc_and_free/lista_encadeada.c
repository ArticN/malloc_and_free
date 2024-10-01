#include <stdio.h>
#include "lista_encadeada.h"

Node pool_memoria[MAX_NOS];
int espacos_livres[MAX_NOS];
int head = -1;

int alocar_no() {
    for (int i = 0; i < MAX_NOS; i++) {
        if (espacos_livres[i] == 0) {
            espacos_livres[i] = 1;
            return i;
        }
    }
    return -1;
}

void liberar_no(int indice) {
    if (indice >= 0 && indice < MAX_NOS) {
        espacos_livres[indice] = 0;
    }
}

void adicionar_no(int valor) {
    int indice_novo_no = alocar_no();
    if (indice_novo_no == -1) {
        printf("Erro: Memória insuficiente!\n");
        return;
    }

    pool_memoria[indice_novo_no].valor = valor;
    pool_memoria[indice_novo_no].prox = -1;

    if (head == -1) {
        head = indice_novo_no;
    } else {
        int temp = head;
        while (pool_memoria[temp].prox != -1) {
            temp = pool_memoria[temp].prox;
        }
        pool_memoria[temp].prox = indice_novo_no;
    }
}

void remover_no(int valor) {
    if (head == -1) {
        printf("A lista está vazia.\n");
        return;
    }

    int temp = head;
    int prev = -1;

    if (pool_memoria[temp].valor == valor) {
        head = pool_memoria[temp].prox;
        liberar_no(temp);
        return;
    }

    while (temp != -1 && pool_memoria[temp].valor != valor) {
        prev = temp;
        temp = pool_memoria[temp].prox;
    }

    if (temp == -1) {
        printf("Valor %d não encontrado na lista.\n", valor);
        return;
    }

    pool_memoria[prev].prox = pool_memoria[temp].prox;
    liberar_no(temp);
}

void mostrar_lista() {
    int temp = head;
    while (temp != -1) {
        printf("%d -> ", pool_memoria[temp].valor);
        temp = pool_memoria[temp].prox;
    }
    printf("NULL\n");
}

void limpar_lista() {
    while (head != -1) {
        int temp = head;
        head = pool_memoria[head].prox;
        liberar_no(temp);
    }
}
