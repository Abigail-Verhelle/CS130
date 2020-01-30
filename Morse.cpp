#include <iostream>
#include <sstream>
using namespace std;
int main()
{
    //declaration
    string moraphabet[26] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    string alphabet[26] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q" ,"R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
    
    string m;
    string e;
    string l;
    
    
    cout << "Enter  words, one per line: " << endl;
    getline(cin,m);
   
    while (m != "Quit")
    {
        stringstream ss(m);
        
        while(ss >> l)
        {
            //compares morse and letter
            for (int k = 0; k < 26; k++)
            {
                //adds to e
                if (l == moraphabet[k])
                {
                    e += alphabet[k];
                }
            }
        }
        //space
        e += " ";
        
        //new
        getline(cin, m);
        
    }
    
    cout << e << endl;
    
}

