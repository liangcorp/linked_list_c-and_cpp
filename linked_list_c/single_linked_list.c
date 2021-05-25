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

int add_first(node_t **head, void *new_var, int content_flag)
{
    int result = 0;

    node_t *new_head = NULL;
    content_t *new_content = NULL;

    if (*head == NULL)
    {
        new_head = calloc(1, sizeof(node_t));
        new_head->node_flag = content_flag;
        new_head->nxt_node_ptr = NULL;
    }
    else if (*head != NULL && (*head)->node_flag != content_flag)
    {
        #ifdef DEBUG
            printf("Content is not compatible with linked list\n");
        #endif

        result = -1;
    }
    else
    {
        new_head = calloc(1, sizeof(node_t));
        new_head->node_flag = content_flag;
        new_head->nxt_node_ptr = *head;
    }

    if (result != -1)
    {
        new_content = calloc(1, sizeof(content_t));

        if (content_flag == INT_FLAG)
            new_content->i_num = *(int *)new_var;
        else if (content_flag == FLOAT_FLAG)
            new_content->f_num = *(float *)new_var;
        else if (content_flag == CHAR_FLAG)
            new_content->c = *(char *)new_var;
        else
            result = -1;

        new_head->node_content = new_content;
        *head = new_head;
    }

    return result;
}

int add_last(node_t **head, void *new_var, int content_flag)
{
    int result = 0;

    node_t *new_tail = NULL;
    node_t *current_node = NULL;
    content_t *new_content = NULL;

    if (*head == NULL)
    {
        new_tail = calloc(1, sizeof(node_t));
        new_tail->node_flag = content_flag;
        new_tail->nxt_node_ptr = NULL;
    }
    else if (*head != NULL && (*head)->node_flag != content_flag)
    {
        #ifdef DEBUG
            printf("Incompatible variable type\n");
        #endif

        result = -1;
    }
    else
    {
        new_tail = calloc(1, sizeof(node_t));
        new_tail->node_flag = content_flag;
    }


    if (result != -1)
    {
        new_content = calloc(1, sizeof(content_t));

        if (content_flag == INT_FLAG)
            new_content->i_num = *(int *)new_var;
        else if (content_flag == FLOAT_FLAG)
            new_content->f_num = *(float *)new_var;
        else if (content_flag == CHAR_FLAG)
            new_content->c = *(char *)new_var;
        else
            result = -1;

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
    }

    return result;
}

int add_at(node_t **head, void *new_var, int index,
                                                int content_flag)
{
    int result = 0;
    int i = 1;

    node_t *new_node = NULL;
    node_t *pre_node = NULL;
    node_t *next_node = NULL;

    content_t *new_content = NULL;

    if (*head == NULL)
    {
        new_node = calloc(1, sizeof(node_t));
        new_node->node_flag = content_flag;
    }
    else if ((*head)->node_flag != content_flag)
    {
        #ifdef DEBUG
            printf("Incompatible variable type\n");
        #endif

        result = -1;
    }
    else
    {
        new_node = calloc(1, sizeof(node_t));
        new_content = calloc(1, sizeof(content_t));
        new_node->node_flag = content_flag;
    }

    if (result != -1)
    {

        if (content_flag == INT_FLAG)
            new_content->i_num = *(int *)new_var;
        else if (content_flag == FLOAT_FLAG)
            new_content->f_num = *(float *)new_var;
        else if (content_flag == CHAR_FLAG)
            new_content->c = *(char *)new_var;
        else
            result = -1;

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
    }

    return result;
}

int remove_first(node_t **head)
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

int remove_last(node_t **head)
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

int remove_at(node_t **head, int index)
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


    }

    if (i < index && to_be_removed->nxt_node_ptr == NULL)
    {
        #ifdef DEBUG
            printf("Not enough nodes in the linked list\n");
        #endif

        result = -1;
    }
    else
    {
        pre_node->nxt_node_ptr = to_be_removed->nxt_node_ptr;

        free(to_be_removed->node_content);
        free(to_be_removed);
    }

    return result;
}

