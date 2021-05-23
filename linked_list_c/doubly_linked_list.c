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

int add_first(node_t **head, node_t **tail, void *new_var,
                                                    int node_flag)
{
    int result = 0;

    node_t *new_node = NULL;
    node_t *current_node = NULL;

    content_t *new_content = NULL;

    new_node = calloc(1, sizeof(node_t));
    new_content = calloc(1, sizeof(content_t));
    new_node->content = new_content;

    if (node_flag == INT_FLAG)
    {
        new_content->i_num = *(int *)new_var;
        new_node->node_flag = INT_FLAG;
    }
    else if (node_flag == FLOAT_FLAG)
    {
        new_content->f_num = *(float *)new_var;
        new_node->node_flag = FLOAT_FLAG;
    }
    else if (node_flag == CHAR_FLAG)
    {
        new_content->c = *(char *)new_var;
        new_node->node_flag = CHAR_FLAG;
    }
    else
    {
        result = -1;
    }

    if (*head == NULL && *tail == NULL)
    {
        new_node->pre_node = NULL;
        new_node->nxt_node = NULL;
        *head = new_node;
        *tail = new_node;
    }
    else
    {
        new_node->pre_node = NULL;
        (*head)->pre_node = new_node;

        new_node->nxt_node = *head;
        *head = new_node;
    }

    current_node = *head;

    while (current_node->nxt_node != NULL)
    {
        current_node = current_node->nxt_node;

    }

    *tail = current_node;

    return result;
}

int add_end(node_t **head, node_t **tail, void *new_var,
                                                int node_flag)
{
    int result = 0;
    node_t *new_node = NULL;
    node_t *current_node = NULL;

    content_t *new_content = NULL;

    new_node = calloc(1, sizeof(node_t));
    new_content = calloc(1, sizeof(content_t));
    new_node->content = new_content;

    if (node_flag == INT_FLAG)
    {
        new_content->i_num = *(int *)new_var;
        new_node->node_flag = INT_FLAG;
    }
    else if (node_flag == FLOAT_FLAG)
    {
        new_content->f_num = *(float *)new_var;
        new_node->node_flag = FLOAT_FLAG;
    }
    else if (node_flag == CHAR_FLAG)
    {
        new_content->c = *(char *)new_var;
        new_node->node_flag = CHAR_FLAG;
    }
    else
    {
        result = -1;
    }

    if (*head == NULL && *tail == NULL)
    {
        new_node->pre_node = NULL;
        new_node->nxt_node = NULL;
        *head = new_node;
        *tail = new_node;
    }
    else
    {
        new_node->nxt_node = NULL;
        (*tail)->nxt_node = new_node;

        new_node->pre_node = *tail;
        *tail = new_node;
    }

    current_node = *tail;

    while (current_node->pre_node != NULL)
    {
        current_node = current_node->pre_node;

    }

    *head = current_node;

    return result;
}

int add_at(node_t **head, node_t **tail, void *new_var,
                                        int node_flag, int position)
{
    int result = 0;
    int index = 1;

    node_t *new_node = NULL;
    node_t *pre_node = NULL;
    node_t *current_node = NULL;
    node_t *next_node = NULL;

    content_t *new_content = NULL;

    new_node = calloc(1, sizeof(node_t));
    new_content = calloc(1, sizeof(content_t));

    new_node->content = new_content;

    if (node_flag == INT_FLAG)
    {
        new_content->i_num = *(int *)new_var;
        new_node->node_flag = INT_FLAG;
    }
    else if (node_flag == FLOAT_FLAG)
    {
        new_content->f_num = *(float *)new_var;
        new_node->node_flag = FLOAT_FLAG;
    }
    else if (node_flag == CHAR_FLAG)
    {
        new_content->c = *(char *)new_var;
        new_node->node_flag = CHAR_FLAG;
    }
    else
    {
        result = -1;
    }

    if (*head == NULL && *tail == NULL)
    {
        new_node->pre_node = NULL;
        new_node->nxt_node = NULL;
        *head = new_node;
        *tail = new_node;
    }
    else if (position == 0)
    {
        new_node->nxt_node = *head;
        *head = new_node;
    }
    else
    {
        pre_node = *head;
        next_node = (*head)->nxt_node;

        while(index < position && pre_node->nxt_node != NULL)
        {
            pre_node = pre_node->nxt_node;
            next_node = pre_node->nxt_node;
            index++;
        }

        pre_node->nxt_node = new_node;

        new_node->pre_node = pre_node;
        new_node->nxt_node = next_node;

        if (next_node == NULL)
            new_node->nxt_node = NULL;
        else
            next_node->pre_node = new_node;
    }

    current_node = *head;

    while (current_node->nxt_node != NULL)
    {
        current_node = current_node->nxt_node;

    }

    *tail = current_node;

    return result;
}

