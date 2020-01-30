#include <iostream>
#include "p2priorityqueue.h"
using namespace std;
int sum(int one, int two)
{
    int sum = one + two;
    return sum;
}
int main ()
{
    int array1[10];
    int array2[10];
    int index = 0;
    int index2 = 0;
    int k = 0;
    
    //make queue
    PriorityQueue<int,int> pq;
    initialize(pq);
    
    cout << "Enter 1st list: " << endl;
    cin >> array1[index];
    
    //input
    while( array1[index] != 0)
    {
        cin >> array1[index];
        index++;
    }
    
    cout << "Enter 2nd list: " << endl;
    cin >> array2[index2];
    
    while(array2[index2] != 0)
    {
        cin >> array2[index2];
        index2++;
        
    }
    
    cout << "Enter k: ";
    cin >> k;
    cout << endl;
    
//    int prob = (k-1) * (k-1);
//    index = 0;
//    index2 = 0;

//    for (int p = 0; p < k;p++)
//    {
//        for (int x = 3;array1[index] < k; index++)
//        {
//        push(pq,array1[index] + array2[index2],array1[index] + array2[index2]);
//        push(pq,array1[index] + array2[index2+1],array1[index] + array2[index2+1]);
//
//            while (x >= k)
//            {
//                push(pq,array1[index] + array2[index2 + x],array1[index] + array2[index2 + x]);
//                x++;
//            }
//
//        }
//    }
    
    for (int p = 0; p <= k-1; p++)
    {
        // pushing into queue
        for (int count = 0; count <= k; count++)
        {
//            push(pq,sum(array2[p],array1[count]),sum(array2[p],array1[count]));
            push (pq,array2[p] + array1[count],array2[p] + array1[count]);
//                  push(pq,array2[q] + array1[count],array2[q] + array1[count]); array2[p] + array1[count],array2[p] + array1[count]);
            
        }
    }
    
    
    //pop out output
 cout << k << " largest sums" << endl;

    for(int y = 0;y <= k; y++)
    {
        if(isEmpty(pq))
        {
            cout << "you suck " << endl;
        }
        
        cout << pop(pq) << endl;
        
        
    }
    
}
