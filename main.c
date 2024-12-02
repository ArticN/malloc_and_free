#include <stdio.h>
#include "lista_encadeada.h"
#include "memoria.h"

int main() {
  lista_encadeada lst = criar_lista();

  insere_valor(lst, 111);
  mostrar_lista(lst);
  insere_valor(lst, 21);
  mostrar_lista(lst);
  insere_valor(lst, 777);
  mostrar_lista(lst);

  apaga_valor(lst, 21);
  mostrar_lista(lst);

  apaga_lista(lst);
  mostrar_lista(lst);

  return 0;
}
