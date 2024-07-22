#define atividade "04"
#define nome "Antonio Rewelli"
#define matricula "554047"
// 1
class vetor{
  int *u;   // ponteiro para vetor
  int size; // tamanho do vetor
  int index; // índice atual

public:
  vetor(int n){
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

vetor mergeAll(vetor U[], int count){
  /*
  Esta função funde os n vetores na entrada U
  num vetor de saída . Note que se os vetores
  em U são ordenados então o vetor de saída
  também o será. Porém mantenha em mente
  que as entradas em U NÃO são necessariamente
  ordenadas nos casos de testes.
  */
  vetor indexes(count);
  int resultSize = 0;

  for (int i = 0; i < count; i++) {
    resultSize += U[i].len();
  }

  vetor result(resultSize);

  while (true) {
    int smallestIndex = -1; 
    bool found = false; 

    for (int i = 0; i < count; i++) {
      if (indexes[i] < U[i].len()) {
        if (!found || U[i][indexes[i]] < U[smallestIndex][indexes[smallestIndex]]) {
          smallestIndex = i;
          found = true;
        }
      }
    }

    if (!found) {
      break;
    }

    result += U[smallestIndex][indexes[smallestIndex]]; 
    indexes[smallestIndex]++;
  }

  return result;
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