int sort_aes(node_t **head)
{
    int result = 0;
    int i = 0;
    int no_of_nodes = 0;

    int i_temp = 0;
    float f_temp = 0.0F;
    char c_temp = '\0';

    int i_current = 0;
    int i_next = 0;

    float f_current = 0.0F;
    float f_next = 0.0F;

    char c_current = '\0';
    char c_next = '\0';

    node_t *current_node = NULL;

    current_node = *head;

    while (current_node->nxt_node_ptr != NULL)
    {
        current_node = current_node->nxt_node_ptr;
        no_of_nodes++;
    }
    current_node = *head;

    if ((*head)->node_flag == INT_FLAG)
    {
        for (i = 0; i < no_of_nodes; i++)
        {
            while (current_node->nxt_node_ptr != NULL)
            {
                i_current = current_node->node_content->i_num;
                i_next =
                        current_node->nxt_node_ptr->node_content->i_num;

                if (i_current > i_next)
                {
                    /* swap integer numbers */
                    i_temp = current_node->node_content->i_num;
                    current_node->node_content->i_num =
                        current_node->nxt_node_ptr->node_content->i_num;
                    current_node->nxt_node_ptr->node_content->i_num =
                                                                i_temp;
                }
                current_node = current_node->nxt_node_ptr;
            }
        }
    }
    else if ((*head)->node_flag == FLOAT_FLAG)
    {
        for (i = 0; i < no_of_nodes; i++)
        {
            while (current_node->nxt_node_ptr != NULL)
            {
                f_current = current_node->node_content->f_num;
                f_next =
                        current_node->nxt_node_ptr->node_content->f_num;

                if (f_current > f_next)
                {
                    /* swap float numbers */
                    f_temp = current_node->node_content->f_num;
                    current_node->node_content->f_num =
                        current_node->nxt_node_ptr->node_content->f_num;
                    current_node->nxt_node_ptr->node_content->f_num =
                                                                f_temp;
                }
                current_node = current_node->nxt_node_ptr;
            }
        }
    }
    else if ((*head)->node_flag == CHAR_FLAG)
    {
        for (i = 0; i < no_of_nodes; i++)
        {
            while (current_node->nxt_node_ptr != NULL)
            {
                c_current = current_node->node_content->c;
                c_next = current_node->nxt_node_ptr->node_content->c;

                if (c_current > c_next)
                {
                    /* swap characters */
                    c_temp = current_node->node_content->c;
                    current_node->node_content->c =
                        current_node->nxt_node_ptr->node_content->c;
                    current_node->nxt_node_ptr->node_content->c =
                                                                c_temp;
                }
                current_node = current_node->nxt_node_ptr;
            }
        }
    }
    else
    {
        #ifdef DEBUG
            printf("Unrecognised FLAG\n");
        #endif

        result = -1;
    }

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
    int i_new2 = 1000;
    int i_new3 = 10;
    int i_new4 = 10000;
    int i_new5 = 1;
    char c_new = 'B';
    char c_new2 = 'A';
    char c_new3 = 'C';
    char c_new4 = 'F';
    char c_new5 = 'Z';
    /*
        char c_new = 'A';
        float f_new = 10.01;
        char c_new2 = 'B';

     */
    /*
        add_first(&head, &i_new, INT_FLAG);
        add_first(&head, &i_new2, INT_FLAG);
        add_first(&head, &i_new3, INT_FLAG);

        add_last(&head, &i_new4, INT_FLAG);
        add_at(&head, &i_new5, 0, INT_FLAG);
    */

    add_first(&head, &c_new, CHAR_FLAG);
    add_first(&head, &c_new2, CHAR_FLAG);
    add_last(&head, &c_new3, CHAR_FLAG);
    add_at(&head, &c_new4, 3, CHAR_FLAG);
    add_at(&head, &c_new5, 2, CHAR_FLAG);

    // add_first(&head);
    // remove_at(&head, 4);
    sort_aes(&head);
    printf("There are %d nodes\n", length_of(head));
    display_nodes(head);
    free_memory(head);

    return 0;
}