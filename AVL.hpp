/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVL.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 04:26:59 by smia              #+#    #+#             */
/*   Updated: 2022/12/11 19:07:56 by smia             ###   ########.fr       */
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
        int     balance_factor;  // (Height of Left Subtree - Height of Right Subtree) or (Height of Right Subtree - Height of Left Subtree) , The value of balance factor should always be -1, 0 or +1.
        node(int data, node* parent, node* right, node* left, int balance) : _data(data), _parent(parent), _right(right), _left(left), balance_factor(balance)
        {
        }
        
};

class AvlTree
{
private:
        node*   _root;
        node*   _NIL;
        int     _size;
public:
    AvlTree() : _size(0)
    {
        _NIL = new node(0, NULL, NULL, NULL, 0);
        _root = _NIL;
    }
    node* get_root(void) const { return (this->_root); }
    node* get_size(void) const { return (this->_size);}
    
    int Balance_factor(node* Node)
    {
            // if(Node->_left && Node->_right)
            // {
            //     if (Node->_left->balance_factor < Node->_right->balance_factor)
            //         return Node->_right->balance_factor + 1;
            //     else 
            //         return  Node->_left->balance_factor + 1;
            // }
            // else if(Node->_left && Node->_right ==  _NIL)
            // {
            //     return Node->_left->balance_factor + 1;
            // }
            // else if(Node->_left == _NIL && Node->_right)
            // {
            //     return Node->_right->balance_factor + 1;
            // }
            // return 0;
        //
        int left_height = 0;
        int right_height = 0;
        node* tmp = Node;
        
        if (tmp == _NIL)
            return 0;
        while(tmp != _NIL && tmp->_left != _NIL)
        {
            tmp = tmp->_left;
            left_height++;
        }
        tmp = Node;
        while(tmp != _NIL && tmp->_right != _NIL)
        {
            tmp = tmp->_right;
            right_height++;
        }
        // std::cout << (right_height - left_height) << std::endl;
        return (right_height - left_height);
    }
    
    int is_leftchild(node* Node)
    {
        if (Node == _NIL || Node == _root)
            return 0;
        if (Node->_data < Node->_parent->_data) // is left child
            return 1; 
        if (Node->_data > Node->_parent->_data) // is right child;
            return 2;
    }

    // node* find_error(node* root)
    // {
    //     if (root != _NIL)
    //     {
    //         root->balance_factor = Balance_factor(root);
    //         // std::cout << root->_data << " factor: "<< root->balance_factor<<  std::endl;
    //         if (root->balance_factor != 0 && root->balance_factor != 1 && root->balance_factor != -1)
    //             return root;
    //     }
    //     if (root->_right != _NIL)
    //         return find_error(root->_right);
    //     if (root->_left != _NIL)
    //         return find_error(root->_left);
    //     return _NIL;
    // }
    
    int max(int a, int b)
    {
        if (a > b)
            return b;
        return a;
    }

    void left_rotate(node* Node)
    {
            
        // node* right = Node->_right;  
        // node* tmp = right->_left;  
        // // Perform rotation
        // right->_right = Node;    
        // Node->_left = tmp;
        // //
        // if (Node == _root)
        //      _root = Node->_right;
        // // update balance factor
        // Node->balance_factor = max(Balance_factor(Node->_left),Balance_factor(Node->_right)) + 1;
        // right->balance_factor = max(Balance_factor(right->_left),Balance_factor(right->_right)) + 1;
    }

    void right_rotate(node* Node)
    {
        // node* left = Node->_left;
        // node* tmp = left->_right;  
        // // Perform rotation  
        // left->_right = Node;    
        // Node->_left = tmp;
        
        // //
        // if (Node == _root)
        //      _root = Node->_left;
        // // update balance factor

        // Node->balance_factor = max(Balance_factor(Node->_left),Balance_factor(Node->_right)) + 1;
        // left->balance_factor = max(Balance_factor(left->_left),Balance_factor(left->_right)) + 1;
    }

    void fix_insert(node* Node)
    {
            if (Node == _NIL) // if nil
            {
                return ;
            }
            if (Balance_factor(Node) > 1 || Balance_factor(Node) < -1) // if Node unbalanced 
            {
                // fix_violation
                
                
            }
            fix_insert(Node->_parent);
    }

    void insert_node(int data)
    {
        node* Node = new node(data, _NIL, _NIL, _NIL, 0); // creat new Node
        // find good position in tree to insert new Node
        if (_root == _NIL)
        {
            _root = Node;
            return ;
        }
        node* ptr = _root;
        while (ptr != _NIL)
        {
            if (data > ptr->_data)
                ptr = ptr->_right;
            else if (data < ptr->_data)
                ptr = ptr->_left;
            else
            {
                delete Node;
                return ;
            }
        }
        // insert Node
        ptr->_parent = Node;
        if (is_leftchild(Node) == 1)
            ptr->_parent->_left = Node;
        else
            ptr->_parent->_right = Node;
        // check if there is a violation in tree
        fix_insert(Node->_parent);
    }

    void print_tree(node* root)
    {

            if (root == _NIL)
            {
                std::cout << "tree is empty \n";
                return ;
            }
            if (root != _NIL)
            {
                if (root == this->_root)
                    std::cout << root->_data << " this is root\n";
                else
                    std::cout << root->_data  << std::endl;
            }
            if (root->_left != _NIL)
                print_tree(root->_left);
            if (root->_right != _NIL)
                print_tree(root->_right);
    }
};