#include <iostream>
#include "p2stack.h"
using namespace std;
int main ()
{
    
    
    string input;
    Stack<char> symbol;
    bool good = true;

    initialize(symbol);
    
    //input
    cout << "Enter expression: ";
    cin >> input;
    
    // start checking for wellformed expression
    for(int x = 0; good && input[x] != 0;x++)
    {
        //check end
        if (input[x] == ']')
        {
            //Empty?
            if(isEmpty(symbol))
            {
                good = false;
            }
            //is it starting
            else if(pop(symbol) != '[')
            {
                good = false;
            }
        }
        
        //ending?
        else if (input[x] == ')')
        {
            //Empty
            if (isEmpty(symbol))
                good = false;
            
            //begginging?
            else if(pop(symbol) != '(')
            {
                good = false;
            }
        }
    //input
    else
        push(symbol, input[x]);
        
    }
    
    //is it empty
    if (! isEmpty(symbol))
    {
        good = false;
    }
    
    //output
    if (good)
    {
        cout <<"Expression " << input << " is well-formed." << endl;
    }
    
    else
    {
        cout << "Expression " << input <<  " is not well-formed." << endl;
    }
}
