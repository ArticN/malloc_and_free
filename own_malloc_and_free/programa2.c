#include <stdio.h>
#include "lista_encadeada.h"
#include "memoria.h"

int main() {
  lista_encadeada lst = criar_lista();

  insere_valor(lst, 123);
  mostrar_lista(lst);
  insere_valor(lst, 321);
  mostrar_lista(lst);
  insere_valor(lst, 333);
  mostrar_lista(lst);

  apaga_valor(lst, 333);
  mostrar_lista(lst);

  apaga_lista(lst);
  mostrar_lista(lst);

  return 0;
}
