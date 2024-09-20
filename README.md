# Sistema de Gerenciamento de Cursos e Alunos

Este projeto implementa um sistema básico de gerenciamento de cursos e alunos, utilizando uma árvore para armazenar os cursos e listas para armazenar os alunos em cada curso. O sistema permite inserir e remover cursos, bem como gerenciar os alunos matriculados em cada curso.

## Funcionalidades

O programa oferece as seguintes opções:

1. **Inserir Novo Curso**: Permite adicionar um novo curso ao sistema.
2. **Excluir Curso**: Remove um curso existente do sistema.
3. **Imprimir Árvore de Cursos**: Exibe todos os cursos cadastrados na árvore.
4. **Inserir Aluno em um Curso**: Adiciona um aluno a um curso específico.
5. **Remover Aluno de um Curso**: Remove um aluno de um curso específico.
6. **Imprimir Lista de Alunos Matriculados em um Curso**: Mostra todos os alunos matriculados em um curso selecionado.
7. **Imprimir Dados dos Alunos de Todos os Cursos**: Exibe todos os alunos e suas informações em todos os cursos cadastrados.
8. **Sair**: Encerra o programa.

## Estrutura de Dados Utilizada

### Árvore de Cursos (`Arv`)
- A estrutura de árvore é utilizada para armazenar os cursos cadastrados. Cada nó da árvore representa um curso.

### Lista de Alunos (`Lista`)
- Cada curso possui uma lista encadeada de alunos matriculados, permitindo o gerenciamento eficiente dos alunos.

## Como Usar

### Compilação

Para compilar o código, você precisará do compilador GCC. No terminal, execute o seguinte comando:

```bash
gcc main.c lista.c curso.c -o sistema_cursos -Wall
