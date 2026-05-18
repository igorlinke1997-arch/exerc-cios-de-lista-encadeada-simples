#include <stdio.h>
#include <stdlib.h>

struct No {
    int cpf;
    struct No *proximo;
};

// Função para remover CPF da lista
void removerCpf(struct No **head, int cpf_alvo) {
    struct No *atual = *head;
    struct No *anterior = NULL;

    // Caso especial: remover o primeiro nó
    if (atual != NULL && atual->cpf == cpf_alvo) {
        *head = atual->proximo;
        free(atual);
        return;
    }

    // Procurando o CPF na lista
    while (atual != NULL && atual->cpf != cpf_alvo) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Se não encontrou
    if (atual == NULL) {
        printf("CPF nao encontrado na lista.\n");
        return;
    }

    // Remoção do nó do meio ou fim
    anterior->proximo = atual->proximo;
    free(atual);
}

// Função para imprimir lista
void imprimir(struct No *head) {
    struct No *atual = head;

    printf("Lista: ");

    while (atual != NULL) {
        printf("%d -> ", atual->cpf);
        atual = atual->proximo;
    }

    printf("NULL\n");
}

int main() {

    // Criando lista: 111 -> 222 -> 333 -> 444
    struct No *n1 = malloc(sizeof(struct No));
    struct No *n2 = malloc(sizeof(struct No));
    struct No *n3 = malloc(sizeof(struct No));
    struct No *n4 = malloc(sizeof(struct No));

    n1->cpf = 111;
    n2->cpf = 222;
    n3->cpf = 333;
    n4->cpf = 444;

    n1->proximo = n2;
    n2->proximo = n3;
    n3->proximo = n4;
    n4->proximo = NULL;

    struct No *head = n1;

    printf("Antes da remocao:\n");
    imprimir(head);

    // Removendo CPF do meio
    removerCpf(&head, 222);

    printf("\nDepois da remocao:\n");
    imprimir(head);

    // Liberando memória restante
    free(n1);
    free(n3);
    free(n4);

    return 0;
}