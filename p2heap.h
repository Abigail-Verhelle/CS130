#include <cstddef>

const int HEAPSIZE = 128;

template <typename T>
struct Heap {
    T  data[HEAPSIZE];
    int size;
};

template <typename T>
void initialize(Heap<T>& cash)
{
    
    // set size to zero
    cash.size = 0;
    
}

template <typename T>
void destroy(Heap<T>& cash)
{
    
    // set size to zero
    cash.size = 0;
    
}

template <typename T>
void put(Heap<T>& cash,T note )
{
    
    cash.size++;
    
    //add new value
    int index = cash.size;
    cash.data[index] = note;
    
    //put it int he right place
    while(index != 1 && note < cash.data[index/2] )
    {
        T change = cash.data[index/2];
        cash.data[index/2] = note;
        cash.data[index] = change;
        
        index = index/2;
    }
}

template <typename T>
T    get(Heap<T>& cash)
{
    
    //where to look variable and what you are looking at.
    int m = 1;
    T place;
    
    //what is on top?
    T topstack = cash.data[1];
    
    // find what to move and move it and decrease size
    T sinker = cash.data[cash.size];
    cash.data[1] = sinker;
    cash.size--;
    
    //while loop to put heep in write order
    while(m * 2 < cash.size && (sinker > cash.data[m * 2] || sinker > cash.data[(m * 2) + 1]))
    {
        
        //comparing left and right nodes
        // if right is bigger
        if(cash.data[m * 2] < cash.data[(m * 2) + 1] && m * 2 < cash.size)
        {
            //sinking sinker
            place = cash.data[m * 2];
            cash.data[m * 2] = sinker;
            cash.data[m] = place;
            
            //cahnge m
            m = m * 2;
            
        }
        
        //if left is bigger
        else if(cash.data[m * 2] > cash.data[(m * 2) + 1] && m * 2 < cash.size)
        {
            
            //sink the sinker
            place = cash.data[(m * 2) + 1];
            cash.data[(m * 2) + 1] = sinker;
            cash.data[m] = place;
            
            //change m
            m = (m * 2) + 1;
            
        }
        
    }
    
    return topstack;
    
    
}

template <typename T>
bool isEmpty(Heap<T> cash)
{
    // set size to zero
    return cash.size == 0;
}
