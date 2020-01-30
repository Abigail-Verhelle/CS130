#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main ()
{
    ifstream fin;
    ofstream fout;
    string file;
    string newfile;
    string e[1000];
    string first;
    string last;
    string ID;
    int x = 0;
    string temp = "";
    
    //files
    cout << "Input file: ";
    cin >> file;
    
    cout << "Output file: ";
    cin >> newfile;
    
    //open
    fin.open(file.c_str());
    
    //open?
    if (fin.is_open())
    {
        
        
        while(fin >> first)
        {
            fin >> last;
            fin >> ID;
            
            e[x] = ID + " " + first + " " + last;
            x++;
            
        }
    }
    
    //file not opening
    
    else
    {
        cout << "You did do it correct!" << endl;
    }
    
    //close
    fin.close();
    
    // open second
    fout.open(newfile.c_str());
    
    if (fout.is_open())
    {
        //insertion sort
        for(int y = 1; y < x; y++ )
        {
            while (y > 0 && e[y] < e[y-1])
            {
                temp = e[y];
                e[y] = e[y-1];
                e[y-1] = temp;
                y--;
            }
        }
        
        for (int y = 0; y < x; y++)
        {
            fout << e[y] << endl;
        }
    }
    
    //didn't open
    else
    {
        cout << "Nope" << endl;
    }
    
    //close
    fout.close();
    
    
    
    
    
}
