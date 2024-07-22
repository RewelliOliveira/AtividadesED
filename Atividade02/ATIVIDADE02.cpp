#include <iostream>
#include <cmath>
#define atividade "2"  
#define nome "Antonio rewelli" 
#define matricula "554047"
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
           // cria  ponto dadas coordenadas
           x = _x;
           y = _y;
    }
    ponto () {
         // alternativa de criação de ponto
         // para construir um ponto (0,0) 
         x = 0;
         y = 0;
     }
     float dist (const ponto& p) {
            // determina a distância do ponto
            // à este passado como argumeto.
            return sqrt((p.x - x ) * (p.x - x) + (p.y - y) * (p.y - y));
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
    return (q.Y( ) - p.Y()) / (q.X() - p.X());
}

float minDist(const ponto& p, ponto kust[], int n) {
    float a , b;
  if(n == 1){
    return kust[0].dist(p);
  }else{
    b = minDist(p, kust++, n-1);
    a = kust[0].dist(p);
    if(b < a) return b;
    else return a;
  }
}

// int main() {
//   ponto p(1, 2), q(2, 3);
//   ponto kust[] = {{3, 4}, {5, 6}, {7, 8}};

//   cout << "Distância entre p e q: " << p.dist(q) << std::endl;
//   cout << "Coeficiente angular da reta pq: " << reta(p, q) << std::endl;
//   cout << "Menor distânciagcc entre p e os pontos da lista: " << minDist(p, kust, 3) << std::endl;
// }

int main()
{
    ponto a(15, 57), b(5, 20), c(10, 50), d(1, 1);
    ponto p(7, 27);

    ponto kust[] = { a, b, c, d };

    cout << minDist(p, kust, 4) << std::endl;

    return 0;
}


