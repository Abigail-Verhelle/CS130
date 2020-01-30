#include <iostream>
#include <sstream>
#include "p2priorityqueue.h"
#include "p2set.h"
using namespace std;
int main()
{
    //declare factors
    string factors;
    int input[50];
    int k = 0;
    int x = 0;
    int size = 0;
    int num = 0;
    
    //create pq and set
    PriorityQueue<int,int> pq;
    Set<int>s;
    
    initialize(pq);
    initialize(s);
    
    //input
    cout << "prime factors: ";
    getline(cin,factors);
    
    cout << "K: ";
    cin >> k;
    
    stringstream ss(factors);
    
    //puts input into an array
    while (ss >> input[x])
    {
        x++;
        size++;
    }
    
    //pushes 1
    push(pq,1,-1);
    insert(s,1);
    
    for(int count = 1; count <= k;count++)
    {
        //poping smallest
        num = pop(pq);
        
        
        for(int v = 0; v < size;v++)
        {
            //making sure it doesn't already exisit
            if(! contains(s,input[v]*num))
            {
                //mult and pushing into pq and set
                push(pq,input[v]*num,input[v]*num*-1);
                insert(s,input[v]*num);
            }
        }
    }
    
    // if not empty out?
    if(! isEmpty(pq))
    {
        cout << "Result: " << num << endl;
    }
    
    // KILL THEM!!
    destroy(pq);
    destroy(s);
}
