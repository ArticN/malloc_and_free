#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

typedef struct nodo_data {
    struct nodo_data* anterior;
    int dado;
    struct nodo_data* proximo;
} nodo;

typedef struct lista_data {
    nodo* inicio;
} lista;

lista* nova_lista();
void lista_apagar(lista* lst);

void lista_inserir(lista* lst, int valor);
void lista_exibir(lista* lst);

nodo* lista_remover(lista* lst, int valor);
void lista_apagar_valor(lista* lst, int valor);

nodo* lista_buscar(lista* lst, int valor);

#endif
