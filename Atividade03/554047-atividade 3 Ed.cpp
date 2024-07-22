#include <fstream>
#define atividade "3"
#define nome "Antonio Rewelli"
#define matricula "554047"

namespace aluno {

class frac {
   int num;
   int den;
   static int mdc(int x, int y) {
       if(y == 0) return x;
       else return mdc(y, x % y);
   }

public:
   frac(int n=0, int d=1) : num(n), den(d) {
       int div = mdc(num, den);
       num /= div;
       den /= div;
       if (den < 0) { // Garantir que o denominador seja positivo
           num = -num;
           den = -den;
        }
   }
   
   bool operator>(frac &frac2)
        {
            if (((float)num / den) > ((float)frac2.getNum() / frac2.getDen()))
                return true;
            return false;
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
    if (n == 1)
        return fracs[0];

    frac soma = fracs[0];
    for (int i = 1; i < n; i++)
    {
        soma = soma + fracs[i];
    }
    return soma;
}

void sortFracs(frac fracs[], int n) {
    /*
       ordena vetor de drações de entrada. Note que um ponteiro do vetor real é passado como argumento. O tamanho passaso  do vetor é dado por n.   
    */
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(fracs[j] > fracs[j + 1]){
                frac aux = fracs[j];
                fracs[j] = fracs[j + 1];
                fracs[j + 1] = aux;
            }
        }
    }
}
}