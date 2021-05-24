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

template <typename T>
SingleLinkedList<T>::SingleLinkedList()
{
    this -> head = (node_t *)calloc(1, sizeof(node_t));
    this -> head->content = (T *)calloc(1, sizeof(T));

    head->next_node_ptr = nullptr;
    *(head->content) = 0;

    this -> node_flag = INT_FLAG;
}

template <typename T>
SingleLinkedList<T>::SingleLinkedList(int node_flag)
{
    this -> head = (node_t *)calloc(1, sizeof(node_t));
    this -> head->content = (T *)calloc(1, sizeof(T));

    head->next_node_ptr = nullptr;

    if (node_flag == INT_FLAG)
        *(head->content) = 0;
    else if (node_flag == FLOAT_FLAG)
        *(head->content) = 0.0;
    else if (node_flag == CHAR_FLAG)
        *(head->content) = 'A';
    else
        perror("Invalid content flag\n");

    this -> node_flag = node_flag;
}

template <typename T>
SingleLinkedList<T>::SingleLinkedList(T new_var, int node_flag)
{
    this -> head = (node_t *)calloc(1, sizeof(node_t));
    this -> head->content = (T *)calloc(1, sizeof(T));

    head->next_node_ptr = nullptr;

    *(head->content) = new_var;

    this -> node_flag = node_flag;
}

template <typename T>
SingleLinkedList<T>::~SingleLinkedList()
{
    // Destructor to free up memory
    this -> free_memory();
}

template <typename T>
int SingleLinkedList<T>::no_of_nodes = 1;

template <typename T>
int SingleLinkedList<T>::add_first(T new_var, int node_flag)
{
    int result = 0;
    node_t *new_node = nullptr;

    new_node = (node_t *)calloc(1, sizeof(node_t));
    new_node->content = (T *)calloc(1, sizeof(T));

    *(new_node->content) = new_var;

    new_node->next_node_ptr = this -> head;
    this->head = new_node;

    SingleLinkedList::no_of_nodes++;

    return result;
}

template <typename T>
int SingleLinkedList<T>::get_length()
{
    return SingleLinkedList::no_of_nodes;
}

template <typename T>
int SingleLinkedList<T>::get_node_flag()
{
    return node_flag;
}

template <typename T>
T SingleLinkedList<T>::get_element(int position)
{
    T result;
    node_t *current_node = nullptr;
    int i = 1;

    if (this -> no_of_nodes > position)
    {
        current_node = this -> head;
        for (i = 1; i < position; i++)
        {
            current_node = current_node->next_node_ptr;
        }
        result = *(current_node->content);
        cout << result << endl;
    }
    else
    {
        result = -1;
    }
    return result;
}

template <typename T>
void SingleLinkedList<T>::display_nodes()
{
    node_t *current_node = nullptr;
    current_node = this -> head;
    int i = 0;

    // while (current_node->next_node_ptr != nullptr)
    for (i = 0; i < this->no_of_nodes; i++)
    {
        cout << *(current_node->content) << endl;
        current_node = current_node->next_node_ptr;
    }
}

template <typename T>
int SingleLinkedList<T>::free_memory()
{
    int result = 0;

    node_t *to_be_freed = nullptr;

    if (this -> no_of_nodes <= 1)
    {
        free(this -> head->content);
        free(this -> head);
    }
    else
    {
        while (this -> head->next_node_ptr != nullptr)
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
    SingleLinkedList<int> linked_list(10, INT_FLAG);
    linked_list.add_first(100, INT_FLAG);
    linked_list.add_first(1000, INT_FLAG);

    cout << "No of nodes is " << linked_list.get_length() << endl;

    linked_list.display_nodes();

    cout << "First element is " << linked_list.get_element(0) << endl;
    cout << "Second element is " << linked_list.get_element(1) << endl;

    return 0;
}