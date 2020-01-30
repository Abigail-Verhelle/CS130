#include <iostream>
#include <sstream>
using namespace std;
int absolute(int number)
{
    number = number * -1;
    return number;
}
int main()
{
    //delcaring
    string list = "";
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int diff[50] = {0};
    int size = 0;
    int missing = -1;
    int x = 0;
    
    //input
    cout << "Enter list:  ";
    getline(cin,list);
    stringstream ss(list);
    
    ss >> num1;

    // finding difference and putting it in Diff array
   while (ss >> num2)
    {
        
        num3 = num2 - num1;
        
        if (num3 < 1)
        {
            num3 = absolute(num3);
        }
        
        diff[num3] = num3;
        num1 = num2;
        size++;
        
    }
    
    //if something is missing
    for (x = 1; x <= size;x++)
    {
        
        if(diff[x] == 0 && missing == -1)
        {
            
            
            
                missing = x;
            
        }
     
        
        
    }
    
    //output
    if (missing == -1 )
    {
        cout << "Good sequence." << endl;
    }
    
    else
    {
        cout << "Bad sequence: missing " << missing << "." << endl;
    }

   
}
            
            
        
    

    
