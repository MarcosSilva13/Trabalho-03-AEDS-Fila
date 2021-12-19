#include <iostream>
#include <windows.h>
#include "Fila.hpp"
#include <time.h>

using namespace std;

void menu()
{
    system("color 0C");
    cout << "MENU DE OPÇÕES\n";
    cout << "1. Novo Aluno na Fila\n";
    cout << "2. Atende Aluno da Fila\n";
    cout << "3. Exibe Fila\n";
    cout << "4. Sair\n";
}

void TFila_Inicializa(TFila *f)
{
    f->inicio = 0;
    f->fim = -1;
    f->quantidade = 0;
}

bool TFila_Vazia(TFila *f)
{
    if (f->inicio > f->fim)
    {                // 0 é maior que -1 no começo
        return true; // 1
    }
    else
    {
        return false; // 0 fila não vazia
    }
}

bool TFila_Cheia(TFila *f)
{
    if (f->fim == MAXTAM - 1)
    {
        return true; // fila cheia
    }
    else
    {
        return false; // 0 fila não cheia
    }
}

void TFila_Enfileira(TFila *f, Aluno alu)
{
    if (TFila_Cheia(f))
    {
        cout << "\nFila Cheia.\n\n";
    }
    else
    {
        f->fim++;
        f->Fila[f->fim] = alu;
        f->quantidade++;

        cout << alu.nome << " entrou na fila!!" << endl;
        Sleep(1500);
    }
}

void TFila_Desenfileira(TFila *f, Aluno *alu)
{
    if (TFila_Vazia(f))
    {
        cout << "\nFila vazia.\n\n";
    }
    else
    {
        *alu = f->Fila[f->inicio];
        f->inicio++;
        f->quantidade--;

        cout << "RA atendido: " << alu->RA << endl;
    }
}

void TFila_Imprime(TFila *f)
{
    if (TFila_Vazia(f))
    {
        cout << "\nFila vazia.\n\n";
    }
    else
    {
        int contador = 1;
        for (int i = f->inicio; i <= f->fim; i++)
        {
            cout << "-------------------\n";
            cout << "      [" << contador << "º]\n\n";
            cout << "RA: " << f->Fila[i].RA << "\n";
            cout << "Aluno: " << f->Fila[i].nome << "\n";
            contador++;
        }
        cout << "-------------------\n";
        cout << "\nTotal na Fila: " << f->quantidade << "\n\n";
        cout << "-------------------\n\n";
    }
}

void NovoAluno(TFila *f, Aluno alu)
{
    // nomes dos alunos
    char alunos[20][12] = {{'M', 'A', 'R', 'C', 'O', 'S', NULL, NULL, NULL, NULL, NULL, NULL},
                           {'E', 'D', 'U', 'A', 'R', 'D', 'O', NULL, NULL, NULL, NULL, NULL},
                           {'R', 'O', 'D', 'R', 'I', 'G', 'O', NULL, NULL, NULL, NULL, NULL},
                           {'A', 'L', 'E', 'S', 'S', 'A', 'N', 'D', 'R', 'A', NULL, NULL},
                           {'C', 'R', 'I', 'S', 'T', 'I', 'A', 'N', 'E', NULL, NULL, NULL},
                           {'M', 'A', 'R', 'I', 'A', NULL, NULL, NULL, NULL, NULL, NULL, NULL},
                           {'A', 'L', 'E', 'X', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
                           {'D', 'A', 'L', 'I', 'L', 'A', NULL, NULL, NULL, NULL, NULL, NULL},
                           {'P', 'A', 'U', 'L', 'O', NULL, NULL, NULL, NULL, NULL, NULL, NULL},
                           {'M', 'A', 'T', 'H', 'E', 'U', 'S', NULL, NULL, NULL, NULL, NULL},
                           {'R', 'I', 'V', 'E', 'L', 'I', 'N', 'O', NULL, NULL, NULL, NULL},
                           {'W', 'I', 'L', 'S', 'O', 'N', NULL, NULL, NULL, NULL, NULL, NULL},
                           {'R', 'O', 'M', 'I', 'L', 'D', 'A', NULL, NULL, NULL, NULL, NULL},
                           {'A', 'R', 'T', 'H', 'U', 'R', NULL, NULL, NULL, NULL, NULL, NULL},
                           {'P', 'E', 'D', 'R', 'O', NULL, NULL, NULL, NULL, NULL, NULL, NULL},
                           {'A', 'N', 'N', 'A', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
                           {'A', 'L', 'I', 'N', 'E', NULL, NULL, NULL, NULL, NULL, NULL, NULL},
                           {'F', 'E', 'L', 'I', 'P', 'E', NULL, NULL, NULL, NULL, NULL, NULL},
                           {'D', 'I', 'E', 'G', 'O', NULL, NULL, NULL, NULL, NULL, NULL, NULL},
                           {'F', 'E', 'R', 'N', 'A', 'N', 'D', 'A', NULL, NULL, NULL, NULL}};

    // vetor de RA dos alunos
    int ra[20] = {57607, 58608, 45579, 35698, 52456, 98745, 55555, 53603, 54604, 66647,
                  66666, 25253, 60209, 74610, 45544, 99100, 48966, 66325, 33377, 70465};

    int cod, ret;

    srand(time(NULL));
    cod = rand() % 20; // sorteando

    if (cod < 1)
    {
        cod = 1; // caso o numero fosse 0 pegaria lixo pois 0 - 1 = -1 que não existe essa posição no vetor
    }

    alu.RA = ra[cod - 1]; // salva o numero de ra do vetor na struct

    // salva o nome do aluno na struct
    for (int i = 0; i < 12; i++)
    {
        alu.nome[i] = alunos[cod - 1][i];
    }

    // percorre a fila para saber se o aluno ja está nela
    for (int i = f->inicio; i <= f->fim; i++)
    {
        if (f->Fila[i].RA == alu.RA)
        {
            ret = 1;
            break;
        }
        else
        {
            ret = 0;
        }
    }

    if (ret == 1)
    {
        cout << alu.nome << " Já está na fila!!\n\n";
        system("pause");
    }
    else
    {
        TFila_Enfileira(f, alu);
    }
}
