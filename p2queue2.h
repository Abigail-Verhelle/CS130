//#include <iostream>
//using namespace std;

const int SIZE = 5;

template <typename T>
struct Queue {
    T   data[SIZE];
    int head;
    int tail;
};

template <typename T>
void initialize(Queue<T>& q)
{

    //set everything to zero
    q.head = 0;
    q.tail = 0;
}

template <typename T>
void destroy(Queue<T>& q)
{

    // set everything to zero
    q.head = 0;
    q.tail = 0;
}

template <typename T>
int  getSize(Queue<T> q)
{
    
    //size?
    if (q.head == q.tail)
    {
        return 0;
    }
   else if(q.head < q.tail)
    {
        return (q.tail - q.head);
    }
    
    else
        return  (SIZE - q.head)+ q.tail;
    
}

template <typename T>
bool isEmpty(Queue<T> q)
{
    
    //same?
    return (q.head == q.tail);
    
}

template <typename T>
void push(Queue<T>& q, T number)
{

    q.data[q.tail] = number;
    
    q.tail++;
    
    if (q.tail >= SIZE)
    {
        q.tail = 0;
    }
   
    
}

template <typename T>
T    pop(Queue<T>& q)
{
    
    T value = q.data[q.head];
    q.head++;
    
    if (q.head >= SIZE)
    {
        q.head = 0;
    }
    
    return value;
    
}

//B-A-N-A-N-A BA-BANANA BA-BA-BANANA
