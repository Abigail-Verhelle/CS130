#include <cstddef>

template <typename T>
struct Node {
    T data;         // Data held at this node in tree
    Node<T>* left;  // Pointer to left child
    Node<T>* right; // Pointer to right child
};

template <typename T>
struct Tree {
    Node<T>* root; // Pointer to topmost (root) node
};

template <typename T>
void initialize(Tree<T> &t)
{
    t.root = NULL;
}

// This is the recursive destroy function, accepting a Node* argument.
template <typename T>
void destroy(Node<T>* n)
{
    if( n == NULL )
        return;
    
    destroy(n->left);  // Recursively destroy left subtree
    destroy(n->right); // Recursively destroy right subtree
    delete n;          // Delete this node
}

// This is the function called by the user, to destroy a Tree.
// It will call the recursive function, beginning with the root node.
template <typename T>
void destroy(Tree<T> &t)
{
    destroy(t.root);
    t.root = NULL;
}

template <typename T>
void insert(Tree<T> &t, T value)
{
    // Create new node to add to the tree
    Node<T>* newNode = new Node<T>;
    newNode->data  = value;
    newNode->left  = NULL;
    newNode->right = NULL;
    
    if( t.root == NULL ) { // empty tree
        t.root = newNode;
        return;
    }
    
    Node<T>* walker = t.root;
    while( true )
    {
        if( walker->data > value )
        {
            if( walker->left == NULL )
            {
                walker->left = newNode;
                return;
            }
            else
                walker = walker->left;
        }
        else // walker->data < value
        {
            if( walker->right == NULL )
            {
                walker->right = newNode;
                return;
            }
            else
                walker = walker->right;
        }
    }
}

// Return depth (level) at which value appears
//    or 0 if value is not in tree
template <typename T>
int contains(Tree<T> &t, T value)
{
    Node<T>* walker = t.root;
    int depth = 1;
    
    while( walker != NULL )
    {
        if( walker->data == value )
            return depth;
        else if( walker->data > value )
            walker = walker->left;
        else // walker->data < value
            walker = walker->right;
        depth++;
    }
    return 0;
}



//////////recursion
template <typename T>
int  countNodes(Tree<T> &t)
{
    return countNodes(t.root);
}

template <typename T>
// implement these functions
int  countNodes(Node<T>* walker )
{
    
    if(walker == NULL)
    {
        return 0;
    }
    
    return countNodes(walker -> left) + countNodes(walker -> right) + 1;
    
}

//recursion
template <typename T>
int height (Tree<T> &t)
{
    return height(t.root);
}

template <typename T>
int  height(Node<T>* walker)
{
    // empty?
   if(walker == NULL)
   {
       return 0;
   }
    
    //recurtion to find leftand right hieght
    int lefthieght = height(walker -> left);
    int righthieght = height(walker -> right);
    
    
    //left bigger?
    if(lefthieght >= righthieght)
    {
        
        return lefthieght + 1;
        
    }
    
    // right bigger
    else
    {
        
        return righthieght + 1;
        
    }
    
}

//recursion
template <typename T>
int  countLeaf(Tree<T> t)
{
    
    return countLeaf(t.root);
    
}

template <typename T>
int  countLeaf(Node<T>* walker)
{
    
    //Empty?
    if(walker == NULL)
    {
        
        return 0;
        
    }
    
    //if there is only the root there
    if(walker -> left == NULL && walker -> right == NULL)
    {
        
        return 1;
        
    }
    
    //return left and right count added together
    return countLeaf(walker -> left) + countLeaf(walker -> right);
    
}

//recursion
template <typename T>
int  countDouble(Tree<T> t)
{
    return countDouble(t.root);
}

template <typename T>
int  countDouble(Node<T>* walker)
{
    
    //Empty?
    if(walker == NULL)
    {
        return 0;
    }
    
    //if there is just a root
    if(walker -> left == NULL && walker -> right == NULL)
    {
        
        return 0;
        
    }
    
    // counts and returns sum
    if(walker -> left != NULL && walker -> right != NULL)
    {
        
        return 1 + countDouble(walker -> left) + countDouble(walker -> right);
        
    }
    
    
    return countDouble(walker -> left) + countDouble(walker -> right);
    
}

//recursion
template <typename T>
T    kthValue(Tree<T> t, int k)
{
    return kthValue(t.root,k);
}

template <typename T>
T    kthValue(Node<T>* walker , int k)
{
    
    int value = countNodes(walker -> left) + 1;
    
    //root?
    if(value == k)
    {
        
        return walker -> data;
        
    }
    
    // if left
    if(k < value)
    {
        
        return kthValue(walker -> left,k);
        
    }
    
    // if right
    else
    {
        
        return kthValue(walker -> right,k - value);
        
    }
}
