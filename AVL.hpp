/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVL.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 04:26:59 by smia              #+#    #+#             */
/*   Updated: 2022/12/17 03:12:23 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class node
{
    public :
        int     _data;
        node*   _right;
        node*   _left;
        node*   _parent;
        int     _balance_factor;  // (Height of Left Subtree - Height of Right Subtree) or (Height of Right Subtree - Height of Left Subtree) , The value of balance factor should always be -1, 0 or +1.
        node(int data, node* parent, node* right, node* left, int balance) : _data(data), _parent(parent), _right(right), _left(left), _balance_factor(balance)
        {
        }
        
};

class AvlTree
{
private:
        node*   _root;
        int     _size;
public:
    AvlTree() : _size(0)
    {
        _root = NULL;
    }

    node* get_root(void) const { return (this->_root); }
    int get_size(void) const { return (this->_size);}

    int get_Balance_factor(node* Node) const
    {
        if (Node == NULL)
            return 0;
        return Node->_balance_factor;
    }

    int is_leftchild(node* Node)
    {
        if (Node == _root)
            return 3;
        if (Node->_data < Node->_parent->_data) // is left child
            return 1; 
        if (Node->_data > Node->_parent->_data) // is right child;
            return 2;
        return 0;
    }


    void left_rotation(node* Node)
    {
        node* tmp = Node->_right->_left;
        node* ptr = Node->_right;
        node* hold = Node->_parent;
        if (Node == _root)
            _root = ptr;
        else
        {     
            if (is_leftchild(ptr) == 1)
                hold->_left = ptr;
            else
                hold->_right = ptr;
        }
        Node->_parent = ptr;
        ptr->_parent = hold;
        Node->_right = tmp;
        ptr->_left = Node;

        Node->_balance_factor = max(get_Balance_factor(Node->_right), get_Balance_factor(Node->_left));
        ptr->_balance_factor = max(get_Balance_factor(ptr->_right), get_Balance_factor(ptr->_left));
    }
    
    int max(int a, int b)
    {
        if (a > b)
            return a;
        return b;
    }
    
    void right_rotation(node* Node)
    {
        node* tmp = Node->_left->_right;
        node* ptr = Node->_left;
        node* hold = Node->_parent;
        if (Node == _root)
            _root = ptr;
        else
        {     
            if (is_leftchild(ptr) == 1)
                hold->_left = ptr;
            else
                hold->_right = ptr;
        }
        Node->_parent = ptr;
        ptr->_parent = hold;
        Node->_left = tmp;
        ptr->_right = Node;
            
        
        Node->_balance_factor = max(get_Balance_factor(Node->_right), get_Balance_factor(Node->_left));
        ptr->_balance_factor = max(get_Balance_factor(ptr->_right), get_Balance_factor(ptr->_left));
    }

    void fix_insert(node* Node)
    {
        node* ptr = Node;
        while(ptr != NULL)
        {
            if (ptr->_balance_factor < -1)
            {
               left_rotation(ptr);
               update_balance_rotation(ptr);
               break ;
            }
            else if (ptr->_balance_factor > 1)
            {
                right_rotation(ptr);
                update_balance_rotation(ptr);
                break;
            }
            ptr = ptr->_parent;
        }
    }

    void update_balance_rotation(node* Node)
    {
        if (Node->_parent != NULL)
        {
            node* ptr = Node->_parent->_parent;
            while(ptr != NULL)
            {
                if (ptr->_data < Node->_data)
                {
                    ptr->_balance_factor++;
                }
                else
                {
                    ptr->_balance_factor--;
                }
                if (ptr->_parent == NULL)
                    break ;
                ptr = ptr->_parent;
                Node = ptr->_parent;
            }
        }
        
    }
    void update_balance_factor(node* Node)
    {
        node* ptr = Node;
        while(ptr != NULL)
        {
            if (is_leftchild(ptr) == 1)
                ptr->_parent->_balance_factor++;
            else if (is_leftchild(ptr) == 2)
                ptr->_parent->_balance_factor--;
            ptr = ptr->_parent;
        }
    }

    void insert_node(int data)
    {
        node* Node = new node(data, NULL, NULL, NULL, 0); // creat new Node
        
        node* ptr = _root; // ptr start with root and go till we find position that we will insert new Node in
        node* hold = NULL; // hold parent of pos (node that we will insert in)
        while( ptr != NULL)
        {
            hold = ptr;
            if (Node->_data > ptr->_data)
                ptr = ptr->_right;
            else if (Node->_data < ptr->_data)
                ptr = ptr->_left;
            else
            {
                delete Node;
                return ;
            }
        }
        Node->_parent = hold; // new Node with his parent;
        if (hold == NULL) 
        {
            _root = Node;
            return ;
        }
        else if (Node->_data > hold->_data)
            hold->_right = Node;
        else
            hold->_left = Node;
        update_balance_factor(Node);
        // check if there is a violation in tree and fix it

        fix_insert(Node);
    }

    void print_tree(node* root)
    {

            if (root == NULL)
            {
                std::cout << "tree is empty \n";
                return ;
            }
            if (root != NULL)
            {
                if (root == this->_root)
                    std::cout << root->_data << " Balance factor: " << root->_balance_factor << " this is root\n";
                else
                    std::cout << root->_data  << " Balance factor: " << root->_balance_factor << std::endl;
            }
            if (root->_left != NULL)
                print_tree(root->_left);
            if (root->_right != NULL)
                print_tree(root->_right);
    }
};