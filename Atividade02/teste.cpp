#include <iostream>
#include <cmath>

using namespace std;
/*
Seja uma classe que representa um ponto no plano dada por,.  
*/

class ponto {
    float x; // abcissa
    float y; // ordenada
public:
    ponto (int _x, int _y)  // constrói ponto
    {  
        x = _x;
        y = _y;
           // cria  ponto dadas coordenadas
    }
    ponto () {
        x = 0;
        y = 0;
         // alternativa de criação de ponto
         // para construir um ponto (0,0) 
     }
     float dist (const ponto& p) {
            // determina a distância do ponto
            // à este passaso como argumeto.
            return sqrt((p.x - x)*(p.x - x) + (p.y - y)*(p.y - y));
        }
        float& X() {
               // retorna referência 
               // da abcissa 
               return x;
        }
        float Y() {
             // Retorna referência para
             // a ordenada
             return y;
         }
};

/* Implemente as funções a seguir usando a classe anterior */
float reta(ponto& p, ponto& q) {
    // retorna coeficiente angular da reta 
    // que passa por p e 
    return (q.Y() - p.Y()) / (q.X() - p.X());
}

float minDist(const ponto& p, ponto kust[], int n) {
   // retorna a menor distância entre p e os // pontos da lista list dada de 
   // comprimento n.
float u, d;
 if(n == 1) {
        u = kust[0].dist(p);
        return u;
    } else {
        d = minDist(p, kust + 1, n - 1);
        u = kust[0].dist(p);
        if(d < u) {
            return d;
        }else {
            return u;
        }
   }
}



int main()
{
    ponto a(15, 57), b(5, 20), c(10, 50), d(1, 1);
    ponto p(7, 27);

    ponto kust[] = { a, b, c, d };

    cout << minDist(p, kust, 4) << std::endl;

    return 0;
}