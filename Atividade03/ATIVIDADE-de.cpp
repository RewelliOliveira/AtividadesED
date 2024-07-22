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
       if (y == 0) return x;
       else return mdc(y, x % y);
   }

public:
   frac(int n=0, int d=1) : num(n), den(d) {
       if (den < 0) { // Garantir que o denominador seja positivo
           num = -num;
           den = -den;
       }
       int div = mdc(num, den);
       num /= div;
       den /= div;
   }

   // Operadores
   bool operator>(const frac& fracao) const {
       // Configura operador >
       return (num * fracao.den) > (den * fracao.num);
   }

   bool operator==(const frac &fracao) const {
       // Configura operador ==
       return (num == fracao.num && den == fracao.den);
   }

   frac operator+(const frac& fracao) const {
       // Soma
       int n_num = (num * fracao.den) + (den * fracao.num);
       int n_den = den * fracao.den;

       int divisor = mdc(n_num, n_den);
       n_num /= divisor;
       n_den /= divisor;

       return frac(n_num, n_den);
   }

   int getNum() const { return num; }
   int getDen() const { return den; }
};

frac* loadFracs(char* fileFracs) {
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

frac sumFracs(const frac fracs[], int n) {
    if (n == 1) return fracs[0];

    frac soma = fracs[0];
    for (int i = 1; i < n; i++) {
        soma = soma + fracs[i];
    }
    return soma;
}

void sortFracs(frac fracs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (fracs[j] > fracs[j + 1]) {
                frac aux = fracs[j];
                fracs[j] = fracs[j + 1];
                fracs[j + 1] = aux;
            }
        }
    }
}

}

using namespace aluno;
using namespace std;

int main() {
    // Criar um vetor de frações com as entradas fornecidas
    frac fracoes[] = {frac(2, 3), frac(5, 6), frac(87, 24), frac(2, -4)};
    int quantidade = sizeof(fracoes) / sizeof(fracoes[0]);

    // Imprimir frações antes da ordenação
    cout << "Frações antes da ordenação:" << endl;
    for (int i = 0; i < quantidade; i++) {
        cout << fracoes[i].getNum() << "/" << fracoes[i].getDen() << " ";
    }
    cout << endl;

    // Ordenar frações
    sortFracs(fracoes, quantidade);

    // Imprimir frações após a ordenação
    cout << "Frações após a ordenação:" << endl;
    for (int i = 0; i < quantidade; i++) {
        cout << fracoes[i].getNum() << "/" << fracoes[i].getDen() << " ";
    }
    cout << endl;

    // Somar frações
    frac soma = sumFracs(fracoes, quantidade);

    // Imprimir a soma das frações
    cout << "Soma das frações: " << soma.getNum() << "/" << soma.getDen() << endl;

    return 0;
}
