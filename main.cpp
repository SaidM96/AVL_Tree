/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:31:54 by smia              #+#    #+#             */
/*   Updated: 2022/12/19 02:26:34 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AvlTree.hpp"

int main()
{
    AvlTree tree;

    tree.insert(63);
    tree.insert(9);
    tree.insert(19);
    tree.insert(27);
    tree.insert(18);
    tree.insert(108);
    tree.insert(99);
    tree.insert(81);
        // tree.PrintTree();

    cout << "delete 9 \n";
    tree.Delete(9);
    tree.PrintTree();
    // cout << "delete 27 \n";
    // tree.Delete(27);
    // tree.PrintTree();
    // cout << "delete 63 \n";
    // tree.Delete(63);
    // tree.PrintTree();

    // if (tree.Search(81))
    //     cout << " exist\n";
    // tree.print_tree(tree.get_root());
    // puts("///////\n");
    // tree.print_tree(tree.get_root());
    // puts("///////\n");
    // tree.insert_node(19);
// tree.print_tree(tree.get_root());
    // // puts("///////\n");
    
   
}