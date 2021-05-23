/**
 * @file doubly_linked_list.h
 * @author Chen Liang (chen.liang.mail@protonmail.com)
 * @brief Create doubly linked list using C language
 * @version 0.1
 * @date 2021-05-23
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define INT_FLAG 0
#define FLOAT_FLAG 1
#define CHAR_FLAG 2

typedef union content
{
    int i_num;
    float f_num;
    char c;
} content_t;

typedef struct node
{
    content_t *content;
    int node_flag;

    struct node *pre_node;
    struct node *nxt_node;
} node_t;

int add_first(node_t **head, void *value, int node_flag);