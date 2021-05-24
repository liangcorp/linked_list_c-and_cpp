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

using namespace std;

SingleLinkedList::SingleLinkedList()
{
    node_t head;
    head.next_node_ptr = NULL;
    head.content.i_num = 0;

    this -> node_flag = INT_FLAG;
}

SingleLinkedList::SingleLinkedList(int node_flag)
{
    node_t head;
    head.next_node_ptr = NULL;

    if (node_flag == INT_FLAG)
        head.content.i_num = 0;
    else if (node_flag == FLOAT_FLAG)
        head.content.f_num = 0.0;
    else if (node_flag == CHAR_FLAG)
        head.content.c == 'A';
    else
        perror("Invalid content flag\n");

    this -> node_flag = node_flag;
}

int SingleLinkedList::no_of_nodes = 0;


int SingleLinkedList::get_length()
{
    return SingleLinkedList::no_of_nodes;
}

int SingleLinkedList::get_node_flag()
{
    return node_flag;
}

int main(void)
{
    SingleLinkedList linked_list;

    cout << "No of nodes is " << linked_list.get_length() << endl;

    return 0;
}