#include <stdio.h>
#include "lista_encadeada.h"
#include "teste_memoria.h"
#include "memoria.h"

int main() {
  lista* minha_lista = nova_lista();
  printf("-------------Teste primário-------------\n");

  lista_inserir(minha_lista, 10);
  lista_exibir(minha_lista);
  lista_inserir(minha_lista, 20);
  lista_exibir(minha_lista);
  lista_inserir(minha_lista, 30);
  lista_exibir(minha_lista);

  lista_apagar_valor(minha_lista, 20);
  lista_exibir(minha_lista);

  lista_apagar(minha_lista);

  printf("------------Teste secundário------------\n"); 
  
  testar_alocacao_simples();
  testar_alocacao_sucessiva();
  testar_liberacao_aleatoria();
  testar_espaco_insuficiente();

  return 0;
}
