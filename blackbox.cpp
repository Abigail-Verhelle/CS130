#include <iostream>
#include "p2queue.h"
#include"p2priorityqueue.h"
#include "p2stack.h"
using namespace std;
int main()
{
    
    string command;
    int value = 0;
    bool Q = true;
    bool S = true;
    bool PQ = true;
    
//    Queue<int> command;
    Queue<int> q;
    Stack<int> s;
    PriorityQueue<int,int> pq;
    
    initialize(q);
    initialize(s);
    initialize(pq);
    
    cout << "Command: ";
    cin >> command >> value;
    
    while(command != "END")
    {
       
        if (command == "PUSH")
        {
            //pushing input into queue
            push(q,value);
            push(s,value);
            push(pq,value,value);
        }
        else //poping and using bools to commpare
        {
            if (! isEmpty(q) && Q)
            {
                if(pop(q) != value)
                {
                    Q = false;
                }
            }
            if(! isEmpty(s) && S)
            {
               if(pop(s) != value)
               {
                   S = false;
               }
            }
            if(! isEmpty(pq) && PQ)
            {
                if(pop(pq) != value)
                {
                    PQ = false;
                }
            }
        }
        
        cout << "Command: ";
        cin >> command >> value;
    }
  
    
    //output
  
    if (Q && !PQ && !S)
    {
        
        cout << "The black box holds a queue." << endl;
    
    }
    else if(!Q && !PQ && S)
    {
        
        cout << "The black box holds a stack." << endl;
        
    }
    else if (!Q && PQ && !S)
    {
        
        cout << "The black box holds a priority queue." << endl;
        
    }
    
    else if ( Q || PQ || S)
    {
        cout << "The black box remains mysterious." << endl;
        
    }
    
    else
    {
        
        cout << "The black box holds something else." << endl;
        
    }
    
    destroy(pq);
    destroy(s);
    destroy(q);
}
