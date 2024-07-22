#include <iostream>
#include <stack>
using namespace std;

// void cuscuz(stack<int>& pilha);

void arroz(int n, stack<int>&pilha){
    if(n <= 0) return;
    pilha.push(n);
    arroz(n-1, pilha);
}
void feijao(stack<int> &pilha){
    // cuscuz(pilha);
    while(!pilha.empty()){
        cout << pilha.top() << endl;
        pilha.pop();
    }
}
// void cuscuz(stack<int>&pilha){
//     stack<int>pilhaT;

//     while (!pilha.empty()){
//         pilhaT.push(pilha.top());
//         pilha.pop();
//     }

//     while(pilhaT.empty()){
//         pilha.push(pilhaT.top());
//         pilhaT.top();
//     }
// }

int main(){
    stack<int> pilha;

    int a = 0;
    cin >> a;

    arroz(a, pilha);

    feijao(pilha);

     return 0;
}