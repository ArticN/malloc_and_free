#include <stdio.h>
#include "lista_encadeada.h"
#include "memoria.h"

int main() {
    lista* minha_lista = nova_lista();

    lista_inserir(minha_lista, 10);
    lista_exibir(minha_lista);
    lista_inserir(minha_lista, 20);
    lista_exibir(minha_lista);
    lista_inserir(minha_lista, 30);
    lista_exibir(minha_lista);

    lista_apagar_valor(minha_lista, 20);
    lista_exibir(minha_lista);

    lista_apagar(minha_lista);

    return 0;
}
