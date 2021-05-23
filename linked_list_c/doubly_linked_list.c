/**
 * @file doubly_linked_list.c
 * @author Chen Liang (chen.liang.mail@protonmail.com)
 * @brief Implementation of doubly linked list
 * @version 0.1
 * @date 2021-05-23
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

int add_first(node_t **head, void *value, int node_flag)
{
    int result = 0;

    node_t *new_node = NULL;
    new_node = calloc(1, sizeof(node_t));

    new_node->pre_node = NULL;
    new_node->nxt_node = *head;
    *head = new_node;

    return result;
}

int main(void)
{
    return 0;
}