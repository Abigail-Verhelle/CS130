#include <iostream>
#include <fstream>
#include "p2queue.h"
using namespace std;

int strgtonum (string A)
{
    
    if (A == "A")
    {
        return 14;
    }
    
    if (A == "10")
    {
        return 10;
    }
    
    if (A == "J")
    {
        return 11;
    }
    
    if (A == "Q")
    {
        return 12;
    }
    
    if (A == "K")
    {
        return 13;
    }
    
    return (int)(A[0] - 48);
    
}

void war (Queue<int>& P1, Queue<int>& P2, int& PP1, int& PP2, int& round)
{
    Queue<int> hostages;
    initialize (hostages);
    
    Queue<int> captives;
    initialize (captives);
    
    while (PP1 == PP2)
    {
        push(hostages,PP1);
        push(captives,PP2);
        
        for (int i = 0; i < 3; i++)
        {
            if (!isEmpty(P1))
            {
                push(hostages,pop(P1));
            }
            
            if (!isEmpty(P2))
            {
                push(captives,pop(P2));
            }
        }
        
        if (!isEmpty(P1) && !isEmpty(P2))
        {
            round++;
        }
        
        PP1 = 0;
        PP2 = 0;
        
        if (!isEmpty(P1))
        {
            PP1 = pop(P1);
        }
        
        if (!isEmpty(P2))
        {
            PP2 = pop(P2);
        }
        
        if (PP1 > PP2 || isEmpty(P2))
        {
            
            while (!isEmpty(hostages))
            {
                push(P1,pop(hostages));
            }
            
            push(P1,PP1);
            
            while (!isEmpty(captives))
            {
                push(P1,pop(captives));
            }
            
            push(P1,PP2);
        }
        
        else if (PP2 > PP1 || isEmpty(P1))
        {
           
            while (!isEmpty(captives))
            {
                push(P2,pop(captives));
            }
            
            push(P2,PP2);
            
            while (!isEmpty(hostages))
            {
                push(P2,pop(hostages));
            }
            
            push(P2,PP1);
            
        }
        
    }
    destroy (hostages);
    destroy (captives);
}




int main ()
{
    
    ifstream fin;
    ofstream fout;
    
    
    string cards;
    int round = 0;
    
    
    Queue<int> P1;
    initialize (P1);

    
    Queue<int> P2;
    initialize (P2);
    
    
    fin.open("player1");
    
    if ( fin.is_open() )
    {
        
        while (fin >> cards)
        {
            push(P1, strgtonum(cards));
        }
        
    }
    
    else
        cout << "NOPE. Try Again";
    
    fin.close();
    
    
    fin.open("player2");
    
    if ( fin.is_open() )
    {
        while (fin >> cards)
        {
            push(P2, strgtonum(cards));
        }
        
    }
    else cout << "NOPE. Trace your code";
    
    fin.close();
    
    while (round < 5000 && !isEmpty(P1) && !isEmpty(P2))
    {
        int PP1 = 0;
        int PP2 = 0;
        
        if (!isEmpty(P1))
        {
            PP1 = pop(P1);
        }
        
        if (!isEmpty (P2))
        {
            PP2 = pop(P2);
        }
        
        if (PP1 == PP2)
        {
            war(P1,P2,PP1,PP2,round);
        }
       
        else if (PP1 > PP2)
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
    }
    
    if (round == 5000)
    {
        cout << "Nobody wins.";
    }
    
    else if (isEmpty(P2))
    {
        cout << "Player 1 wins after " << round << " battles.";
    }
    
    else if (isEmpty(P1))
    {
        cout << "Player 2 wins after " << round << " battles.";
    }
    
    //burn it all
    destroy (P1);
    destroy (P2);
    
}
