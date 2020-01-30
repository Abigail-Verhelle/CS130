#include <iostream>
#include <fstream>
#include "p2queue.h"
using namespace std;

int strtoint(string a)
{
    // change all the charaters to integers
    if(a == "A")
    {
        return 14;
    }
    
    if(a == "10")
    {
        return 10;
    }
    
    if(a == "J")
    {
        return 11;
    }
        
    if(a == "Q")
    {
        return 12;
    }
        
    if(a == "K")
    {
        return 13;
    }
    
        return (int)(a[0] - 48);
    
}

void War(Queue<int>& P1, Queue<int>& P2, int& PP1, int& PP2, int& round)
{
    Queue<int> hostages;
    initialize(hostages);
    
    Queue<int> captives;
    initialize(captives);
    
    while(PP1 == PP2)
    {
        // put cards into new Q
        push(hostages,PP1);
        push(captives, PP2);
        
        for(int y = 0;y < 3; y++)
        {
            if(!isEmpty(P1))
            {
                push(hostages, pop(P1));
            }
        
            if(!isEmpty(P2))
            {
                push(captives, pop(P2));
            }
        }
        
        // add a round if niether Q is empty
        if(!isEmpty(P1) && !isEmpty(P2))
        {
            round++;
        }
        
        //reset
        PP1 = 0;
        PP2 = 0;
        
        //empty?
        if(!isEmpty(P1))
        {
            PP1 = pop(P1);
        }
        
        //Empty
        if(!isEmpty(P2))
        {
            PP2 = pop(P2);
        }
        
        // PP1 wins
        if(PP1 > PP2 || isEmpty(P2))
        {
            
            while(!isEmpty(hostages))
            {
                push(P1,pop(hostages));
            }
            
            push(P1,PP1);
            
            while(!isEmpty(captives))
            {
                push(P1,pop(captives));
            }
            
            push(P1,PP2);
            
        }
        
        // if P2 wins
        else if(PP2 > PP1 || isEmpty(P1))
        {
            
            while(!isEmpty(captives))
            {
                push(P2,pop(captives));
            }
            
            push(P2,PP2);
            
            while(!isEmpty(hostages))
            {
                push(P2,pop(hostages));
            }
            
            push(P2,PP1);
            
        }
        
    }
    
    // kill them
    destroy(hostages);
    destroy(captives);
}



int main()
{
    
    ifstream fin;
    ofstream fout;

    // variables
    string in;
    int round = 0;

    // PQ for player 1
    Queue<int> P1;
    initialize(P1);

    // PQ for player 2
    Queue<int> P2;
    initialize(P2);

    // open file
    fin.open("player1");
    // did it open?
    if( fin.is_open() )
    {
        // take in file info
        while(fin >> in)
        {
            push(P1, strtoint(in));
        }
    
    }
    //NOPE it didi not
    else
        cout << "you real dumb" << endl;
    // trash the fill
    fin.close();

    //poen player two file
    fin.open("player2");
// opened?
    if( fin.is_open() )
    {
        // take in the file
        while(fin >> in)
        {
            // push and change to int
            push(P2, strtoint(in));
        }
    }
    
//    did not work
    else
        cout << "you real dumb" << endl;
    
    // burn the file
    fin.close();
    
    
    
    //
    while(round < 5000 && !isEmpty(P1) && !isEmpty(P2))
    {
        int PP1 = 0;
        int PP2 = 0;
        
        if(!isEmpty(P1))
        {
            PP1 = pop(P1);
//            cout << PP1 << endl;
        }
        
        if(!isEmpty(P2))
        {
            PP2 = pop(P2);
//            cout << PP2 << endl;
        }
        
        if (PP1 == PP2)
        {
            War(P1,P2,PP1,PP2,round);
        }
        
        else if(PP1 > PP2)
        {
            push(P1,PP1);
            push(P1,PP2);
        }
        else
        {
            push(P2,PP2);
            push(P2,PP1);
        }
        
        round++;
//        cout << round << endl;
    }
    
    if(round == 5000)
    {
        cout << "Nobody wins." << endl;
    }
    // if P2 is empty
    else if (isEmpty(P2))
    {
        cout << "Player 1 wins after " << round << " battles." << endl;
    }
    // if P1 is empty
    else if(isEmpty(P1))
    {
        cout << "Player 2 wins after " << round << " battles." << endl;
    }
    
//kill them
    destroy (P1);
    destroy (P2);
    
}
// BANANA
