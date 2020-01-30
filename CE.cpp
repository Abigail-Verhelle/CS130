#include <iostream>
#include <fstream>
#include <string>
#include "p2priorityqueue.h"
using namespace std;
int main()
{
    //declare file and PQ
    ifstream fin;
    ofstream fout;
    PriorityQueue<string, int> CS332;
    PriorityQueue<string,int> CS352;
    PriorityQueue<string,int> CS365;
    string filename;
    //declare variables
    string classname;
    string id;
    int important;
    string x = "CS332";
    string y = "CS352";
    string z = "CS365";
    
    cout << "Input filename: ";
    cin >> filename;
    
    //open
    initialize(CS332);
    initialize(CS352);
    initialize(CS365);
    
    
    fin.open(filename.c_str());
    
    if( fin.is_open() )
    {
        //getting input from file
        while (fin >> classname)
        {
            fin >> id;
            fin >> important;
            
            //putting data into queues
            if(classname == "CS332")
            {
                push(CS332,id,important);
            }
            if (classname == "CS352")
            {
                push(CS352,id,important);
            }
            if (classname == "CS365")
            {
                push(CS365,id,important);
            }
        }
    }
    
    //coded it wrong
    else
    {
        cout << "did not open" << endl;
    }
    
    //close file
        fin.close();
    //open cs332
        fout.open(x.c_str());
    
    
    //output CS332
        if( fout.is_open() )
        {
            while (!isEmpty(CS332))
            {
                fout << pop(CS332) << endl;
            }
            
        }
    // nope
        else
        {
            fout << "did not open" << endl;
        }
    //close
        fout.close();
    
    //output for CS352 and open
        fout.open(y.c_str());
    
        if( fout.is_open() )
        {
            while(!isEmpty(CS352))
            {
                fout << pop(CS352) << endl;;
            }
        }
    //nope
        else
        {
            cout << "did not open" << endl;
        }
    //close
        fout.close();
    
    //outout for cs365 and open
        fout.open(z.c_str());
    
        if( fout.is_open() )
        {
            while(!isEmpty(CS365))
            {
                fout << pop(CS365) << endl;
            }
        }
    //nope
        else
        {
            cout << "did not open" << endl;
        }
    //close
        fout.close();
    
    //killing them
    destroy(CS332);
    destroy(CS352);
    destroy(CS365);
}

