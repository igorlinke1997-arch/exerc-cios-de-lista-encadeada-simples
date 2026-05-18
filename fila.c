#include <stdio.h>
#include <stdlib.h>

struct No {
    int id;
    struct No *proximo;
};

// Função para inserir após um ID específico
void inserirApos(struct No *head, int id_alvo, int novo_id) {
    struct No *atual = head;

    // Percorre a lista procurando o id_alvo
    while (atual != NULL) {
        if (atual->id == id_alvo) {

            // 1. Criar novo nó
            struct No *novo = (struct No *) malloc(sizeof(struct No));
            novo->id = novo_id;

            // 2. IMPORTANTE: ligar o novo nó ao próximo primeiro
            novo->proximo = atual->proximo;

            // 3. Depois ligar o atual ao novo nó
            atual->proximo = novo;

            return; // já inseriu, pode sair
        }

        atual = atual->proximo;
    }

    printf("ID %d nao encontrado na lista.\n", id_alvo);
}

// Função para imprimir lista
void imprimir(struct No *head) {
    struct No *atual = head;

    printf("Lista: ");

    while (atual != NULL) {
        printf("%d -> ", atual->id);
        atual = atual->proximo;
    }

    printf("NULL\n");
}

int main() {

    // Criando lista inicial: 100 -> 500 -> 700
    struct No *n1 = malloc(sizeof(struct No));
    struct No *n2 = malloc(sizeof(struct No));
    struct No *n3 = malloc(sizeof(struct No));

    n1->id = 100;
    n2->id = 500;
    n3->id = 700;

    n1->proximo = n2;
    n2->proximo = n3;
    n3->proximo = NULL;

    struct No *head = n1;

    printf("Antes:\n");
    imprimir(head);

    // Inserindo paciente após 500
    inserirApos(head, 500, 999);

    printf("\nDepois:\n");
    imprimir(head);

    // Liberando memória
    free(n1);
    free(n2);
    free(n3);
    // (novo nó também poderia ser liberado depois se quiser)

    return 0;
}