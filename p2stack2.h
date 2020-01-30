#include <cstddef>

template <typename T>
struct Node {
    T value;
    Node<T>* next;
};

template <typename T>
struct Stack {
    Node<T>* top;
};

template <typename T>
void initialize(Stack<T> & s)
{
    //set top to NULL
    s.top = NULL;
}

//go through and delete from begining
template <typename T>
void destroy(Stack<T>& s)
{
    //new node
    Node<T>* walker = s.top;
    
    // for loop for deleting
    while(s.top != NULL)
    {
        //poining to next node deleteing and reassigning top
        walker = walker -> next;
        delete s.top;
        s.top = walker;
        
    }
}

template <typename T>
bool isEmpty(Stack<T> s)
{
    // if top equals NULL then it is empty
    return(s.top == NULL);
}

template <typename T>
void push(Stack<T>& s,T number)
{
    //new node
    Node<T>* noo = new Node<T>;
    //set new to the value read in
    noo -> value = number;
    //assign noo's next value
    noo -> next = s.top;
    //move top
    s.top = noo;
    
}

template <typename T>
T    pop(Stack<T>& s)
{
    //new node
    Node<T>* popper = s.top;
    //reset top
    s.top = s.top -> next;
    //hold output
    T output = popper -> value;
    //delete node
    delete popper;
    
    return output;
}
//sorry about all the comments wanted to make sure I remembered what stuff does!! 🤗
// BANANA 🍌
