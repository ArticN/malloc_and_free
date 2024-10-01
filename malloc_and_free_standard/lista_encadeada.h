// lista_encadeada.h
#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

// Estrutura do nó da lista
typedef struct Node {
    int valor;
    struct Node* prox;
} Node;

Node* criar_no(int value);                    // cria um novo nó
void adicionar_no(Node** head, int value);    // adiciona um nó ao final da lista
void limpar_lista(Node** head);               // limpa a lista toda
void liberar(Node** head, int value);         // dado um valor, procura na lista e libera o espaço
void mostrar(Node* head);                     // imprime os valores da lista

#endif
