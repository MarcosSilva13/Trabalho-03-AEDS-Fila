#include <iostream>
#include <windows.h>
#include "Fila.cpp"
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  TFila f;
  Aluno alu;

  TFila_Inicializa(&f);

  int op;  
  do{
    system("cls");
    menu();
    cout << "\n-> ";
    cin >> op;
    
    switch (op)
    {
    case 1:
        NovoAluno(&f, alu);
        break;
    case 2:
        TFila_Desenfileira(&f, &alu);
        system("pause");
        break;
    case 3:
        system("cls");
        cout << "***** FILA *****\n";
        TFila_Imprime(&f);
        system("pause");
        system("cls");
        break;    
    }
    
  }while(op != 4);
  
  return 0;
}