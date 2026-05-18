
#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;
    struct No *proximo;
};

void imprimirObras(struct No *head) {
    struct No *atual = head;

    printf("==== Protocolo de obras ====\n");

    while (atual != NULL) {
        printf("[Protocolo: %d] -> ", atual->dado);
        atual = atual->proximo;
    }

    printf("NULL\n");
}

int main() {
    // Alocação dinâmica
    struct No *obra1 = (struct No *) malloc(sizeof(struct No));
    struct No *obra2 = (struct No *) malloc(sizeof(struct No));
    struct No *obra3 = (struct No *) malloc(sizeof(struct No));

    // Inserindo dados
    obra1->dado = 1045;
    obra2->dado = 2088;
    obra3->dado = 3012;

    // Ligando os nós
    obra1->proximo = obra2;
    obra2->proximo = obra3;
    obra3->proximo = NULL;

    // Início da lista
    struct No *inicio_da_lista = obra1;

    // Impressão
    imprimirObras(inicio_da_lista);

    // Liberação de memória
    free(obra1);
    free(obra2);
    free(obra3);

    return 0;
}
