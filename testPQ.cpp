#include <iostream>
#include "p2priorityqueue2.h"
using namespace std;

int main()
{
    cout << "* This program tests an implementation of a Priority Queue *\n\n";
    
    // Create and initialize priority queue
    PriorityQueue<string,int> p;
    initialize(p);
    
    string command;
    while(true)
    {
        cin >> command;
        
        if( command == "Quit" )
            break; // quit loop, end program
        
        else if( command == "Push" )
        {
            string value;
            int rank;
            cin >> value;
            cin >> rank;
            push(p,value,rank);
        }
        
        else if( command == "Pop" )
        {
            if( isEmpty(p) )
                cout << ">> Priority Queue empty\n";
            else
                cout << ">> " << pop(p) << endl;
        }
    }
}
