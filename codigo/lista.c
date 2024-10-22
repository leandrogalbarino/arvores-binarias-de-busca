#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "curso.h"

Lista *lista_cria_vazia()
{
    return NULL;
}

Lista *lista_cria_no(char *nome, int matricula, int ano_ingresso)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->matricula = matricula;
    novo->ano_ingresso = ano_ingresso;
    strcpy(novo->nome, nome);
    novo->prox = NULL;
    return novo;
}

Lista *lista_ajusta_ponteiros(Lista *l, Lista *novo)
{
    Lista *p;
    Lista *ant = NULL;
    if (novo->matricula > l->matricula)
    {
        novo->prox = l;
        return novo;
    }

    for (p = l; p != NULL; p = p->prox)
    {
        if (novo->matricula > p->matricula)
        {
            ant->prox = novo;
            novo->prox = p;
            break;
        }
        ant = p;
    }

    if (p == NULL)
        ant->prox = novo;
    return l;
}

// INSERIDO PARA MANTER A LISTA ORDENADA PELO NÚMERO DA MATRICULA;
Lista *lista_inserir(Lista *l, char *nome, int matricula, int ano_ingresso)
{
    Lista *novo = lista_cria_no(nome, matricula, ano_ingresso);
    if (l == NULL)
    {
        return novo;
    }

    l = lista_ajusta_ponteiros(l, novo);
    return l;
}

Lista *lista_remover(Lista *l, int matricula)
{
    Lista *p;
    Lista *ant = NULL;

    if (l == NULL)
    {
        printf("Nao existe alunos para serem removidos!\n");
        return l;
    }

    if (l->matricula == matricula)
    {
        Lista *temp = l;
        l = l->prox;
        free(temp);
        return l;
    }

    for (p = l; p != NULL; p = p->prox)
    {
        if (p->matricula == matricula)
        {
            ant->prox = p->prox;
            free(p);
            break;
        }
        ant = p;
    }
    return l;
}

void lista_imprime(Lista *l)
{
    Lista *p;

    if (l == NULL)
    {
        printf("Nao existem alunos matriculados no curso!\n\n");
        return;
    }

    for (p = l; p != NULL; p = p->prox)
    {
        printf("Nome:%s\n", p->nome);
        printf("Matricula:%d\n", p->matricula);
        printf("Ano de Ingresso:%d\n\n", p->ano_ingresso);
    }
}

Lista *aluno_pertence(Lista *l, int matricula)
{
    Lista *p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->matricula == matricula)
        {
            return p;
        }
    }
    return p;
}

Lista *inserir_alunos(Lista *l, int matricula)
{
    int ano_ingresso;
    char nome[50];

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", nome);

    printf("Digite o ano de ingresso do aluno: ");
    scanf("%d", &ano_ingresso);

    if (aluno_pertence(l, matricula) != NULL)
        printf("Aluno ja pertence ao Curso!! Nao foi possivel inserido novamente!!\n");

    else
    {
        l = lista_inserir(l, nome, matricula, ano_ingresso);
        printf("Aluno inserido com sucesso.\n");
    }
    return l;
}

Lista *remover_alunos(Lista *l)
{
    int matricula;
    if (l == NULL)
    {
        printf("Nao existem alunos matriculados no curso!!\n");
        return l;
    }
    printf("Digite o numero da matricula do aluno que deseja remover do curso: ");
    scanf("%d", &matricula);
    if (aluno_pertence(l, matricula) != NULL)
    {
        l = lista_remover(l, matricula);
        printf("Aluno com numero da matricula: %d, removido com sucesso!!\n", matricula);
    }
    else
        printf("Aluno nao encontrado!\n");

    return l;
}

void imprimir(Lista *alunos, char *nome_curso, char *centro_curso)
{
    Lista *p;
    for (p = alunos; p != NULL; p = p->prox)
    {
        printf("Numero de Matricula:%d\n", p->matricula);
        printf("Nome do Aluno:%s\n", p->nome);
        printf("Nome do Curso:%s\n", nome_curso);
        printf("Centro do Curso:%s\n\n", centro_curso);
    }
}

void liberar_lista(Lista *l)
{
    Lista *p = l;
    while (p != NULL)
    {
        free(p);
        p = p->prox;
    }
}
