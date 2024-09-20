#ifndef CURSO_H
#define CURSO_H

struct dados_curso{
    int codigo;
    char nome[100];
    char centro[100];
    struct lista *alunos;

}; typedef struct dados_curso Curso;

struct arv{
    Curso *curso;
    struct arv *esquerda;
    struct arv *direita;
}; typedef struct arv Arv;

Arv *arv_cria_vazia();

Arv *arv_cria_no(Curso *dados);

Arv *abb_insere(Arv *arv, Curso *dados);

Arv *arv_remove_no(Arv *arv, Curso *dados);

Arv *abb_retira(Arv *arv, int codigo);

void imprimir_info_curso(Curso *dados);

void abb_imprime(Arv *arv);

void imprimir_cursos(Arv *arv);

Arv *curso_pertence_arv(Arv *arv, int codigo);

Arv *inserir_curso(Arv *arv);

Arv *remover_curso(Arv *arv);

void imprimir_alunos_curso(Arv *arv);

Arv *inserir_aluno_curso(Arv *arv);

Arv *remover_aluno_curso(Arv *arv);

int dados_alunos_cursos(Arv *arv);

void vinculo_aluno_e_curso(Arv *arv);

int aluno_pertence_a_algum_curso(Arv *arv, int matricula);

#endif
