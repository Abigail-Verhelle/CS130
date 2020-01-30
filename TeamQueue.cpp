#include <iostream>
#include <sstream>
#include <fstream>
#include "p2priorityqueue.h"
#include "p2map.h"
using namespace std;
int main ()
{
    
    //declare everything
    ifstream fin;
    ofstream fout;
    
    int size = 0;
    string teammem, teammems, input, trash;
    int order = -1;
    int count = 0;
    
   
    Map <string,int> teams;
    initialize(teams);
    
    Map <int,int> sorted;
    initialize(sorted);
    
    PriorityQueue <string,int> line;
    initialize(line);
    
    
    fin.open("teams");
    
    //open?
    if(fin.is_open())
    {
        
        //gets size
        fin >> size;
        
        //takes trash out
        getline(fin,trash);
        
        for(int j = 1; j <= size; j++)
        {
            
            getline(fin,teammems);
            stringstream ss(teammems);
            
            //loop to put names into the teams
            while (ss >> input)
            {
                
                assign(teams,input,j);
                
            }
            
        }
        
    }
    
    else
    {
        
        cout << "NOPE!!!!!!!!" << endl;
        
    }
    
    //close
    fin.close();
    
    
    cout << "Enter names in order of arrival: " << cout;
    cin >> input;
    
    //ordering
    while(input != "END")
    {
        
        //assigned?
        if(!has_key(sorted,lookup(teams,input)))
        {
            
            assign(sorted,lookup(teams,input),order);
            order--;
            
        }
        
        //pushing in input
        push(line,input,lookup(sorted,lookup(teams,input)));
        
        cin >> input;
        
    }
    
    
    //new file!!!!
    fout.open("grouped");
    
    //open?
    if(fout.is_open())
    {
        
        //push?
        while(!isEmpty(line))
        {
            
            fout << pop(line) << endl;
            
        }
        
    }
    
    else
    {
        
        cout << "Unable to open file\n";
    
    }
    
    //close and kill the MAPS and PQ
    fout.close();
    destroy(teams);
    destroy(sorted);
    destroy(line);
    
}

//BANANA
