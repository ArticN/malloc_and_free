#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

typedef struct no_data {
  struct no_data *prev;
  int value;
  struct no_data *next;
} *no;

typedef struct lista_enc {
  no head;
} *lista_encadeada;

lista_encadeada criar_lista();
void apaga_lista(lista_encadeada);

void insere_valor(lista_encadeada, int);
void mostrar_lista(lista_encadeada);

no remove_valor(lista_encadeada, int);
void apaga_valor(lista_encadeada, int);

no procura_no(lista_encadeada, int);

#endif