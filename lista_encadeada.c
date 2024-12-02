#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"
#include "memoria.h"

lista_encadeada criar_lista() {
  return (lista_encadeada)aloca_mem(sizeof(struct lista_enc));
}

void apaga_lista(lista_encadeada lst) {
  no temp;

  while (lst->head != NULL) {
      temp = lst->head;
      lst->head = lst->head->next;
      libera_mem(temp);
    }

  libera_mem(lst);
}

void insere_valor(lista_encadeada lst, int value) {
no n = (no)aloca_mem(sizeof(struct no_data));
    n->value = value;
    n->next = NULL;

    if (lst->head == NULL) {
        n->prev = NULL;
        lst->head = n;
    } else {
        no temp = lst->head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = n;
        n->prev = temp;
    }
}

void mostrar_lista(lista_encadeada lst) {
    no temp = lst->head;

    printf("lista:");
    while (temp != NULL) {
        if (temp->next == NULL) {
            printf(" %d", temp->value);
        } else {
            printf(" %d <-->", temp->value);
        } 
        temp = temp->next;
    }
    printf("\n");
}

no remove_valor(lista_encadeada lst, int value) {
    no n = procura_no(lst, value);

    if (n == NULL) {
        printf("Valor %d não encontrado\n", value);
        return NULL;
    }

    if (n->prev != NULL) {
        n->prev->next = n->next;
    } else {
        lst->head = n->next;
    }

    if (n->next != NULL) {
        n->next->prev = n->prev;
    }

    return n;   
}

void apaga_valor(lista_encadeada lst, int value) {
 no n = remove_valor(lst, value);

  if (n != NULL) {
      libera_mem(n); 
  }
}

no procura_no(lista_encadeada lst, int value) {
  no current = lst->head;
  while (current != NULL && current->value != value) {
    current = current->next;
  }
  return current;
}
