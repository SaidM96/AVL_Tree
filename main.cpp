/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:31:54 by smia              #+#    #+#             */
/*   Updated: 2022/12/17 02:46:06 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AVL.hpp"

int main()
{
    AvlTree tree;
    
tree.insert_node(1);
tree.insert_node(2);
tree.insert_node(3);
// tree.print_tree(tree.get_root());
tree.insert_node(4);
tree.insert_node(5);
tree.print_tree(tree.get_root());


    // tree.insert_node(63);
    // tree.print_tree(tree.get_root());
    // puts("///////\n");
    // tree.insert_node(9);
    // tree.print_tree(tree.get_root());
    // puts("///////\n");
    // tree.insert_node(19);
// tree.print_tree(tree.get_root());
    // // puts("///////\n");
    
   
}