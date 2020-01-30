#include <iostream>
#include <fstream>
#include <string>
#include "p2map.h"
using namespace std;

int main()
{
    string f;
    string s;
    
    //make maps
    Map<string,string> Son;
    Map<string,string> Father;
    
    
    initialize(Son);
    initialize(Father);
    
    ifstream fin;
    string filename;
    
    //take in file
    cout << "File Input: ";
    cin >> filename;
    
    //open
    fin.open(filename.c_str());
    
    //open?
    if( fin.is_open() )
    {
        // Reads in the first "word"👍🏻
        while(fin >> f)
        {
            fin >> s;
            
            assign(Son,s,f);
            assign(Father,f,s);
            //which one is father?
            
        }
    }
    
    //close file
    fin.close();
    
    ofstream fout;
    
    //make newstring for file
    string filetwo = "fixed_" + filename;
    
    //Open
    fout.open(filetwo.c_str());
    
    string Name = s;
    
    //find key and follow key to last one(son without a kid)
    while(has_key(Son,Name))
    {
        Name = lookup(Son,Name);
    }
    
    //open?
    if( fout.is_open() )
    {
        //take key and prit key and lookup
        while(has_key(Father,Name))
        {
            fout << Name << " " << lookup(Father,Name) << endl;
            //reset name
            Name = lookup(Father,Name);
        }
        
    }
    //close file
    fout.close();
    
    cout << "Ordering complete." << endl;
}
