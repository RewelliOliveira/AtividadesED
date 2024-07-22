#include <cmath>
#define atividade "2"  
#define nome "Antonio Rewelli" 
#define matricula "554047"

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
