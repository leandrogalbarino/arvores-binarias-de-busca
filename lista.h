#ifndef LISTA_H
#define LISTA_H

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

void imprimir(Lista *alunos, char *nome_curso, char *centro_curso);

Lista *inserir_alunos(Lista *l, int matricula);

Lista *remover_alunos(Lista *l);

void liberar_lista(Lista* l);

Lista *aluno_pertence(Lista *l, int matricula);

#endif