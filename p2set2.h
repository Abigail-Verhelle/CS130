#include <cstddef>

template <typename T>
struct Set {
    T* data;
    int size;
    int count;
};

template <typename T>
void initialize(Set<T>& s)
{
    //set
    s.size = 2;
    s.count = 0;
    //make
    s.data = new T[s.size];
}

template <typename T>
void destroy(Set<T>& s)
{
    //set
    s.size = 2;
    s.count = 0;
    
    //delete
    delete [] s.data;
    s.data = NULL;
}

template <typename T>
bool isEmpty(Set<T> s)
{
    //empty?
    return (s.count == 0);
}

template <typename T>
void insert(Set<T>& s, T val)
{
    //create bool
    bool there = false;
    
    for(int i = 0; i < s.count; i++)
    {
        //is it there?
        if (s.data[i] == val)
        {
            there = true;
        }
        
    }
    
    //is the array full
    if (s.count == s.size && !there)
    {
        //double
        T* baby = new T[s.size*2];
        
        for(int x = 0; x <= s.size; x++)
        {
            //copy
            baby[x] = s.data[x];
        }
        
        //change the number for the variable
        s.size *= 2;
        
        //delete everything
        delete[] s.data;
        
        //make data and baby the same array
        s.data = baby;
    }
    
    if (!there)
    {
        //add value to array
        s.data[s.count] = val;
        s.count++;
    }
    
}

template <typename T>
bool contains(Set<T> s, T value)
{
    //is the varable there
    for (int y = 0; y < s.count; y++)
    {
        if (s.data[y] == value)
        {
            //yes!
            return true;
        }
        
    }
    //NO!!!
    return false;
}

template <typename T>
void remove(Set<T>& s, T number)
{
    for (int x = 0;x < s.count; x++)
    {
        //find value
        if (s.data[x] == number)
        {
            //remove
            s.data[x] = s.data[s.count-1];
            s.count --;
        }
    }
    
}

template <typename T>
int  getSize(Set<T> s)
{
    //size
    return s.count;
}

template <typename T>
Set<T> operator&&(Set<T> a ,Set<T> b)  // intersection
{
    Set<T> same;
    initialize (same);
    
    
    for(int j = 0;j <= b.count; j++)
    {
        if (contains(a,b.data[j]))
        {
            insert(same,b.data[j]);
            
            
        }
        
            
    }
    return same;
}


template <typename T>
Set<T> operator||(Set<T> a, Set<T> b)  // union
{
    
    Set<T> c;
    initialize(c);
    
    for (int n = 0; n < a.count;n++)
    {
        insert(c, a.data[n]);
    }
    
    for (int x = 0; x < b.count;x++)
    {
        if (!contains(a, b.data[x]))
        {
            insert(c, b.data[x]);
        }
    }
    
   
    return c;


}

template <typename T>
Set<T> operator-(Set<T> a,Set<T> b)   // difference
{
    Set<T> diff;
    initialize(diff);
    
    for (int y = 0; y < a.count;y++)
    {
        insert(diff, a.data[y]);
    }
    
    for (int x = 0; x < b.count;x++)
    {
        if (contains(a, b.data[x]))
        {
            remove(diff, b.data[x]);
        }
    }
    
    
    return diff;
}
