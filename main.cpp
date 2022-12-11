/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:31:54 by smia              #+#    #+#             */
/*   Updated: 2022/12/11 13:07:12 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AVL.hpp"

int main()
{
    AvlTree tree;
    

    tree.insert_node(10);
     tree.insert_node(15);
    tree.insert_node(18);
    // tree.insert_node(20);
   
    // tree.print_tree(tree.get_root());
}