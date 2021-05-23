/**
 * @file single_linked_list.cpp
 * @author Chen Liang (chen.liang.mail@protonmail.com)
 * @brief Single linked list written in C++
 * @version 0.1
 * @date 2021-05-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include "single_linked_list.h"

SingleLinkedList::SingleLinkedList()
{
    node_t head;
    head.next_node_ptr = NULL;
    head.num = 0;

    this -> no_of_element = 0;
    this -> node_flag = INT_FLAG;
}

int SingleLinkedList::length_of()
{
    return no_of_element;
}

int main(void)
{
    return 0;
}