int remove_first(node_t **head, node_t **tail)
{
    int result = 0;

    node_t *to_be_removed = NULL;

    if (*head == NULL && *tail == NULL)
    {
        result = -1;
    }
    else if ((*head)->nxt_node == NULL)
    {
        to_be_removed = *head;
        *head = NULL;
        *tail = NULL;
    }
    else
    {

        *head = (*head)->nxt_node;
        (*head)->pre_node = NULL;
    }

    free(to_be_removed->content);
    free(to_be_removed);

    return result;
}

void display(node_t *head)
{
    int i = 0;

    while (head != NULL)
    {
        printf("%d  |  ", i);
        if (head->node_flag == INT_FLAG)
            printf("Integer: %d\n", head->content->i_num);
        else if (head->node_flag == FLOAT_FLAG)
            printf("Float: %.4f\n", head->content->f_num);
        else if (head->node_flag == CHAR_FLAG)
            printf("Character: %c\n", head->content->c);
        else
            printf("ERROR\n");

        head = head->nxt_node;
        i++;
    }
}

void display_reverse(node_t *tail)
{
    int i = 0;
    node_t *current_node = tail;

    if (tail != NULL)
        while (current_node->pre_node != NULL)
        {
            current_node = current_node->pre_node;
            i++;
        }

    while (tail != NULL)
    {
        printf("%d  |  ", i);
        if (tail->node_flag == INT_FLAG)
            printf("Integer: %d\n", tail->content->i_num);
        else if (tail->node_flag == FLOAT_FLAG)
            printf("Float: %.4f\n", tail->content->f_num);
        else if (tail->node_flag == CHAR_FLAG)
            printf("Character: %c\n", tail->content->c);
        else
            printf("ERROR\n");

        tail = tail->pre_node;
        i--;
    }
}

int length_of(node_t *head)
{
    int result = 0;

    while (head != NULL)
    {
        head = head->nxt_node;
        result++;
    }
    return result;
}

int free_memory(node_t *head)
{
    int result = 0;

    node_t *to_be_removed = NULL;

    while (head != NULL)
    {
        to_be_removed = head;
        head = head->nxt_node;
        free(to_be_removed->content);
        free(to_be_removed);
    }

    return result;
}

int main(void)
{
    node_t *head = NULL;
    node_t *tail = NULL;

    int i_num = 100;
    int i_num2 = 200;
    char c1 = 'A';
    float f_num = 10.01;
    float f_num2 = 20.02;

    add_first(&head, &tail, &i_num, INT_FLAG);
    // add_first(&head, &tail, &c1, CHAR_FLAG);
    // add_end(&head, &tail, &f_num, FLOAT_FLAG);
    // add_end(&head, &tail, &i_num2, INT_FLAG);

    // add_at(&head, &tail, &f_num2, FLOAT_FLAG, 9);

    remove_first(&head, &tail);

    display(head);
    printf("----------------------\n");
    display_reverse(tail);

    free_memory(head);
    return 0;
}