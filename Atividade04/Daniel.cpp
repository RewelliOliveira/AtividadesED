#define atividade "04"
#define nome "Daniel Christopher Souza Rodrigues"
#define matricula "552493"
// 1

#include <iostream>

using namespace std;

class vetor
{
  int *u;   // ponteiro para vetoe
  int size; // tamanho do vetor
public:
  vetor(int n)
  {
    u = new int[n];
    size = n;
  }

  ~vetor() { delete[] u; }

  int &operator[](int k) { return u[k]; }

  int len() { return size; }
};

void merge(vetor& l_vet, vetor& r_vet, vetor& result, int& i) {
  int l = l_vet.len() - 1;
  int r = r_vet.len() - 1;
  
  while (l >= 0 && r >= 0) {
    if (l_vet[l] < r_vet[r]) {
      result[i] = l_vet[l];
      --l;
      ++i;
    } else {
      result[i] = r_vet[r];
      --r;
      ++i;
    }
  }

  while (l > 0) result[i++] = l_vet[l--];
  while (r > 0) result[i++] = r_vet[r--];

}

vetor mergeAll(vetor U[], int n) {
    /*
    Esta função funde os n vetores na entrada U 
    num vetor de saída . Note que se os vetores 
    em U são ordenados então o vetor de saída 
    também o será. Porém mantenha em mente 
    que as entradas em U NÃO são necessariamente 
    ordenadas nos casos de testes.     
    */
    int result_len = 0;

    for (int i = 0; i < n; i++) {
      result_len += U[i].len();
    }

    vetor result(result_len);
    int index = 0;

    for (int i = 0; i < n - 1; i++) {
      merge(U[i], U[i + 1], result, index);
    }

    return result; 
}

int main() {
  vetor U[3] = {
    vetor(3),
    vetor(3),
    vetor(4)
  };

  U[0][0] = 1;
  U[0][1] = 2;
  U[0][2] = 3;

  U[1][0] = 6;
  U[1][2] = 5;
  U[1][1] = 8;

  U[2][1] = 0;
  U[2][3] = 1;
  U[2][0] = 4;
  U[2][2] = 9;

  vetor result = mergeAll(U, 3);

  for (int i = 0; i < result.len(); i++) {
    cout << result[i] << " ";
  }

  return 0;
}

/*
Exemplo

U = { [6,8,5], [3,2,1], [4,0,9] }

{ [6,8,5], [3,2], [4,0,9] } => {1}
{ [6,8,5], [3], [4,0,9] } => {1,2}
{ [6,8,5], [], [4,0,9] } => {1,2,3}
{ [6,8], [], [4,0,9] } => {1,2,3,5}
{ [6], [], [4,0,9] } => {1,2,3,5,8}
{ [], [], [4,0,9] } => {1,2,3,5,8,6}
{ [], [], [] } => {1,2,3,5,8,6,9,0,4}

*/