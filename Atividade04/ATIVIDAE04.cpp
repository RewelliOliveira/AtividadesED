#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class vetor {
   vector<int> u;  // vetor de inteiros
public:
   vetor() {}
   vetor(initializer_list<int> il) : u(il) {}
   int& operator[] (int k) { return u[k]; } 
   int len() const { return u.size(); }
   void push_back(int val) { u.push_back(val); }

   // Adicionar um método para obter o vetor u
   vector<int>& getVector() { return u; }
};

vetor mergeAll(vetor U[]) {
    // Criar um vetor temporário para armazenar todos os elementos dos vetores de entrada
    vetor temp;

    // Comparar e fundir o primeiro vetor com o segundo vetor
    int i = 0, j = 0;
    while (i < U[0].len() && j < U[1].len()) {
        if (U[0][i] <= U[1][j]) {
            temp.push_back(U[0][i++]);
        }
        else {
            temp.push_back(U[1][j++]);
        }
    }
    while (i < U[0].len()) {
        temp.push_back(U[0][i++]);
    }
    while (j < U[1].len()) {
        temp.push_back(U[1][j++]);
    }

    // Comparar e fundir o primeiro vetor com o terceiro vetor
    i = 0;
    j = 0;
    int k = 0;
    while (i < temp.len() && j < U[2].len()) {
        if (temp[i] <= U[2][j]) {
            temp.push_back(temp[i++]);
            temp[k++] = U[2][j++];
        }
    }
    while (i < temp.len()) {
        temp.push_back(temp[i++]);
    }
    while (j < U[2].len()) {
        temp.push_back(U[2][j++]);
    }

    return temp;
}

int main() {
    vetor U[] = { {6,8,5}, {3,2,1}, {4,0,9} };

    vetor result = mergeAll(U);

    // Imprimir o vetor resultante
    cout << "{ ";
    for (int i = 0; i < result.len(); i++) {
        cout << result[i];
        if (i < result.len() - 1) {
            cout << ", ";
        }
    }
    cout << " }" << endl;

    return 0;
}
