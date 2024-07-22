#define atividade "04"
#define nome "Garibaldi"
#define matricula "*123"

#include <iostream>

using namespace std;

// 1

class vetor
{
  int *u;   // ponteiro para vetor
  int size; // tamanho do vetor
  int index; // índice atual

public:
  vetor(int n)
  {
    u = new int[n];
    for (int i = 0; i < n; i++) {
      u[i] = 0;
    }
    size = n;
    index = 0;
  }
  ~vetor() { delete[] u; }
  int &operator[](int k) { return u[k]; }
  int len() { return size; }

  void operator+=(int k) {
    u[index] = k;
    ++index;
  }
};

vetor mergeAll(vetor U[], int count)
{
  /*
  Esta função funde os n vetores na entrada U
  num vetor de saída . Note que se os vetores
  em U são ordenados então o vetor de saída
  também o será. Porém mantenha em mente
  que as entradas em U NÃO são necessariamente
  ordenadas nos casos de testes.
  */
  vetor indexes(count); // Índices para acompanhar as posições em cada vetor
  int resultSize = 0; // Tamanho do vetor de saída

  // Calcula o tamanho total do vetor de saída
  for (int i = 0; i < count; i++) {
    resultSize += U[i].len();
  }

  vetor result(resultSize); // Vetor de saída

  while (true) {
    int smallestIndex = -1; // Índice do menor elemento encontrado
    bool found = false; // Indica se um menor elemento foi encontrado

    for (int i = 0; i < count; i++) {
      if (indexes[i] < U[i].len()) {
        if (!found || U[i][indexes[i]] < U[smallestIndex][indexes[smallestIndex]]) {
          smallestIndex = i;
          found = true;
        }
      }
    }

    if (!found) {
      break; // Se não encontrou nenhum elemento menor, sai do loop
    }

    result += U[smallestIndex][indexes[smallestIndex]]; // Adiciona o menor elemento ao resultado
    indexes[smallestIndex]++; // Avança o índice do vetor que teve o menor elemento
  }

  return result;
}

int main()
{
  vetor U[3] = {
      vetor(3),
      vetor(3),
      vetor(3),
  };

  U[0][0] = 6; U[0][1] = 8; U[0][2] = 5;

  U[1][0] = 3; U[1][1] = 2; U[1][2] = 1;

  U[2][0] = 4; U[2][1] = 0; U[2][2] = 9;

  vetor r = mergeAll(U, 3);

  for (int i = 0; i < r.len(); i++)
  {
    cout << r[i] << " ";
  }

  return 0;
}

/*
Exemplo 1

U = { [6,8,5], [3,2,1], [4,0,9] }

{ [6,8,5], [2,1], [4,0,9] } => {3}
{ [6,8,5], [1], [4,0,9] } => {3,2}
{ [6,8,5], [], [4,0,9] } => {3,2,1}
{ [6,8,5], [], [0,9] } => {3,2,1,4}
{ [6,8,5], [], [9] } => {3,2,1,4,0}
{ [8,5], [], [9] } => {3,2,1,4,0,6}
{ [5], [], [9] } => {3,2,1,4,0,6,8}
{ [], [], [9] } => {3,2,1,4,0,6,8,5}
{ [], [], [] } => {3,2,1,4,0,6,8,5,9}

Exemplo 2

U = { [1,3,5], [2,4,6], [7,8,9] }


{ [3,5], [2,4,6], [7,8,9] } => {1}
{ [3,5], [4,6], [7,8,9] } => {1,2}
{ [5], [4,6], [7,8,9] } => {1,2,3}
{ [5], [6], [7,8,9] } => {1,2,3,4}
{ [], [6], [7,8,9] } => {1,2,3,4,5}
{ [], [], [7,8,9] } => {1,2,3,4,5,6}
{ [], [], [8,9] } => {1,2,3,4,5,6,7}
{ [], [], [9] } => {1,2,3,4,5,6,7,8}
{ [], [], [] } => {1,2,3,4,5,6,7,8,9}

*/
