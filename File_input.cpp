#include <fstream>

int main()
{
     ifstream fin;
    string x = "filename.txt";
    string y = "filename.txt";
    
     fin.open(filename.c_str());
    
     if( fin.is_open() )
     {
         
     }
    
      fin.close();
    
    
    
    
    
    
    
    // example one
    
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
                //new member
                twoyears++;
                newmem++;
                
            }
        }
        
    }
    //you suck
    else
    {
        cout << "NOPE" << endl;
    }
    
    //close
    fin.close();

    
    
    
    
    
    // example two
    
    // open file
    fin.open("player1");
    // did it open?
    if( fin.is_open() )
    {
        // take in file info
        while(fin >> in)
        {
           
        }
        
    }
    //NOPE it didi not
    else
        cout << "you real dumb" << endl;
    // trash the fill
    fin.close();
}
