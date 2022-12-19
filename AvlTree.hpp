#pragma once
#include <iostream>

using namespace std;

class node
{
    public:
        int _value;
        int _height;
        int _balance;
        node* _parent;
        node* _right;
        node* _left;

        node() {};

        node(int value, int height, node* parent, node* right, node* left) : _value(value), _parent(parent), _height(height), _right(right), _left(left)
        {
        }
};

class AvlTree
{
    private:   
        node* _root;
        int   _size;

        void LeftRotate(node* Node)
        {
            node* hold = (Node)->_parent;
            node* ptr = (Node)->_right;


            Node->_parent = ptr;
            ptr->_left = Node;
            Node->_right = NULL;
            ptr->_parent = hold;
            if (Node != _root)
            {
                if(IsChild(Node) == 1)
                    hold->_left = ptr;
                else if (IsChild(Node) == 2)
                    hold->_right = ptr;
            }
            else
                _root = ptr;
            (Node)->_height = max(GetHeight((Node)->_right), GetHeight((Node)->_left)) + 1;
            ptr->_height = max(GetHeight(ptr->_right), GetHeight(ptr->_left)) + 1;

            (Node)->_balance = GetBalance(Node);
            ptr->_balance = GetBalance(ptr);
        }

        void RightRotate(node* Node)
        {
            node* hold = Node->_parent;
            node* ptr = Node->_left;

            Node->_parent = ptr;
            ptr->_right = Node;
            Node->_left = NULL;
            ptr->_parent = hold;
            if (Node != _root)
            {
                if(IsChild(Node) == 1)
                    hold->_left = ptr;
                else if (IsChild(Node) == 2)
                    hold->_right = ptr;
            }
            else
                _root = ptr;
            (Node)->_height = max(GetHeight((Node)->_right), GetHeight((Node)->_left)) + 1;
            ptr->_height = max(GetHeight(ptr->_right), GetHeight(ptr->_left)) + 1;

            (Node)->_balance = GetBalance(Node);
            ptr->_balance = GetBalance(ptr);

        }

        void rebalance(node* Node, int value)
        {

            if (Node->_balance > 1)
            {
                if (value < Node->_left->_value)
                    RightRotate(Node);
                else
                {
                    LeftRotate(Node->_left);
                    RightRotate(Node);
                }
                    
            }
            else if (Node->_balance < -1)
            {
                if (value > Node->_right->_value)
                {
                    LeftRotate(Node);
                }
                else
                {
                    RightRotate(Node->_right);
                    LeftRotate(Node);
                }
            }
        }

        void HelperInsert(node** root, int value)
        {
            // using recursion we insert new Node like BST insertion
            if (*root == NULL)
            {
                *root =  new node(value, 1, NULL, NULL, NULL);
            }
            else if (value > (*root)->_value)
            {
                HelperInsert(&((*root)->_right), value);
                (*root)->_right->_parent = (*root);
            }
            else if (value < (*root)->_value)
            {
                HelperInsert(&((*root)->_left), value);
                (*root)->_left->_parent = (*root);
            }
            else
                return ;
            // update height factor 
            (*root)->_height = max(GetHeight((*root)->_left), GetHeight((*root)->_right)) + 1;      
            (*root)->_balance = GetBalance((*root));
            // rebalance
            rebalance(*root, value);
        }

        int GetBalance(node* Node)
        {
            if (Node == NULL)
                return 0;
            return (GetHeight(Node->_left) - GetHeight(Node->_right));
        }

        void HelperPrint(node* root)
        {
            if (root == NULL)
                return ;
            if (root == _root)
                cout << "this is root: " << root->_value << " balance: " << root->_balance << endl;
            else 
                cout << root->_value << " _balance: "<< root->_balance << endl;
            HelperPrint(root->_left);
            HelperPrint(root->_right);
        }

        node* HelperSearch(node* root, int value)
        {
            if (root == NULL)
                return NULL;
            if (root->_value == value)
                return root;
            if (value > root->_value)
                return HelperSearch(root->_right, value);
            if (value < root->_value)
                return HelperSearch(root->_left, value);
            return root;
        }

        void HelperDelete(node** root, int value)
        {
            if ((*root) == NULL)
                return ;
            if ((*root)->_value > value)
                HelperDelete(&((*root)->_left), value);
            else if ((*root)->_value < value)
                HelperDelete(&((*root)->_right), value);
            else
            {
                if ((*root)->_left == NULL  && (*root)->_right == NULL) // no child
                {
                    delete (*root);
                    (*root) = NULL;
                }
                else if ((*root)->_left != NULL  && (*root)->_right != NULL) // two child
                {
                    node* ptr = inorder_successor((*root)->_right); // now ptr point to a node with a minimum value in the right subtree
                    int hold_value = ptr->_value;
                    ptr->_value = (*root)->_value;
                    (*root)->_value = hold_value;
                    HelperDelete(&(*root)->_right, value);
                }
                else // one child
                {
                    node* hold = (*root)->_parent;
                    node* ptr;
                    if ((*root)->_left != NULL)
                        ptr = (*root)->_left;
                    else
                        ptr = (*root)->_right;
                    if (IsChild((*root)) == 1)
                        hold->_left = ptr;
                    else if (IsChild((*root)) == 2)
                        hold->_right = ptr;
                    ptr->_parent = hold;
                    delete (*root);
                    // cout << hold->_left->_value << endl;
                }
            }

        }

    public:
        AvlTree() : _root(NULL), _size(0) {}

        node* GetRoot(void) const
        {
           return (this->_root);
        }
        int GetHeight(node* Node)
        {
            if (Node == NULL)
                return 0;
            return (Node->_height);
        }
        int GetSize(void) const
        {
            return (this->_size);
        }

        int max(int a, int b)
        {
            if (a > b)
                return a;
            return b;
        }

        int IsChild(node* Node)
        {
            if(Node == NULL || Node->_parent == NULL)
                return 0;
            if (Node == Node->_parent->_left) // Node is a left child
                return 1;
            return 2; // Node is a Right child
        }

        node* inorder_successor(node* Node)
        {
            if (Node == NULL || Node->_left == NULL)
                return Node;
            while(Node != NULL && Node->_left != NULL)
            {
                Node = Node->_left;
            }
            return Node;
        }

        void insert(int value)
        {
            HelperInsert(&_root, value);
        }

        bool Search(int value)
        {
            if (HelperSearch(_root, value) != NULL)
                return true;
            return false;
        }

        void Delete(int value)
        {
            HelperDelete(&_root, value);
        }
        void PrintTree(void)
        {
            HelperPrint(_root);
        }
};
