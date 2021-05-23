/**
 * @file single_linked_list.h
 * @author Chen Liang (chen.liang.mail@protonmail.com)
 * @brief Implementation of single linked list in C
 * @version 0.1
 * @date 2021-05-22
 *
 * @copyright Copyright (c) 2021
 *
 */

/* User flag to mark which node is active in the union */
#define INT_FLAG 0
#define FLOAT_FLAG 1
#define CHAR_FLAG 2

/* This maybe a mistake */
typedef union content
{
    int i_num;
    float f_num;
    char c;
} content_t;

typedef struct node
{
    content_t *node_content;
    int node_flag;
    struct node *nxt_node_ptr;
} node_t;

int add_first(node_t **head, void *new_var, int content_flag);
int add_last(node_t **head, void *new_var, int content_flag);
int add_at(node_t **head, void *new_var, int index,
                                                int content_flag);

int remove_first(node_t **head);
int remove_last(node_t **head);
int remove_at(node_t **head, int index);

int length_of(node_t *head);

void display_nodes(node_t *head);

int free_memory(node_t *head);
