#include <stdio.h>
#include <stdlib.h>

typedef struct st_linkedList {
    int val;
    struct st_linkedList *prox;
    struct st_linkedList *ant;
} lista;
lista *cauda;

int menu();

int v_vazia(lista *ld) {
    if (ld->prox == NULL) {
        return 1;
    }
    return 0;
}

void iniciarLista(lista *ld) {
    ld->prox == NULL;
}

void inserir_inicio(lista *ld, int val) {
    lista *novoNo = (lista *) malloc(sizeof(lista));
    if (!novoNo) {
        printf("Sem memoria\n");
        exit(1);
    }
    printf("Insira o valor a ser inserido: \n");
    scanf("%d", &val);
    if (v_vazia(ld)) {
        ld->prox = novoNo;
        novoNo->val = val;
        novoNo->prox = NULL;
        novoNo->ant = NULL;
    }else{
        novoNo->prox = ld->prox;
        ld->prox->ant = novoNo;
        ld->prox = novoNo;
        novoNo->ant = NULL;
        novoNo->val = val;
    }
    if(cauda == NULL) {
        cauda = novoNo;
    }
}

void inserir_final(lista *ld, int val) {
    lista *novoNo = (lista *) malloc(sizeof(lista));
    if (!novoNo) {
        printf("Sem memoria\n");
        exit(1);
    }
    printf("Insira o valor a ser inserido: \n");
    scanf("%d", &val);
    novoNo->val = val;
    if (v_vazia(ld)) {
        ld->prox = novoNo;
        novoNo->ant = NULL;
        novoNo->prox = NULL;
    } else {
        lista *aux;
        aux = ld;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novoNo;
        novoNo->ant = aux;
        novoNo->prox = NULL;
    }
    cauda = novoNo;
}

void imprimir(lista *ld) {
    lista *aux;
    aux = ld->prox;
    while (aux != NULL) {
        printf("%d", aux->val);
        aux = aux->prox;
    }
    printf("\n");
    lista *aux2 = cauda;
    while (aux2!= NULL) {
        printf("%d", aux2->val);
        aux2 = aux2->ant;
    }
    printf("\n");
}

int menu() {
    int opt;
    printf("Switch option: \n");
    printf("1. Print list\n");
    printf("2. Insert first\n");
    printf("3. Insert last\n");
    printf("4. Encerrar\n");
    printf("Option: ");
    scanf("%d", &opt);
    return opt;
}

void option(lista *ld, int option) {
    switch (option) {
        case 1:
            imprimir(ld);
            break;
        case 2:
            inserir_inicio(ld, 0);
            break;
        case 3:
            inserir_final(ld, 0);
            break;
        case 4:
            printf("Encerrando...\n");
            exit(0);
        default:
            printf("Invalid option\n");
    }
}


int main() {
    lista *ld = (lista *) malloc(sizeof(lista));
    int opt;
    if (!ld) {
        printf("Sem memoria\n");
        exit(1);
    }
    iniciarLista(ld);
    do {
        opt = menu();
        option(ld, opt);
    } while (opt);
    free(ld);
}
