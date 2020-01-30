 #include<cstddef> // includes NULL definition

template <class T>
struct Stack {
    T*  data;    // array of values
    int size;    // size of array
    int top;    // index of value currently at top of Stack
};


template <class T>
void initialize(Stack<T>& tables)
{
    //set everything to bases numbers
    tables.size = 2;
    tables.top = 0;
    
    tables.data = new T[tables.size];
}


template <class T>
void destroy(Stack<T>& tables)
{
    
    //set everything back initial values
    tables.size = 2;
    tables.top = 0;
    
    delete [] tables.data;
    tables.data = NULL;
}


template <class T>
bool isEmpty(Stack<T> tables)
{
    //if it 0?
    return(tables.top == 0);
        
}


template <class T>
void push(Stack<T>& tables,T number)
{
    //full?
    if(tables.size == tables.top)
    {
        //make new array
        T* chairs = new T[tables.size*2];
        
        //copy full array
        for(int x = 0; x < tables.size; x++)
        {
            chairs[x] = tables.data[x];
        }
        
        //change size
        tables.size *= 2;
        
        //delete everything
        delete[] tables.data;
        
        tables.data = chairs;
    }
  
    tables.data[tables.top] = number;
    tables.top++;
}


template <class T>
T    pop(Stack<T>& tables)
{
    //make value
    T value;
    
    value = tables.data[tables.top-1];
    
    //move top
    tables.top--;
    
    return value;
}
