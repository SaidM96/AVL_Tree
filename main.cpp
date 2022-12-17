/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:31:54 by smia              #+#    #+#             */
/*   Updated: 2022/12/17 20:13:27 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AVL.hpp"

int main()
{
    AvlTree tree;
    
tree.insert_node(63);
tree.insert_node(9);
tree.insert_node(19);
tree.insert_node(27);
tree.insert_node(18);
tree.insert_node(108);
tree.insert_node(99);
// tree.insert_node(81);

// tree.print_tree(tree.get_root());
tree.print_tree(tree.get_root());


    // tree.print_tree(tree.get_root());
    // puts("///////\n");
    // tree.print_tree(tree.get_root());
    // puts("///////\n");
    // tree.insert_node(19);
// tree.print_tree(tree.get_root());
    // // puts("///////\n");
    
   
}