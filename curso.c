#include <stdio.h>
#include <stdlib.h>
#include "curso.h"
#include "lista.h"

// 1. a inserção e exclusão de nós na árvore de cursos;
// 2. a impressão da árvore de cursos, ordenada pelo código do curso;
Arv *arv_cria_vazia()
{
    return NULL;
}

Arv *arv_cria_no(Curso *dados)
{
    Arv *novo = (Arv *)malloc(sizeof(Arv));
    novo->direita = arv_cria_vazia();
    novo->esquerda = arv_cria_vazia();

    novo->curso = dados;
    novo->curso->alunos = lista_cria_vazia();
    return novo;
}

Arv *abb_insere(Arv *arv, Curso *dados)
{
    if (arv == NULL)
        arv = arv_cria_no(dados);
    else if (dados->codigo < arv->curso->codigo)
        arv->esquerda = abb_insere(arv->esquerda, dados);
    else
        arv->direita = abb_insere(arv->direita, dados);
    return arv;
}

Arv *arv_remove_no(Arv *arv, Curso *dados)
{
    if (arv->esquerda == NULL && arv->direita == NULL)
    {
        free(arv);
        return NULL;
    }

    else if ((arv->esquerda != NULL && arv->direita == NULL) || (arv->direita != NULL && arv->esquerda == NULL))
    {
        Arv *temp = arv;
        if (arv->esquerda != NULL)
            arv = arv->esquerda;
        else
            arv = arv->direita;
        free(temp);
    }

    else
    {
        Arv *temp = arv->esquerda;
        while (temp->direita != NULL)
        {
            temp = temp->direita;
        }

        arv->curso = temp->curso;
        temp->curso = dados;

        arv->esquerda = abb_retira(arv->esquerda, dados->codigo);
    }
}

Arv *abb_retira(Arv *arv, int codigo)
{
    if (arv == NULL)
        return NULL;

    if (codigo < arv->curso->codigo)
        arv->esquerda = abb_retira(arv->esquerda, codigo);
    else if (codigo > arv->curso->codigo)
        arv->direita = abb_retira(arv->direita, codigo);
    else
    {
        arv = arv_remove_no(arv, arv->curso);
    }
    return arv;
}

void imprimir_info_curso(Curso *dados)
{
    printf("Centro:%s\n", dados->centro);
    printf("Nome:%s\n", dados->nome);
    printf("Codigo:%d\n", dados->codigo);

    printf("Alunos:\n");
    lista_imprime(dados->alunos);
}

void abb_imprime(Arv *arv)
{
    if(arv == NULL){

    }
    else
    {
        abb_imprime(arv->direita);
        imprimir_info_curso(arv->curso);
        abb_imprime(arv->esquerda);
    }
}

// printf("3. IMPRIMIR ARVORE DE CURSO.\n");
void imprimir_cursos(Arv *arv)
{
    if (arv == NULL)
        printf("Nao existe nenhum curso cadastrado!!\n");
    else
    {
        printf("CURSOS:");
        abb_imprime(arv);
    }
}

Arv *arv_curso()
{
    int codigo;
    printf("Digite o codigo do curso:");
    scanf("%d", &codigo);
}

Arv *curso_pertence_arv(Arv *arv, int codigo)
{
    if (arv == NULL)
        return arv;
    else if (codigo < arv->curso->codigo)
        return curso_pertence_arv(arv->esquerda, codigo);

    else if (codigo > arv->curso->codigo)
        return curso_pertence_arv(arv->direita, codigo);
    else
        return arv;
}

// printf("1. INSERIR NOVO CURSO.\n");
Arv *inserir_curso(Arv *arv)
{
    Curso *curso = (Curso *)malloc(sizeof(Curso));
    printf("Digite o nome do curso:\n");
    scanf("%s", curso->nome);

    printf("Digite o centro do grupo:\n");
    scanf("%s", curso->centro);

    printf("Digite o codigo do curso:\n");
    scanf("%d", &curso->codigo);

    if (curso_pertence_arv(arv, curso->codigo) != NULL)
    {
        printf("Curso ja existente, nao foi possivel inserir!!\n");
        free(curso);
    }
    else
    {
        arv = abb_insere(arv, curso);
        printf("Curso inserido com sucesso.\n");
    }
    return arv;
}

// printf("2. EXCLUIR CURSO.\n");
Arv *remover_curso(Arv *arv)
{
    int codigo;
    if (arv == NULL)
    {
        printf("Arvore vazia, nao existem cursos para serem removidos!!\n");
        return arv;
    }
    printf("Digite o codigo do curso:");
    scanf("%d", &codigo);
    Arv *no_curso = curso_pertence_arv(arv, codigo);
    if (no_curso != NULL)
    {
        arv = abb_retira(arv, codigo);
        printf("Curso removido com sucesso!!\n");
    }
    else
        printf("Curso nao encontrado!!\n");
    return arv;
}

void imprimir_alunos_curso(Arv *arv)
{
    int codigo_curso;

    printf("Digite o codigo do curso que deseja: ");
    scanf("%d", &codigo_curso);

    Arv *curso_achou = curso_pertence_arv(arv,codigo_curso);

    if(curso_achou != NULL)
    {
        printf("Alunos matriculados no curso %d:\n", curso_achou->curso->nome);
        lista_imprime(curso_achou->curso->alunos);
    }
    else
    {
        printf("Curso nao encontrado.\n");
    }
}