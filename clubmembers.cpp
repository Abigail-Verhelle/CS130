#include <iostream>
#include <fstream>
#include "p2set.h"
using namespace std;
int main()
{
    //declare variables
    ifstream fin;
    string old = "8A_past.txt";
    string newf = "8A_new.txt";
    string trash;
    string name;
    int oldvalue;
    int newvalue;
    int twoyears = 0;
    int oldmem = 0;
    int newmem = 0;
    
    //create set
    Set<string> members;
    initialize(members);

    
    fin.open(old.c_str());
    
    //is open ⁉️
    if( fin.is_open() )
    {
        fin >> trash;
        fin >> trash;
        fin >> oldvalue;
        
        getline(fin,trash);
        
        //get names
        for(int x = 0; x < oldvalue; x++)
        {
            getline(fin,name);
            insert(members,name);
            twoyears++;
        }
        
    }
    //you suck ☠️
    else
    {
        cout << "NOPE" << endl;
    }
    //close ❌
    fin.close();
    
    
    fin.open(newf.c_str());
    
    //open?
    if( fin.is_open() )
    {
        fin >> trash;
        fin >> trash;
        fin >> newvalue;
        
        getline(fin,trash);
        
        //get list
        for (int y = 0; y < newvalue; y++)
        {
            getline(fin,name);
            if(contains(members,name))
            {
                //old?
                oldmem++;
                
            }
            else
            {
                //new member 🤗
                twoyears++;
                newmem++;
                
            }
        }
        
    }
    //you suck 🆘
    else
    {
        cout << "NOPE" << endl;
    }
    
    //close
    fin.close();
    
    //Math 💹
    int totalold = oldmem * 62;
    int totalnew = newmem * 80;
    
    //Output
    cout << "Old Member Dues: $" << totalold << endl;
    cout << "New Member Dues: $" << totalnew << endl;
    cout << "Total expected:  $" << totalold + totalnew << endl;
    
    cout << endl;
    
    cout << "Two-year membership: " << twoyears << endl;
    
}

//BANANA  🍌
