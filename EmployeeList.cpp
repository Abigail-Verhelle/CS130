#include <iostream>
#include <fstream>
//#include <string>
#include <sstream>
using namespace std;

int main()
{
    // Create input stream using file
    ifstream fin;
    ofstream fout;
    string infilename;
    string outfilename;
    string a[1000];
    string b[1000];
    string firstname;
    string lastname;
    string id;
    int p = 0;
    string temp = "";
    
    //find files
    cout << "Input File: ";
    cin >> infilename;
    
    cout << "Output file: ";
    cin >> outfilename;
    
    // Open file
    fin.open(infilename.c_str());
    
    //if input open
    if( fin.is_open() )
    {
        while(fin >> firstname)
        {
            fin >> lastname;
            fin >> id;
            a[p] = /*id + " " + */firstname + " " + lastname;
            b[p] = (id);
            p++;
            
            // check
            //for (int u = 0; a[u]!= "0"; u++)
            //{
                //cout << a[u] << endl;
           // }
            
            //a[x] = b;
        
            
        }
    }
    
    else
    {
        cout << " It didn't work!";
    }
    
    //close file
    fin.close();
    
    
    
    // Open output file
    fout.open("output.txt");
    
    if( fout.is_open() )
    {

        
        /*for (int y = 1;y < p; y++)
        {
            while(y > 0 && a[y] < a[y-1])
            {
                temp  = a[y];
                a[y] = a[y - 1];
                a[y] =  temp;
                y--;
            }
        }*/
        
        string lowest = b[0]; // b is id array
        string finalArray [1000];
        int index = 0;
        
        for(int j = 0; j < p; j++)
        {
            lowest = b[j];
            for (int i = j; i < p; i++)
            {
                if (b[i] < lowest)
                {
                    lowest = b[i];
                    index = i;
                }
            }
            //tostring(b[i])
            finalArray[j] = b[j] + " " +  a[i];
        
        for(int l = 0; l < p; l++)
        {
            fout << finalArray[l] << endl;
    
        }
        }
    }
    
    // If file didn't open successfully, notify user
    else
    {
        cout << "Unable to open file\n";
    }
    
    fout.close();
    
    
    

    
    
    // Close input stream when finished reading from it
    fin.close();
}
