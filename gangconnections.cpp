#include <iostream>
#include <fstream>
#include <string>
#include "p2graph.h"
using namespace std;
int main()
{
    
    // declare
    ifstream fin;
    
    int flys1 = 0;
    char relation;
    int flys2 = 0;
    char trash;
    
    Graph<int> spiderwebb;
    initialize(spiderwebb);
    
// open?
    fin.open("connections");
    
    if( fin.is_open() )
    {
        //input
        while (fin >> flys1 >> relation >> flys2)
        {
            //create vertext
            addVertex(spiderwebb,flys1);
            addVertex(spiderwebb,flys2);
            
            //create relation
            if(relation == 'o')
            {
                //add edge
                addEdge(spiderwebb, flys1, flys2, 2);
                
            }
            
            else
            {
                //add edge
                addEdge(spiderwebb, flys1, flys2, 1);
                
            }
        
        }
        
    }
    
    //if file did not open
    else
    {
        cout << "NOPE!!!" << endl;
    }
    
    cout << "File read." << endl;
    
    //close
    fin.close();
    
    cout << "What connection do you want to search?" << endl << endl;
    //take in what you are looking for
    cin >> trash >> flys1 >> flys2;


    //if vertex exist
    if ( hasVertex(spiderwebb,flys1) && hasVertex(spiderwebb,flys2) )
    {
        //find shortest path
        int path = shortestPath(spiderwebb,flys1,flys2);

        //if path does not connect
        if(path == 0)
        {
            
            cout << "Connection unknown" << endl;
            
        }
        
        //if the shortest value is even
        else if(path % 2 == 0)
        {

            cout << "Members of the same gang" << endl;
            
        }
        
        //if the path is odd
        else if(path % 2 == 1)
        {

            cout << "Members of different gangs" << endl;
            
        }
        
        
    }
    
    //if the number input do not exist
    else
    {
        cout << "did not enter if " << endl;
        cout << "Connection unknown" << endl;
    }
    
    //kill the graph
    destroy (spiderwebb);
    
    //last program!!!!!!!
    //BANANAS

}
