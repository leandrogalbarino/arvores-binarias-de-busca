#ifndef CURSO_H
#define CURSO_H

#include "lista.h"
struct dados_curso{
    int codigo;
    char nome[100];
    char centro[100];
    Lista* alunos;

}; typedef struct dados_curso Curso;


struct arv{
    Curso *curso;
    struct arv* esquerda;
    struct arv* direita;
}; typedef struct arv Arv;


#endif
