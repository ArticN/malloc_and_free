#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#define TAMANHO_MEMORIA 8192
#define MAX_NOS (TAMANHO_MEMORIA / sizeof(Node))

typedef struct Node {
    int valor;
    int prox;
} Node;

extern Node pool_memoria[MAX_NOS];
extern int espacos_livres[MAX_NOS];

int alocar_no();
void liberar_no(int indice);
void adicionar_no(int valor);
void remover_no(int valor);
void mostrar_lista();
void limpar_lista();

#endif
