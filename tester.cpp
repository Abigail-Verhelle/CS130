#include <iostream>
#include "p2heap.h"
using namespace std;
int main()
{

//input one
int A = 5, B = 6, C = 1, D = 10, E = 18, F = 27, G = 4, H = 19, S;
//input two
int I = 3, J = 12, K = 30, L = 15, M = 4;
////////////////////////////////////////////////

Heap<int> T;
initialize(T);
    
put(T,A);
put(T,B);
put(T,C);
put(T,D);
put(T,E);
put(T,F);
put(T,G);
put(T,H);
S = get(T);
S = get(T);
S = get(T);
put(T,I);
put(T,J);
put(T,K);
put(T,L);
put(T,M);
    
    for(int x = 0; x < 8; x++)
    {
        S = get(T);
        
        cout << S << endl;
    }

//assert(T.data[2] == M);

}

