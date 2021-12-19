#ifndef FILA_H
#define FILA_H

#define MAXTAM 30

typedef struct Aluno
{
    int RA;
    char nome[30];
} Aluno;

typedef struct TFila
{
    Aluno Fila[MAXTAM];
    int inicio, fim;
    int quantidade;
} TFila;

void menu();

// TADS
void TFila_Inicializa(TFila *f);
bool TFila_Vazia(TFila *f);
bool TFila_Cheia(TFila *f);
void TFila_Enfileira(TFila *f, Aluno alu);     // algumas modificações para enfileirar
void TFila_Desenfileira(TFila *f, Aluno *alu); // algumas modificações para desenfileirar
void TFila_Imprime(TFila *f);                  // algumas modificações para imprimir

// FUNCÕES EXTRAS
void NovoAluno(TFila *f, Aluno alu); // adiciona novo aluno na fila

#endif