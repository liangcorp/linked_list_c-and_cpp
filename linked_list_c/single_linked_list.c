/**
 * @file single_linked_list.c
 * @author Chen Liang (chen.liang.mail@protonmail.com)
 * @brief Implementation of single linked list in C
 * @version 0.1
 * @date 2021-05-22
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "single_linked_list.h"

int insert_beginning(node_t **head, void *new_var, int content_flag)
{
    int result = 0;

    node_t *new_head = NULL;
    content_t *new_content = NULL;

    new_head = calloc(1, sizeof(node_t));
    new_content = calloc(1, sizeof(content_t));

    /*
        Using union maybe a bad idea.
     */

    if (content_flag == INT_FLAG)
    {
        new_content->i_num = *(int *)new_var;
        new_head->node_flag = INT_FLAG;

        #ifdef DEBUG
            printf("Integer %d\n", new_content->i_num);
        #endif
    }
    else if (content_flag == FLOAT_FLAG)
    {
        new_content->f_num = *(float *)new_var;
        new_head->node_flag = FLOAT_FLAG;

        #ifdef DEBUG
            printf("Float %d\n", new_content->f_num);
        #endif
    }
    else if (content_flag == CHAR_FLAG)
    {
        new_content->c = *(char *)new_var;
        new_head->node_flag = CHAR_FLAG;

        #ifdef DEBUG
            printf("Character %d\n", new_content->c);
        #endif
    }
    else
    {
        result = -1;
    }

    new_head->node_content = new_content;

    if (*head != NULL)
    {
        new_head->nxt_node_ptr = *head;
    }
    else
    {
        new_head->nxt_node_ptr = NULL;
    }

    *head = new_head;

    return result;
}

int insert_end(node_t **head, void *new_var, int content_flag)
{
    int result = 0;

    node_t *new_tail = NULL;
    node_t *current_node = NULL;
    content_t *new_content = NULL;

    new_tail = calloc(1, sizeof(node_t));
    new_content = calloc(1, sizeof(content_t));

    if (content_flag == INT_FLAG)
    {
        new_content->i_num = *(int *)new_var;
        new_tail->node_flag = INT_FLAG;

        #ifdef DEBUG
            printf("Integer %d\n", new_content->i_num);
        #endif
    }
    else if (content_flag == FLOAT_FLAG)
    {
        new_content->f_num = *(float *)new_var;
        new_tail->node_flag = FLOAT_FLAG;

        #ifdef DEBUG
            printf("Float %d\n", new_content->f_num);
        #endif
    }
    else if (content_flag == CHAR_FLAG)
    {
        new_content->c = *(char *)new_var;
        new_tail->node_flag = CHAR_FLAG;

        #ifdef DEBUG
            printf("Character %d\n", new_content->c);
        #endif
    }
    else
    {
        result = -1;
    }

    new_tail->node_content = new_content;

    if (*head == NULL)
    {
        *head = new_tail;
    }
    else
    {
        current_node = *head;
        while (current_node->nxt_node_ptr != NULL)
        {
            current_node = current_node->nxt_node_ptr;
        }
        current_node->nxt_node_ptr = new_tail;
    }

    return result;
}

int insert_at(node_t **head, void *new_var, int index,
                                                int content_flag)
{
    int result = 0;
    int i = 1;

    node_t *new_node = NULL;
    node_t *pre_node = NULL;
    node_t *next_node = NULL;

    content_t *new_content = NULL;

    new_node = calloc(1, sizeof(node_t));
    new_content = calloc(1, sizeof(content_t));

    if (content_flag == INT_FLAG)
    {
        new_content->i_num = *(int *)new_var;
        new_node->node_flag = INT_FLAG;

        #ifdef DEBUG
            printf("Integer %d\n", new_content->i_num);
        #endif
    }
    else if (content_flag == FLOAT_FLAG)
    {
        new_content->f_num = *(float *)new_var;
        new_node->node_flag = FLOAT_FLAG;

        #ifdef DEBUG
            printf("Float %d\n", new_content->f_num);
        #endif
    }
    else if (content_flag == CHAR_FLAG)
    {
        new_content->c = *(char *)new_var;
        new_node->node_flag = CHAR_FLAG;

        #ifdef DEBUG
            printf("Character %d\n", new_content->c);
        #endif
    }
    else
    {
        result = -1;
    }

    new_node->node_content = new_content;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else if (index == 0)
    {
        new_node->nxt_node_ptr = *head;
        *head = new_node;
    }
    else
    {
        pre_node = *head;
        next_node = (*head)->nxt_node_ptr;

        while(i < index && pre_node->nxt_node_ptr != NULL)
        {
            pre_node = pre_node->nxt_node_ptr;
            next_node = pre_node->nxt_node_ptr;
            i++;
        }

        pre_node->nxt_node_ptr = new_node;
        new_node->nxt_node_ptr = next_node;
    }

    return result;
}

