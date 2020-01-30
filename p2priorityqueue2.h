#include <cstddef>

template <typename V, typename R>
struct Node {
    V value;
    R priority;
    Node<V,R>* next;
    Node<V,R>* prev;
};

template <typename V, typename R>
struct PriorityQueue {
    Node<V,R>* head;
};


template <typename V, typename R>
void initialize(PriorityQueue<V,R>& PQ) //NULL?
{
    PQ.head = NULL;
}


template <typename V, typename R>
void destroy(PriorityQueue<V,R>& PQ)
{
    //Make a "Walker" var
    Node<V,R>* looking = PQ.head;
    
    //looking
    while (PQ.head != NULL)
    {
        looking = looking -> next;
        delete PQ.head;
        PQ.head = looking;
    }
}

//Empty?
template <typename V, typename R>
bool isEmpty(PriorityQueue<V,R> PQ) // check if any PQ left
{
    return (PQ.head == 0);
}



template <typename V, typename R>
void push(PriorityQueue<V,R>& PQ,V val,R num) //push in a new ducky
{
    //new node
    Node<V,R>* noo = new Node<V,R>;
    noo -> value = val;
    noo -> priority = num;
    
    
    if (PQ.head == NULL) //empty
    {
        
        PQ.head = noo;
        noo -> next = noo;
        noo -> prev = noo;
    }
    
    
    // single item list
    else if (PQ.head -> next == PQ.head)
    {
        
        PQ.head -> next = noo;
        PQ.head -> prev = noo;
        noo -> next = PQ.head;
        noo -> prev = PQ.head;
        
        //larger?
        if (num > PQ.head -> priority)
        {
            PQ.head = noo;
        }
    }
    
    
    // multiple item
    else
    {
      //new node
        Node<V,R>* looking = PQ.head;
        
        
        while (looking -> priority >= num && looking -> next != PQ.head)
        {
            looking = looking -> next;
        }
        
        if (num <= looking -> priority) //attach to end of list and attach to begining
        {
            noo -> next = PQ.head;
            noo -> prev = PQ.head -> prev;
            PQ.head -> prev -> next = noo;
            PQ.head -> prev = noo;
            
        }
        else
        {
            //create new node
            Node<V,R>* beginning = looking -> prev;
            
            looking -> prev = noo;
            beginning -> next = noo;
            noo -> next = looking;
            noo -> prev = beginning;
            
            if (PQ.head -> priority < num)
            {
                PQ.head = noo;
            }
        }
    }
}


template <typename V, typename R>
V    pop(PriorityQueue<V,R>& PQ)
{
    //save new
    V val;
    val = PQ.head -> value;
    
    // new pointer
    Node<V,R>* del = PQ.head;
    
    if (del -> next == del)
    {
        PQ.head = NULL;
    }
    else
    {
        PQ.head = del -> next;
        PQ.head -> prev = del -> prev;
        del -> prev -> next = PQ.head;
    }
    
    //delete
    delete del;
    
    return val;
}
//Banana
