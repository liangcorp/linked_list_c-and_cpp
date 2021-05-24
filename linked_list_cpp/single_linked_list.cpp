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
    this -> head = (node_t *)calloc(1, sizeof(node_t));
    this -> head->content = (content_t *)calloc(1, sizeof(content_t));

    head->next_node_ptr = NULL;
    head->content->i_num = 0;

    this -> node_flag = INT_FLAG;
}

SingleLinkedList::SingleLinkedList(int node_flag)
{
    this -> head = (node_t *)calloc(1, sizeof(node_t));
    this -> head->content = (content_t *)calloc(1, sizeof(content_t));

    head->next_node_ptr = NULL;

    if (node_flag == INT_FLAG)
        head->content->i_num = 0;
    else if (node_flag == FLOAT_FLAG)
        head->content->f_num = 0.0;
    else if (node_flag == CHAR_FLAG)
        head->content->c == 'A';
    else
        perror("Invalid content flag\n");

    this -> node_flag = node_flag;
}

SingleLinkedList::SingleLinkedList(void *new_var, int node_flag)
{
    this -> head = (node_t *)calloc(1, sizeof(node_t));
    this -> head->content = (content_t *)calloc(1, sizeof(content_t));

    head->next_node_ptr = NULL;

    if (node_flag == INT_FLAG)
        head->content->i_num = *(int *)new_var;
    else if (node_flag == FLOAT_FLAG)
        head->content->f_num = *(float *)new_var;
    else if (node_flag == CHAR_FLAG)
        head->content->c == *(char *)new_var;
    else
        perror("Invalid content flag\n");

    this -> node_flag = node_flag;
}

SingleLinkedList::~SingleLinkedList()
{
    // Destructor to free up memory
    this -> free_memory();
}

int SingleLinkedList::no_of_nodes = 1;


int SingleLinkedList::get_length()
{
    return SingleLinkedList::no_of_nodes;
}

int SingleLinkedList::get_node_flag()
{
    return node_flag;
}

void * SingleLinkedList::get_element(int position)
{
    void * result = NULL;

    if (this -> node_flag == INT_FLAG)
        result = &(head->content->i_num);

    return result;
}

int SingleLinkedList::free_memory()
{
    int result = 0;

    node_t *to_be_freed = NULL;

    if (this -> no_of_nodes <= 1)
    {
        free(this -> head->content);
        free(this -> head);
    }
    else
    {
        while (this -> head->next_node_ptr != NULL)
        {
            to_be_freed = this -> head;
            this -> head = this -> head->next_node_ptr;
            free(to_be_freed->content);
            free(to_be_freed);
        }
    }
    return result;
}

int main(void)
{
    int i_num = 10;
    SingleLinkedList linked_list(&i_num, 0);

    cout << "No of nodes is " << linked_list.get_length() << endl;

    cout << "First element is " << *(int *)linked_list.get_element(0) << endl;

    // linked_list.free_memory();
    return 0;
}