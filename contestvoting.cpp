#include <iostream>
#include <iomanip>
#include <fstream>
#include "p2map.h"
#include "p2queue.h"
#include "p2priorityqueue.h"
using namespace std;

int main()
{
    //declare
    ifstream fin;
    ofstream fout;
    string file1 = "";//file
    string file2 = "";//file
    int count = 0;
    float votes = 0;
    float acvotes = 0;
    float v = 0;
    float per = 0;
    int ncontestants = 0;
    int nvotes = 0;
    string con = "";
    int phone = 0;
    int c = 0;
    Map<string,int> M1;
    Map<int,int> M2;
    Queue <string> Q;
    PriorityQueue<string,int> PQ;
    
    
    //initialize data strctures
    initialize(M1);
    initialize(M2);
    initialize(Q);
    initialize(PQ);
    
    
    //file input
    cout << "Enter filename containing list of contestants: ";
    cin >> file1;
    
    cout << "Enter filename containing list of votes: ";
    cin >> file2;
    
    //open file one
    fin.open(file1.c_str());
    
    if( fin.is_open() )
    {
        //names input
        
        fin >> ncontestants;//number
        
        while (count < ncontestants)
        {
            fin >> con;//string
            assign(M1,con,0);
            
            push(Q,con);
            
            count++;
        }
        
      
    }
    
    //destroy!!!!
    fin.close();
    
    //open file 2
    fin.open(file2.c_str());
    
    if( fin.is_open() )
    {
        fin >> nvotes;//number
        
        while(votes < nvotes)
        {
            fin >> con;//string
            fin >> phone;//string
            
            //voted?
            if (! has_key(M2,phone))
            {
                assign(M2,phone,0);
            }
            
            // adding the votes
            if (lookup(M2,phone) < 4)
            {
                assign(M2,phone,lookup(M2,phone)+1);
                assign(M1,con,lookup(M1,con)+1);
                acvotes++;
                
            }
                
            votes++;
        }
    }
                
    //KILL IT!!!
    fin.close();
                

    cout << "Final rankings" << endl;
                
    //proierty queue and contestants and votes
    while (! isEmpty(Q))
    {
        con = pop(Q);
        push(PQ,con,lookup(M1,con));
    }

    //output
    while (! isEmpty(PQ))
    {
        //math to find percent
        con = pop(PQ);
        v = lookup(M1,con);
        per = v/acvotes;
        per = per*100;
                    
        //output
        cout << fixed;
        cout << setprecision(1) << per << "% " << con <<endl;
        
    }
          
    //DEATH
    destroy(M1);
    destroy(M2);
    destroy(Q);
    destroy(PQ);
    
                
}
