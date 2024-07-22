#define atividade "04"
#define nome "Garibaldi"
#define matricula "*123"

#include <iostream>

using namespace std;

// 1

class vetor{

   int *u;  // ponteiro para vetor
   int size; // tamanho do vetor
   bool copiado = false;

public:

   vetor(int n) { u = new int[n]; size = n; }
   ~vetor() { delete [] u; }
   int& operator[] (int k) { return u[k]; } 
   int len(){ return size; }
   void setCopiado(bool arg){ copiado = arg; }
   bool getCopiado(){ return copiado; }
};

vetor mergeAll(vetor U[], int n){
   int tamanhoTot = 0;
   for(int i = 0; i < n; i++){
      tamanhoTot += U[i].len();
   }
   vetor resultante(tamanhoTot);
   int index = 0;
   for(int i = 0; i < n; i++){
      int verificaMenor = 100000;
      int indexMenor = -1;
      for(int k = 0; k < n; k++){ // Busca qual o Menor
         if(!U[k].getCopiado()){
            int tam = U[k].len() - 1;
            if(verificaMenor > U[k][tam]){
               verificaMenor = U[k][tam];
               indexMenor = k;
            }
         }
      }
      for(int j = U[indexMenor].len() - 1; j >= 0; j--){ // Copia para o vetor de saída
         resultante[index++] = U[indexMenor][j];
      }
         U[indexMenor].setCopiado(true);
   }
   return resultante;
}

int main() {
    // Criando três vetores de exemplo
    vetor U1(3);
    U1[0] = 6; U1[1] = 8; U1[2] = 5;
    vetor U2(3);
    U2[0] = 3; U2[1] = 2; U2[2] = 1;
    vetor U3(3);
    U3[0] = 4; U3[1] = 0; U3[2] = 9;
    // Criando um vetor de vetores
    vetor U[] = {U1, U2, U3};
    // Chama a função mergeAll com o vetor de vetores e o tamanho
    vetor resultado = mergeAll(U, 3);
    // Imprime o resultado
    for (int i = 0; i < resultado.len(); i++) {
        cout << resultado[i] << " ";
    }
    cout << endl;

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