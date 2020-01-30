#include <cstddef>

template <typename K, typename V>
struct Node {
    K key;
    V value;
    Node<K,V>* next;
};

template <typename K, typename V>
struct Map {
    Node<K,V>** table;
    int size;
};


template <typename K, typename V>
void initialize(Map<K,V>& marbles, int number)
{
    
    marbles.size = number;
    
    marbles.table = new Node<K,V> *[marbles.size];
    
    // a loop that sets the pointers to null
    for(int x = 0; x < number; x++)
    {
        
        marbles.table[x] = NULL;
        
    }
    
}

template <typename K, typename V>
void destroy(Map<K,V>& marbles)
{
    for(int y = 0; y < marbles.size; y++)
    {
        
        //create and set pointers
        Node<K,V>* walker = marbles.table[y];
        Node<K,V>* delwalker = marbles.table[y];
        delwalker = marbles.table[y];
        walker = delwalker;
        
        //loop to delete nodes
        while(delwalker != NULL)
        {
            
            walker = delwalker -> next;
             delete delwalker;
            delwalker = walker;
            
        }
       
    }
    
    //delete the table
    delete [] marbles.table;
    marbles.table = NULL;
    marbles.size = 0;
   
}

template <typename K, typename V>
void assign(Map<K,V>& marbles,K newkey,V val)
{
    
    //new pointer
    Node<K,V>* walker = marbles.table[newkey % marbles.size];
    Node<K,V>* walk = marbles.table[newkey % marbles.size];
    
    int down = 1;
    
    //when there is a node
    while(walker != NULL)
    {
        
        //key right? then reset the value
        if(walker -> key == newkey)
        {
            
            walker -> value = val;
            return;
            
        }
        
        //move pointers
        walk = walker;
        walker = walker -> next;
        down++;
        
    }
    
    //new node
    Node<K,V>* blue = new Node<K,V>;
    blue -> key = newkey;
    blue -> value = val;
    blue -> next = NULL;
    
    //if no node
    if(down == 1)
    {
        
        marbles.table[newkey % marbles.size] = blue;
        return;
        
    }
    
    //move walk
    walk -> next = blue;

}

template <typename K, typename V>
void remove(Map<K,V>& marbles,K newkey)
{
    //new pointer
    Node<K,V>* walker = marbles.table[newkey % marbles.size];
    Node<K,V>* walker2 = marbles.table[newkey % marbles.size];
    
    int down = 1;
    
    //loop through to find what to delele
    while( walker != NULL)
    {
        
        //how to know what to delete
        if(walker -> key == newkey)
        {
            
            //if just one
            if(down == 1)
            {
                
                
                marbles.table[newkey % marbles.size] = walker -> next;
                delete walker;
                
                return;

            }
            
            //end?
            else if(walker -> next == NULL)
            {
                
                walker2 -> next = NULL;
                delete walker;
                
                return;
                
            }

        }
        
        //moving walker b/c key does not match
        else
        {
            
            walker2 = walker;
            walker = walker -> next;
            down++;
            
        }
        
    }
    
}

template <typename K, typename V>
bool has_key(Map<K,V>& marbles,K newkey)
{
   
    //new pointer
    Node<K,V>* walker = marbles.table[newkey % marbles.size];
    
    //nothing there
    if(walker == NULL)
    {
        
        return false;
        
    }
    
    //YES they match
    else if(walker -> key == newkey)
    {
        
        return true;
        
    }
    
    //more than one node
    while(walker != NULL)
    {
        
       if(walker -> key == newkey)
       {
           
           return true;
           
       }
        
        walker = walker -> next;
        
    }
    
    return false;
    
}
    
template <typename K, typename V>
V    lookup(Map<K,V>& marbles,K noo)
{
    
    //new pointer
     Node<K,V>* walker = marbles.table[noo % marbles.size];
    
    //looping through
    while(walker -> next != NULL)
    {
        
        //matchs?
        if(walker -> key == noo)
        {
            
            return walker -> value;
            
        }
        
        //move
        walker = walker -> next;
        
    }
    
    return walker -> value;
    
}


//hashes
int hash(int key, int size)
{
    
    return key % size;
    
}

int hash(char key, int size)
{
    
    return key % size;
    
}




