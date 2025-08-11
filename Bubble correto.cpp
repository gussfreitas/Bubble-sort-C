#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Jogador {
    char nome[50];
    int matricula;
    char time[50];
    int numeroCamisa;
    struct Jogador* next;
} Jogador;
//funcao
Jogador* createJogador(char nome[], int matricula, char time[], int numeroCamisa) {
    Jogador* novo_jogador = (Jogador*)malloc(sizeof(Jogador));
    strcpy(novo_jogador->nome, nome);
    novo_jogador->matricula = matricula;
    strcpy(novo_jogador->time, time);
    novo_jogador->numeroCamisa = numeroCamisa;
    novo_jogador->next = NULL;
    return novo_jogador;
}
//funcao
void adicionarJogador(Jogador** head_ref) {
    char nome[50];
    int matricula;
    char time[50];
    int numeroCamisa;

    getchar(); // limpa o \n anterior
    printf("Digite o nome do jogador: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    printf("Digite a matricula do jogador: ");
    scanf("%d", &matricula);

    getchar();
    printf("Digite o time do jogador: ");
    fgets(time, sizeof(time), stdin);
    time[strcspn(time, "\n")] = 0;

    printf("Digite o numero da camisa do jogador: ");
    scanf("%d", &numeroCamisa);

    Jogador* novo_jogador = createJogador(nome, matricula, time, numeroCamisa);
    novo_jogador->next = *head_ref;
    *head_ref = novo_jogador;
}
//funcao
void exibirJogadores(Jogador* head) {
    Jogador* temp = head;
    if (temp == NULL) {
        printf("Nenhum jogador cadastrado.\n");
        return;
    }
    while (temp != NULL) {
        printf("\nNome: %s\n", temp->nome);
        printf("Matricula: %d\n", temp->matricula);
        printf("Time: %s\n", temp->time);
        printf("Numero da Camisa: %d\n", temp->numeroCamisa);
        temp = temp->next;
    }
}
// funcao de bubblesort pela matricula do meu codigo
void bubbleSort(Jogador* head) {
    int trocou;
    Jogador *ptr1;
    Jogador *lptr = NULL;

    if (head == NULL)
        return;

    do {
        trocou = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->matricula > ptr1->next->matricula) {
                char tempNome[50], tempTime[50];
                int tempMatricula, tempNumeroCamisa;

                strcpy(tempNome, ptr1->nome);
                tempMatricula = ptr1->matricula;
                strcpy(tempTime, ptr1->time);
                tempNumeroCamisa = ptr1->numeroCamisa;

                strcpy(ptr1->nome, ptr1->next->nome);
                ptr1->matricula = ptr1->next->matricula;
                strcpy(ptr1->time, ptr1->next->time);
                ptr1->numeroCamisa = ptr1->next->numeroCamisa;

                strcpy(ptr1->next->nome, tempNome);
                ptr1->next->matricula = tempMatricula;
                strcpy(ptr1->next->time, tempTime);
                ptr1->next->numeroCamisa = tempNumeroCamisa;

                trocou = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (trocou);
}
//Main menu do meu codigo
int main() {
    Jogador* head = NULL;
    int opcao;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Adicionar jogador\n");
        printf("2. Exibir jogadores\n");
        printf("3. Ordenar por matricula\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarJogador(&head);
                break;
            case 2:
                exibirJogadores(head);
                break;
            case 3:
                bubbleSort(head);
                printf("Lista ordenada por matricula!\n");
                break;
            case 4:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 4);

    // Libera a memória
    Jogador* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
