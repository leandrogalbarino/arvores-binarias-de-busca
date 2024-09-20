#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "curso.h"

void espera_enter()
{
    printf("\nPressione Enter para continuar...");
    while (getchar() != '\n')
        ;
    getchar();
}

void menu_opcao(Arv **cursos, int opcao)
{
    switch (opcao)
    {
    case 1:
        *cursos = inserir_curso(*cursos);
        break;
    case 2:
        *cursos = remover_curso(*cursos);
        break;
    case 3:
        imprimir_cursos(*cursos);
        break;
    case 4:
        *cursos = inserir_aluno_curso(*cursos); 
        break;
    case 5:
        *cursos = remover_aluno_curso(*cursos);
        break;
    case 6:
        imprimir_alunos_curso(*cursos);
        break;
    case 7:
        vinculo_aluno_e_curso(*cursos);
        break;
    default:
        break;
    }
}

void menu(Arv *cursos)
{
    int opcao;
    do
    {
        printf("\tMENU:\n");

        printf("1. INSERIR NOVO CURSO.\n");
        printf("2. EXCLUIR CURSO.\n");
        printf("3. IMPRIMIR ARVORE DE CURSO.\n");
        printf("4. INSERIR ALUNO EM UM CURSO.\n");
        printf("5. REMOVER ALUNO DE UM CURSO.\n");

        printf("6. IMPRIMIR LISTA DE ALUNOS MATRICULADO EM UM CURSO.\n");
        printf("7. IMPRIMIR DADOS DOS ALUNOS DE TODOS OS CURSOS.\n");
        printf("8. SAIR.\n");
        do
        {
            printf("POR FAVOR, DIGITE O NUMERO DO QUE DESEJA REALIZAR: ");
            scanf("%d", &opcao);
            if (opcao < 1 || opcao > 8)
                printf("POR FAVOR, DIGITE UM NUMERO VALIDO!!\n");

        } while (opcao < 1 || opcao > 8);
        menu_opcao(&cursos, opcao);
        espera_enter();
    } while (opcao != 8);
}

int main()
{
    Arv *cursos = arv_cria_vazia();
    menu(cursos);
    
}