# Lista Encadeada em C

Este projeto implementa uma lista encadeada em C, com funcionalidades para criar, manipular e exibir uma lista. O objetivo deste projeto é demonstrar conceitos gestão de memória.

## Índice

- [Lista Encadeada em C](#lista-encadeada-em-c)
  - [Índice](#índice)
  - [Estrutura do Projeto](#estrutura-do-projeto)
  - [Como Compilar e Executar](#como-compilar-e-executar)
  - [Estruturas de Dados](#estruturas-de-dados)
    - [`struct no_data`](#struct-no_data)
    - [`struct lista_enc`](#struct-lista_enc)
  - [Funções Implementadas](#funções-implementadas)
    - [Funções da lista encadeada](#funções-da-lista-encadeada)
    - [Funções de gestão de memória](#funções-de-gestão-de-memória)
  - [Uso](#uso)


## Estrutura do Projeto

O projeto é composto pelos seguintes arquivos:

```
.
├── lista_encadeada.c    // Implementação das funções da lista encadeada.
├── lista_encadeada.h    // Declarações das estruturas e funções da lista encadeada.
├── memoria.c             // Implementação das funções de gestão de memória.
├── memoria.h             // Declarações das funções de gestão de memória.
└── programa.c            // Arquivo principal que demonstra o uso da lista encadeada.
```

## Como Compilar e Executar

Para compilar o projeto, você pode usar o compilador `gcc`. Execute os seguintes comandos no terminal:

```bash
gcc -o <nome_do_exe> programa.c lista_encadeada.c memoria.c
```

Para executar o programa, use:

```bash
./<nome_do_exe>
```

## Estruturas de Dados

O projeto utiliza duas estruturas principais:

### `struct no_data`

Esta estrutura representa um nó da lista encadeada. Ela contém os seguintes campos:

- `struct no_data* prev`: ponteiro para o nó anterior.
- `int value`: valor armazenado no nó.
- `struct no_data* next`: ponteiro para o próximo nó.

### `struct lista_enc`

Esta estrutura representa a lista encadeada em si. Ela contém um único campo:

- `no head`: ponteiro para o primeiro nó da lista.

## Funções Implementadas

### Funções da lista encadeada

- **`lista_encadeada criar_lista()`**: Cria e inicializa uma nova lista encadeada.
- **`void apaga_lista(lista_encadeada lst)`**: Remove todos os nós da lista e libera a memória utilizada.
- **`void insere_valor(lista_encadeada lst, int v)`**: Insere um novo nó contendo um valor inteiro no final da lista.
- **`void mostrar_lista(lista_encadeada lst)`**: Exibe os valores armazenados na lista.
- **`no remove_valor(lista_encadeada lst, int v)`**: Remove um nó com um valor específico da lista.
- **`void apaga_valor(lista_encadeada lst, no n)`**: Remove um nó específico da lista e libera a memória.
- **`no procura_no(lista_encadeada lst, int v)`**: Busca um nó com um valor específico e retorna o nó encontrado.

### Funções de gestão de memória

- **`byte* aloca_mem(byte s)`**: Aloca memória da área global.
- **`void libera_mem(void* addrs)`**: Libera a memória alocada em um endereço específico.
- **`bool ESPACO_VALIDO(int inicio, int fim)`**: Identifica se há espaço livre dado onde começa e onde termina.

## Uso

O programa principal (`programa.c`) demonstra como criar uma lista encadeada, adicionar valores, exibir a lista, remover valores e liberar a memória. Os resultados são exibidos no terminal.

Exemplo de uso:

```c
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
```