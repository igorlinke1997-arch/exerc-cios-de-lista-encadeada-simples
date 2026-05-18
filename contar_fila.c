#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;              
    struct No *proximo;    
};


int contarFila(struct No *head) {
    int contador = 0;
    struct No *atual = head;

    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }

    return contador;
}

int main() {
    
    struct No *aluno1 = (struct No *) malloc(sizeof(struct No));
    struct No *aluno2 = (struct No *) malloc(sizeof(struct No));
    struct No *aluno3 = (struct No *) malloc(sizeof(struct No));

    
    aluno1->dado = 101;
    aluno2->dado = 102;
    aluno3->dado = 103;


    aluno1->proximo = aluno2;
    aluno2->proximo = aluno3;
    aluno3->proximo = NULL;

    struct No *head = aluno1;

   
    int total = contarFila(head);

    printf("Total de crianças na fila: %d\n", total);

    
    free(aluno1);
    free(aluno2);
    free(aluno3);

    return 0;
}