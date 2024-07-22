#include <fstream>
#include <iostream>
using namespace std;

#define atividade "3"
#define nome "Antonio Rewelli"
#define matricula "554047"

/* Representa uma fração reduzida, ou seja, numerador e denominador são primos entre si. */
namespace aluno
{
    class frac
    {
        int num;
        int den;

        static int mdc(int a, int b)
        {
            if (b == 0)
            {
                return a;
            }
            else
            {
                return mdc(b, a % b);
            }
        }

    public:
        frac(int n, int d)
        {
            if (d == 0) // Garantir que o denominador não seja zero
            {
                throw invalid_argument("Denominador não pode ser zero.");
            }
            
            // Garantir que o denominador seja positivo
            if (d < 0)
            {
                n = -n;
                d = -d;
            }

            int m = mdc(n, d);
            num = n / m;
            den = d / m;
        }

        frac() : num(0), den(1) {} // Inicializador padrão para frações 0/1

        // Operador maior para fração
        bool operator>(const frac &f) const
        {
            double num1 = static_cast<double>(num) / den;
            double num2 = static_cast<double>(f.getNum()) / f.getDen();
            return num1 > num2;
        }

        // Operador igual para fração
        bool operator==(const frac &f) const
        {
            return num == f.getNum() && den == f.getDen();
        }

        // Operador soma para fração
        frac operator+(const frac &f) const
        {
            int n_num = num * f.getDen() + f.getNum() * den;
            int n_den = den * f.getDen();
            return frac(n_num, n_den);
        }

        int getNum() const
        {
            return num;
        }

        int getDen() const
        {
            return den;
        }
    };

    frac *loadFracs(const char *fileFracs)
    {
        ifstream file(fileFracs);

        if (!file.is_open())
        {
            throw runtime_error("Não foi possível abrir o arquivo.");
        }

        // Lendo a quantidade de frações
        int n;
        file >> n;

        // Vetor dinamicamente alocado
        frac *vetor = new frac[n];

        for (int i = 0; i < n; i++)
        {
            int num, den;
            file >> num >> den; // Lê o numerador e o denominador de cada linha
            vetor[i] = frac(num, den); // Cria um objeto frac e o coloca no vetor
        }

        file.close();

        return vetor;
    }

    frac sumFracs(const frac fracs[], int n)
    {
        frac f = fracs[0];
        for (int i = 1; i < n; i++)
        {
            f = f + fracs[i];
        }
        return f;
    }

    void swap(frac u[], int j)
    {
        frac x = u[j];
        u[j] = u[j + 1];
        u[j + 1] = x;
    }

    // Ordena vetor de frações de entrada. Note que um ponteiro do vetor real é passado como argumento.
    // O tamanho passado do vetor é dado por n.
    void sortFracs(frac fracs[], int n)
    {
        for (int i = n - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (fracs[j] > fracs[j + 1])
                {
                    swap(fracs, j);
                }
            }
        }
    }
}

int main()
{
    try
    {
        // Criar um vetor de frações com as entradas fornecidas
        aluno::frac fracoes[] = {aluno::frac(2, 3), aluno::frac(5, 6), aluno::frac(87, 24), aluno::frac(2, -4)};
        int quantidade = sizeof(fracoes) / sizeof(fracoes[0]);

        // Imprimir frações antes da ordenação
        cout << "Frações antes da ordenação:" << endl;
        for (int i = 0; i < quantidade; i++)
        {
            cout << fracoes[i].getNum() << "/" << fracoes[i].getDen() << " ";
        }
        cout << endl;

        // Ordenar frações
        aluno::sortFracs(fracoes, quantidade);

        // Imprimir frações após a ordenação
        cout << "Frações após a ordenação:" << endl;
        for (int i = 0; i < quantidade; i++)
        {
            cout << fracoes[i].getNum() << "/" << fracoes[i].getDen() << " ";
        }
        cout << endl;

        // Somar frações
        aluno::frac soma = aluno::sumFracs(fracoes, quantidade);

        // Imprimir a soma das frações
        cout << "Soma das frações: " << soma.getNum() << "/" << soma.getDen() << endl;
    }
    catch (const exception &e)
    {
        cerr << "Erro: " << e.what() << endl;
    }

    return 0;
}