int delete_beginning(node_t **head)
{
    int result = 0;
    node_t *to_be_removed = NULL;

    if (*head == NULL)
    {
        result = -1;
    }
    else
    {
        to_be_removed = *head;
        *head = (*head)->nxt_node_ptr;

        free(to_be_removed->node_content);
        free(to_be_removed);
    }

    return result;
}

int delete_end(node_t **head)
{
    int result = 0;

    node_t *to_be_removed = NULL;
    node_t *new_tail = NULL;

    if (*head == NULL)
    {
        result = -1;
    }
    else
    {
        to_be_removed = *head;

        while (to_be_removed->nxt_node_ptr != NULL)
        {
            new_tail = to_be_removed;
            to_be_removed = to_be_removed->nxt_node_ptr;
        }
        new_tail->nxt_node_ptr = NULL;

        free(to_be_removed->node_content);
        free(to_be_removed);
    }
}

int delete_at(node_t **head, int index)
{
    int result = 0;
    int i = 1;

    node_t *to_be_removed = NULL;
    node_t *pre_node = NULL;

    if (*head == NULL)
    {
       result = -1;
    }
    else if (index == 0)
    {
        to_be_removed = *head;
        *head = (*head)->nxt_node_ptr;
    }
    else
    {
        pre_node = *head;
        to_be_removed = (*head)->nxt_node_ptr;

        while(i < index && to_be_removed->nxt_node_ptr != NULL)
        {
            pre_node = pre_node->nxt_node_ptr;
            to_be_removed = pre_node->nxt_node_ptr;
            i++;
        }

        pre_node->nxt_node_ptr = to_be_removed->nxt_node_ptr;
    }

    free(to_be_removed->node_content);
    free(to_be_removed);

    return result;
}

int length_of(node_t *head)
{
    int length = 0;
    node_t *temp = NULL;

    while (head != NULL)
    {
        head = head->nxt_node_ptr;
        length++;
    }

    return length;
}

void display_nodes(node_t *head)
{
    int index = 0;

    while (head != NULL)
    {
        printf("%d  |  ", index);

        if (head->node_flag == INT_FLAG)
        {
            printf("Integer Value: %d\n", head->node_content->i_num);
        }
        else if (head->node_flag == FLOAT_FLAG)
        {
            printf("Float Value: %.2f\n", head->node_content->f_num);
        }
        else if (head->node_flag == CHAR_FLAG)
        {
            printf("Charactor Value: %c\n", head->node_content->c);
        }
        else
        {
            printf("ERROR\n");
        }

        head = head->nxt_node_ptr;
        index++;
    }
}

int free_memory(node_t *head)
{
    /*
        This function is used at the end to free the memory of
        all nodes in the linked list as well as the memory of
        the content.
     */
    int result = 0;

    node_t *to_be_removed = NULL;

    while (head != NULL)
    {
        to_be_removed = head;
        head = head->nxt_node_ptr;

        /* Free the node contents' memory */
        free(to_be_removed->node_content);

        /* Free the linked list nodes' memory */
        free(to_be_removed);
    }

    return result;
}

int main(void)
{
    node_t *head = NULL;
    int i_new = 100;
    char c_new = 'A';
    float f_new = 10.01;
    char c_new2 = 'B';
    char c_new3 = 'C';

    insert_beginning(&head, &i_new, INT_FLAG);
    insert_beginning(&head, &c_new, CHAR_FLAG);
    insert_beginning(&head, &f_new, FLOAT_FLAG);

    // insert_end(&head, &c_new2, CHAR_FLAG);
    insert_at(&head, &c_new3, 9, CHAR_FLAG);
    // delete_beginning(&head);
    // delete_end(&head);
    delete_at(&head, 3);

    printf("There are %d nodes\n", length_of(head));
    display_nodes(head);
    free_memory(head);

    return 0;
}