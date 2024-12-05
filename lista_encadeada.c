#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"
#include "memoria.h"

lista* nova_lista() {
    return (lista*)memoria_alocar(sizeof(lista));
}

void lista_apagar(lista* lst) {
    nodo* atual;

    while (lst->inicio != NULL) {
        atual = lst->inicio;
        lst->inicio = lst->inicio->proximo;
        memoria_liberar(atual);
    }

    memoria_liberar(lst);
}

void lista_inserir(lista* lst, int valor) {
    nodo* novo = (nodo*)memoria_alocar(sizeof(nodo));
    novo->dado = valor;
    novo->proximo = NULL;

    if (lst->inicio == NULL) {
        novo->anterior = NULL;
        lst->inicio = novo;
    } else {
        nodo* temp = lst->inicio;

        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }

        temp->proximo = novo;
        novo->anterior = temp;
    }
}

void lista_exibir(lista* lst) {
    nodo* atual = lst->inicio;

    printf("Lista:");
    while (atual != NULL) {
        printf(" %d%s", atual->dado, (atual->proximo ? " <-->" : ""));
        atual = atual->proximo;
    }
    printf("\n");
}

nodo* lista_remover(lista* lst, int valor) {
    nodo* alvo = lista_buscar(lst, valor);

    if (alvo == NULL) {
        printf("Valor %d não encontrado\n", valor);
        return NULL;
    }

    if (alvo->anterior != NULL) {
        alvo->anterior->proximo = alvo->proximo;
    } else {
        lst->inicio = alvo->proximo;
    }

    if (alvo->proximo != NULL) {
        alvo->proximo->anterior = alvo->anterior;
    }

    return alvo;
}

void lista_apagar_valor(lista* lst, int valor) {
    nodo* removido = lista_remover(lst, valor);

    if (removido != NULL) {
        memoria_liberar(removido);
    }
}

nodo* lista_buscar(lista* lst, int valor) {
    nodo* atual = lst->inicio;
    while (atual != NULL && atual->dado != valor) {
        atual = atual->proximo;
    }
    return atual;
}
