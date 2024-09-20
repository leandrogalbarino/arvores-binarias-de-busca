#include <stdio.h>
#include <stdlib.h>
#include "curso.h"
#include "lista.h"

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
        if (arv->curso->alunos != NULL)
            liberar_lista(arv->curso->alunos);
        free(arv->curso);
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

        if (temp->curso->alunos != NULL)
            liberar_lista(arv->curso->alunos);
        free(temp->curso);
        free(temp);
    }
    else
    {
        Arv *temp = arv->esquerda;
        while (temp->direita != NULL)
            temp = temp->direita;

        arv->curso = temp->curso;
        temp->curso = dados;

        arv->esquerda = abb_retira(arv->esquerda, dados->codigo);
    }
    return arv;
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
        arv = arv_remove_no(arv, arv->curso);
    return arv;
}

void imprimir_info_curso(Curso *dados)
{
    printf("Nome:%s\n", dados->nome);
    printf("Centro:%s\n", dados->centro);
    printf("Codigo:%d\n\n", dados->codigo);
}

void abb_imprime(Arv *arv)
{
    if (arv != NULL)
    {
        abb_imprime(arv->esquerda);
        imprimir_info_curso(arv->curso);
        abb_imprime(arv->direita);
    }
}

void imprimir_cursos(Arv *arv)
{
    if (arv == NULL)
        printf("Nao existe nenhum curso cadastrado!!\n");
    else
    {
        printf("\tCURSOS\n");
        abb_imprime(arv);
    }
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

Arv *inserir_curso(Arv *arv)
{
    Curso *curso = (Curso *)malloc(sizeof(Curso));
    printf("Digite o nome do curso:\n");
    scanf(" %[^\n]", curso->nome);

    printf("Digite o centro do grupo:\n");
    scanf(" %[^\n]", curso->centro);

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
    if (arv == NULL)
    {
        printf("Nao existe nenhum curso cadastrado!!\n");
        return;
    }
    printf("Digite o codigo do curso que deseja: ");
    scanf("%d", &codigo_curso);

    Arv *curso_achou = curso_pertence_arv(arv, codigo_curso);

    if (curso_achou != NULL)
    {
        printf("Alunos matriculados no curso %s:\n", curso_achou->curso->nome);
        lista_imprime(curso_achou->curso->alunos);
    }
    else
    {
        printf("Curso nao encontrado.\n");
    }
}

int aluno_pertence_a_algum_curso(Arv *arv, int matricula)
{
    int pertence = 0;
    if (arv == NULL)
        return 0;
    if (arv->curso->alunos != NULL)
        if (aluno_pertence(arv->curso->alunos, matricula) != NULL)
            pertence = 1;

    return pertence || aluno_pertence_a_algum_curso(arv->esquerda, matricula) || aluno_pertence_a_algum_curso(arv->direita, matricula);
}

Arv *inserir_aluno_curso(Arv *arv)
{
    int codigo;
    int matricula;
    if (arv == NULL)
    {
        printf("Nao existem cursos, nao foi possivel inserir aluno!!\n");
        return arv;
    }
    printf("Digite o codigo do curso que deseja inserir o aluno:");
    scanf("%d", &codigo);

    Arv *no_curso = curso_pertence_arv(arv, codigo);
    if (no_curso != NULL)
    {
        printf("Digite o numero da matricula do aluno: ");
        scanf("%d", &matricula);
        if (!aluno_pertence_a_algum_curso(arv, matricula))
            no_curso->curso->alunos = inserir_alunos(no_curso->curso->alunos, matricula);
        else
            printf("Aluno ja matriculado em um curso!!\n");
    }
    else
        printf("Curso nao encontrado!!\n");
    return arv;
}

Arv *remover_aluno_curso(Arv *arv)
{
    int codigo;
    if (arv == NULL)
    {
        printf("Nao existem cursos, nao foi possivel remover alunos!!\n");
        return arv;
    }
    printf("Digite o codigo do curso que deseja remover o aluno:");
    scanf("%d", &codigo);

    Arv *no_curso = curso_pertence_arv(arv, codigo);
    if (no_curso != NULL)
    {
        no_curso->curso->alunos = remover_alunos(no_curso->curso->alunos);
    }
    else
        printf("Curso nao encontrado!!\n");
    return arv;
}

int dados_alunos_cursos(Arv *arv)
{
    int retornar = 0;
    if (arv != NULL)
    {
        retornar += dados_alunos_cursos(arv->esquerda);

        char *nome_curso = arv->curso->nome;
        char *centro_curso = arv->curso->centro;
        if (arv->curso->alunos != NULL)
        {
            imprimir(arv->curso->alunos, nome_curso, centro_curso);
            retornar++;
        }
        retornar += dados_alunos_cursos(arv->direita);
    }
    return retornar;
}

void vinculo_aluno_e_curso(Arv *arv)
{
    if (arv == NULL)
    {
        printf("Nao ha nenhum vinculo entre alunos e cursos.\n");
    }
    else
    {
        printf("Dados de Vinculos entre Alunos e Cursos:\n\n");
        if (!dados_alunos_cursos(arv))
            printf("Nao existe nenhum vinculo entre Aluno e Curso!!\n");
    }
}