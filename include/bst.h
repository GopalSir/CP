#ifndef _BST
#define _BST
#include <iostream>
template <typename T>
class Node{
    public :
    T data;
    Node *left;
    Node *right;

   

    
    // bool operator<(T &rhs);
    Node(T temp);
     Node();
};

template <typename T>
class BST{
   

public:
     Node<T> *root;
    BST();
     BST(T temp_data);
     BST(Node<T> *temp_node);
    BST(Node<T> &temp_node);
    // //either pass node data
    //create temp node and pass it to other function
    void insert(T temp_data);

    //either pass Pointer to entire node
    void insert(Node<T> *temp_node);

    // //either pass Referenec to entire node
    // void insert(Node<T> &temp_node);

     void preorder(Node<T> *tstart);
    // void inorder();
    // void postorder();
};



template<typename T> Node<T>::Node(T temp):data{temp}
{
    std::cout<<"Calling T arg Node constructor \n";
 
 left = nullptr;
 right = nullptr;
}

template<typename T> Node<T>::Node()
{
    std::cout<<"Calling NO ARG Node constructor \n";
    data = T();
    left = nullptr;
    right = nullptr;
}

// template <typename T> bool Node<T>::operator<( T &rhs)
// {
//     std::cout<<"Calling Parametric Node constructor \n";
//     if(this->data <= rhs->data)
//     return true;
//     return false;
// }

//no arg constructor of BST
template <typename T> BST<T>::BST()
{    
    std::cout<<"Calling T NO ARG BST constructor \n";
 root = new Node<T>();
}

template <typename T> BST<T>::BST(T temp_data)
{
 std::cout<<"Calling T arg BST constructor \n";
 root = new Node<T>(temp_data);
}

//reference constructor constructor
template <typename T> BST<T>::BST(Node<T> &temp_node)
{
 std::cout<<"Calling NODE REFERENCE ARG BST constructor \n";
 root = &temp_node;
}

template <typename T> BST<T>::BST(Node<T> *temp_node)
{
 std::cout<<"Calling NODE POINTER ARG BST constructor \n";
 root = temp_node;
}



template<typename T> void BST<T>::insert(T temp_data)
{
 //create new node ourselves which will be pointed at hehe
 Node<T> *ins_node = new Node<T>(temp_data);

 insert(ins_node);

 ins_node = nullptr;
 delete ins_node;
}

template<typename T> void BST<T>::insert(Node<T> *ins_node)
{
  //create two node pointers for traversal . 
  Node<T> *y = nullptr;
  Node<T> *x = root;

  while(x != nullptr)
  {
     y = x;
     if(ins_node->data < x->data)
        x = x->left;
     else
        x = x->right;
  }

  if(y == nullptr)
    root = ins_node;
    else if(ins_node->data < y->data)
    {
      y->left = ins_node;
    }
    else
    {
      y->right = ins_node;
    }

  y = nullptr;
  x = nullptr;

  delete y;
  delete x;
 
}

template<typename T> void BST<T>::preorder(Node<T> *tstart)
{
    if(tstart != nullptr)
    {
        preorder(tstart->left);
        std::cout<<tstart->data<<" ";
        preorder(tstart->right);
    }
    tstart = nullptr;
    delete tstart;
}



#endif //_BST