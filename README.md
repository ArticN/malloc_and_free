
# Projeto de Lista Encadeada com Gerenciamento de Memória Personalizado

Este projeto implementa uma lista duplamente encadeada utilizando um gerenciador de memória personalizado que simula o comportamento das funções `malloc` e `free` da linguagem C. 

## Estrutura do Projeto

O projeto é composto pelos seguintes arquivos:

- **`main.c`**: Contém a função principal para testar as funcionalidades da lista encadeada.
- **`lista_encadeada.c`**: Implementa as operações de gerenciamento e manipulação da lista encadeada.
- **`lista_encadeada.h`**: Declarações das funções e tipos utilizados na lista encadeada.
- **`memoria.c`**: Implementa um gerenciador de memória personalizado.
- **`memoria.h`**: Declarações das funções e tipos relacionados ao gerenciamento de memória.

## Funcionamento do Gerenciador de Memória

O gerenciamento de memória neste projeto substitui o uso de `malloc` e `free` por funções customizadas:

- **`memoria_alocar`**: Simula a alocação de memória. A memória é gerenciada em um vetor global de bytes (`MEMORIA`), onde os blocos disponíveis são marcados e atribuídos conforme necessário.
- **`memoria_liberar`**: Libera a memória alocada. Os bytes utilizados são marcados como disponíveis novamente.
- **`espaco_disponivel`**: Verifica se um intervalo de memória no vetor global está livre para alocação.

### Limitações do Gerenciador de Memória
1. **Tamanho Fixo**: O vetor global de memória tem um tamanho máximo predefinido (`8192` bytes).
2. **Simples Marcação**: A memória alocada é precedida por um byte que indica o tamanho do bloco, permitindo rastrear e liberar a memória alocada.

## Operações Disponíveis na Lista Encadeada

1. **Criação da Lista**: `nova_lista()` inicializa uma lista encadeada vazia.
2. **Inserção de Valores**: `lista_inserir(lista*, int)` adiciona um novo valor ao final da lista.
3. **Exibição da Lista**: `lista_exibir(lista*)` exibe todos os valores presentes na lista.
4. **Remoção de Valores**: `lista_remover(lista*, int)` remove o primeiro nó com o valor especificado.
5. **Busca de Valores**: `lista_buscar(lista*, int)` retorna um ponteiro para o nó que contém o valor desejado.
6. **Limpeza da Lista**: `lista_apagar(lista*)` libera todos os nós e a estrutura da lista.

## Compilação e Execução

Para compilar o projeto, utilize o comando:

```bash
gcc -o  <nome> main.c lista_encadeada.c memoria.c
```

Após compilar, execute o programa:

```bash
./<nome> 
```

## Exemplos de Uso

A seguir, um exemplo do que acontece no programa principal:

1. Uma lista encadeada é criada.
2. Valores são inseridos (`10`, `20`, `30`).
3. A lista é exibida.
4. Um valor específico (`20`) é removido.
5. A lista é apagada.

## Contribuições

Se desejar contribuir ou sugerir melhorias, sinta-se à vontade para abrir uma *issue* ou enviar um *pull request*.

---

### Contato

Se precisar de ajuda ou tiver dúvidas, entre em contato! 🚀