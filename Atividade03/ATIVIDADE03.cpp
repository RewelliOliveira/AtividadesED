#include <fstream>
#include <iostream>

#define atividade "3"  
#define nome "Garibaldi" 
#define matricula "***123"

using namespace std;
namespace aluno {

/*
Representa uma fração reduzida, ou seja, numerador e denominador são primos entre si.  
*/

class frac {
   int num;
   int den;
   static int mdc(int x, int y) {
       // calcula mdc dos argumentos
       if(y == 0) return x;
       else return mdc(y, x % y);
   }

public:   
frac(int n=0, int d=1) {  
       // configura operador == 
       num = n;
       den = d;
   }
   // Operadores 
   bool operator>(frac& fracao) {
        // configura operador >
        if((num/ den) > (fracao.num/fracao.den)) return true;
        return false;
   }

   bool operator==(frac &fracao){
      // configura operador ==
      if (num == fracao.num() && den == fracao.den) return true;
      return false;
    }
   
   frac operator+(frac& fracao) {
        // soma
        int n_num = (num * fracao.den) + (den * fracao.num);
        int n_den = den * fracao.den;

        n_num = n_num / mdc(n_num, n_den);
        n_den = n_den / mdc(n_num, n_den);
        
        return frac(n_num, n_den);
    }     

   int getNum() { return num; }    
   int getDen() { return den; } 
};

frac* loadFracs(char* fileFracs) {
/* 
Retorna frações num arquivo e as coloca em um vetor alocaso dinamicamente. 

O conteúdo de tais arquivos segue o formato do esquema a seguir,

-----------
4           | -> 4 frações
1   2       | -> fração 1/2
3   5       | -> fração 1/5
2   9       ! -> fração 2/9 
7   11      ! -> fração 7/11
-------------
*/
    std::ifstream file(fileFracs);

    int numFracs;
    file >> numFracs;

    frac* fracs = new frac[numFracs];

    int num, den;
    for (int i = 0; i < numFracs; ++i) {
        file >> num >> den;
        fracs[i] = frac(num, den);
    }

    file.close();
    return fracs;
}

//Meu: não entendi foi nada
frac sumFracs(frac fracs[], int n) {
  /* 
   Retorna soma de frações do vetor de entrada. 
*/
if(n == 1) return fracs[0];

frac prox_frac = sumFracs(fracs + 1, n-1);
    return fracs[0] + prox_frac;
}


void sortFracs(frac fracs[], int n) {
    /*
       ordena vetor de drações de entrada. Note que um ponteiro do vetor real é passado como argumento. O tamanho passaso  do vetor é dado por n.   
    */
   for(int i = 0; i < n-1; i++){
    for(int j = 0; j < n-i-1; j++){
        if(fracs[j] > fracs[j+1]){
            frac x = fracs[j];
            fracs[j] = fracs[j+1];
            fracs[j+1] = x;
                }
            }
        }
    }
}
using namespace aluno;
int main() {

    char filename[] = "fractions.txt";
    frac* fracs = loadFracs(filename);
    for (int i = 0; i < 4; ++i) {
        cout << "fracao " << (i + 1) << ": " << fracs[i].getNum() << "/" << fracs[i].getDen() << endl;
    }

    // 0,4444
    // 0,6
    // 0,85
    // 1,33

    // char filename[] = "fractions.txt";
    // frac* fracs = loadFracs(filename);

    // frac fracs[4] = {frac(8, 9), frac(7, 5), frac(8, 100), frac(2, 1)};
    // frac vetor[4] = {frac(1, 1), frac(2, 1), frac(8, 1), frac(6, 1)};
    // 0,75 - 1,4 - 2,6666 - 2
    // frac soma = sumFracs(fracs, 4);


    // cout << soma.getNum() << " " << soma.getDen() << endl;

    // sortFracs(fracs, 4);

    for(int i = 0; i < 4; i++) {
        cout << fracs[i].getNum() << " " << fracs[i].getDen() << endl;
    }

    delete[] fracs;

    return 0;
}