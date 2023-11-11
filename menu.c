#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void espera_enter()
{
    printf("\nPressione Enter para continuar...");
    while (getchar() != '\n')
        ;
    getchar();
}

void menu_opcao(Lista *alunos, int opcao)
{
    switch (opcao)
    {
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    case 5:
        /* code */
        break;
    case 6:
        /* code */
        break;
    case 7:
        /* code */
        break;
    default:
        break;
    }
}

void menu(Lista *alunos)
{
    int opcao;
    do
    {
        printf("MENU:\n");

        // printf("1. INSERIR NOVO CURSO.\n");
        // printf("2. EXCLUIR CURSO.\n");
        // printf("3. IMPRIMIR ARVORE DE CURSO.\n");
        printf("4. INSERIR ALUNO EM UM CURSO.\n");
        printf("5. REMOVER ALUNO DE UM CURSO.\n");
        printf("6. IMPRIMIR LISTA DE ALUNOS MATRICULADO EM UM CURSO.\n");
        printf("7. IMPRIMIR DADOS DE UM ALUNO.\n");
        printf("8. SAIR.\n");
        do
        {
            printf("POR FAVOR, DIGITE O NUMERO DO QUE DESEJA REALIZAR:");
            scanf("%d", &opcao);
            if (opcao < 1 || opcao > 8)
                printf("POR FAVOR, DIGITE UM NUMERO VALIDO!!\n");

        } while (opcao < 1 || opcao > 8);
        menu_opcao(alunos, opcao);
        esperar_enter();
    } while (opcao != 8);
}

int main()
{
    Lista *alunos = lista_cria_vazia();
    menu(alunos);
}