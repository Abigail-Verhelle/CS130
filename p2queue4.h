#include <cstddef>

template <class T>
struct Queue {
    T*  data;    // array of values
    int size;    // size of data array
    int head;    // index from which the next value will be read (on Pop)
    int tail;    // index at which the next value will be written (on Push)
};

template <class T>
void initialize(Queue<T> & line)
{
    //set to initial val
    line.size = 2;
    line.head = 0;
    line.tail = 0;
    
    //create array
     line.data = new T[line.size];
    
}

template <class T>
void destroy(Queue<T> & line)
{
    //set back to orinigal val
    line.size = 2;
    line.head = 0;
    line.tail = 0;
    
    //destory array ☠️
    delete [] line.data;
    line.data = NULL;

}

template <class T>
int  getSize(Queue<T> line)
{
    //size?
    if (line.head == line.tail)
    {
        //nothng in array
        return 0;
    }
    else if(line.head < line.tail)
    {
        //math to get size
        return line.size - (line.tail - line.head);
    }
    
    else
    {
        //more math to get size
        line.head - line.tail;
    }
}

template <class T>
bool isEmpty(Queue<T> line)
{
    //if head == tail there is nothing there
    return (line.head == line.tail);
}

template <class T>
void push(Queue<T> & line, T val)
{
    
    
    //full?
    if(line.tail + 1 == line.head || (line.head == 0 && line.tail + 1 == line.size))
    {
        //make new array
        T* rocks = new T[line.size*2];
        
        //copy full array
        for(int x = 0; line.head != line.tail; x++)
        {
            rocks[x] = line.data[line.head];
            line.head++;
            
            if(line.head == line.size)
            {
                //reseting
                line.head = 0;
            }
            
        }
        
        //resetting
        line.head = 0;
        line.tail = line.size - 1;
        
        //change size
        line.size *= 2;
        
        //delete everything
        delete[] line.data;
        
        //making data rocks
        line.data = rocks;
    }
    
    //putting in array
    line.data[line.tail] = val;
    line.tail++;
    
    //resetting
    if(line.tail == line.size)
    {
        line.tail = 0;
    }
    
}

template <class T>
T    pop(Queue<T> & line)
{
    T number;
    
    //setting val
    number = line.data[line.head];
    
    line.head++;
    
    //resetting
    if(line.head == line.size)
    {
        line.head = 0;
    }
    
    return number;
    
}

//Banana 🍌
