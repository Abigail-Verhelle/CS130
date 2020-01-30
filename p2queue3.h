#include "p2stack.h"

template <typename T>
struct Queue {
    Stack<T> s1;
    Stack<T> s2;
};

template <typename T>
void initialize(Queue<T>& logs);
{
    initialize(logs.s1);
    initialize(logs.s1);
}

template <typename T>
void destroy(Queue<T>& logs);
{
    destroy(logs.s1);
    destroy(logs.s2);

}

template <typename T>
int  getSize(Queue<T> logs);
{
    return getSize(logs.s1);
}

template <typename T>
bool isEmpty(Queue<T> logs);
{
    return isEmpty(logs.s1);
}

template <typename T>
void push(Queue<T>& logs, T val);
{
    push(logs.s1,val);
}

template <typename T>
T    pop(Queue<T>& logs);
{
    while (! isEmpty(logs.s1))
    {
        val = pop(logs.s1);
        push(logs.s2,val);
    }
    
    return val;
}
