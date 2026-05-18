#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista encadeada
struct No {
    int dado;              // Neste caso, representa o CPF do cidadão
    struct No *proximo;    // Ponteiro para o próximo nó
};

// Função para buscar um CPF na lista
// Retorna 1 se encontrar, ou 0 caso contrário
int buscarCidadao(struct No *head, int cpf_buscado) {
    struct No *atual = head;

    while (atual != NULL) {
        if (atual->dado == cpf_buscado) {
            return 1; // CPF encontrado
        }
        atual = atual->proximo;
    }

    return 0; // CPF não encontrado
}

int main() {
    // Criando 3 nós
    struct No *cidadao1 = (struct No *) malloc(sizeof(struct No));
    struct No *cidadao2 = (struct No *) malloc(sizeof(struct No));
    struct No *cidadao3 = (struct No *) malloc(sizeof(struct No));

    // Atribuindo CPFs fictícios
    cidadao1->dado = 111111111;
    cidadao2->dado = 222222222;
    cidadao3->dado = 333333333;

    // Ligando os nós
    cidadao1->proximo = cidadao2;
    cidadao2->proximo = cidadao3;
    cidadao3->proximo = NULL;

    // Início da lista
    struct No *head = cidadao1;

    // CPF que queremos buscar
    int cpf_buscado = 222222222;

    // Chamando a função
    if (buscarCidadao(head, cpf_buscado)) {
        printf("CPF %d encontrado na lista de aprovados.\n", cpf_buscado);
    } else {
        printf("CPF %d nao encontrado na lista.\n", cpf_buscado);
    }

    // Liberando memória
    free(cidadao1);
    free(cidadao2);
    free(cidadao3);

    return 0;
}