/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:31:54 by smia              #+#    #+#             */
/*   Updated: 2022/12/16 23:34:08 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AVL.hpp"

int main()
{
    AvlTree tree;
    

    tree.insert_node(3);
    tree.insert_node(2);
    tree.insert_node(1);
    tree.print_tree(tree.get_root());
    
   
}