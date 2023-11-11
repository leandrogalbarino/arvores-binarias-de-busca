#ifndef LISTA_H
#define LISTA_H

#include "curso.h"

struct lista
{
    char nome[50];
    int matricula;
    int ano_ingresso;
    struct lista *prox;
};
typedef struct lista Lista;

Lista* lista_cria_vazia();

Lista *lista_cria_no(char *nome, int matricula, int ano_ingresso);

Lista *lista_ajusta_ponteiros(Lista *l, Lista *novo);

Lista *lista_inserir(Lista *l, char *nome, int matricula, int ano_ingresso);

Lista *lista_remover(Lista *l, int matricula);

void lista_imprime(Lista *l);

void imprime_dados_aluno(Lista *aluno);

#endif