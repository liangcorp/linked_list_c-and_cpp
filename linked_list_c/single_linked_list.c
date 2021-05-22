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

/* User flag to mark which element is active in the union */
#define INT_FLAG 0
#define FLOAT_FLAG 1
#define CHAR_FLAG 2

typedef union content
{
    int i_num;
    float f_num;
    char c;
} content_t;

typedef struct element
{
    content_t *ele_content;
    int ele_flag;
    struct element *nxt_ele_ptr;
} element_t;

int insert_beginning(element_t **head, void *new_var, int content_flag);
int insert_end(element_t **head, void *new_var, int content_flag);
int insert_at(element_t **head, void *new_var, int index,
                                                int content_flag);

int delete_beginning(element_t **head);
int delete_end(element_t **head);
int delete_at(element_t **head, int index);

int length_of(element_t *head);

void display_elements(element_t *head);

int free_memory(element_t *head);

int main(void)
{
    element_t *head = NULL;
    int i_new = 100;
    char c_new = 'A';
    float f_new = 10.01;
    char c_new2 = 'B';
    insert_beginning(&head, &i_new, INT_FLAG);
    insert_beginning(&head, &c_new, CHAR_FLAG);
    insert_beginning(&head, &f_new, FLOAT_FLAG);

    insert_end(&head, &c_new2, CHAR_FLAG);

    printf("There are %d elements\n", length_of(head));
    display_elements(head);
    free_memory(head);

    return 0;
}

int insert_beginning(element_t **head, void *new_var, int content_flag)
{
    int result = 0;

    element_t *new_head = NULL;
    content_t *new_content = NULL;

    new_head = calloc(1, sizeof(element_t));
    new_content = calloc(1, sizeof(content_t));

    /*
        Using union maybe a bad idea.
     */

    if (content_flag == INT_FLAG)
    {
        new_content->i_num = *(int *)new_var;
        new_head->ele_flag = INT_FLAG;

        #ifdef DEBUG
            printf("Integer %d\n", new_content->i_num);
        #endif
    }
    else if (content_flag == FLOAT_FLAG)
    {
        new_content->f_num = *(float *)new_var;
        new_head->ele_flag = FLOAT_FLAG;

        #ifdef DEBUG
            printf("Float %d\n", new_content->f_num);
        #endif
    }
    else if (content_flag == CHAR_FLAG)
    {
        new_content->c = *(char *)new_var;
        new_head->ele_flag = CHAR_FLAG;

        #ifdef DEBUG
            printf("Character %d\n", new_content->c);
        #endif
    }
    else
    {
        result = -1;
    }

    new_head->ele_content = new_content;

    if (*head != NULL)
    {
        new_head->nxt_ele_ptr = *head;
    }
    else
    {
        new_head->nxt_ele_ptr = NULL;
    }

    *head = new_head;

    return result;
}

int insert_end(element_t **head, void *new_var, int content_flag)
{
    int result = 0;

    element_t *new_tail = NULL;
    element_t *current_element = NULL;
    content_t *new_content = NULL;

    new_tail = calloc(1, sizeof(element_t));
    new_content = calloc(1, sizeof(content_t));

    if (content_flag == INT_FLAG)
    {
        new_content->i_num = *(int *)new_var;
        new_tail->ele_flag = INT_FLAG;

        #ifdef DEBUG
            printf("Integer %d\n", new_content->i_num);
        #endif
    }
    else if (content_flag == FLOAT_FLAG)
    {
        new_content->f_num = *(float *)new_var;
        new_tail->ele_flag = FLOAT_FLAG;

        #ifdef DEBUG
            printf("Float %d\n", new_content->f_num);
        #endif
    }
    else if (content_flag == CHAR_FLAG)
    {
        new_content->c = *(char *)new_var;
        new_tail->ele_flag = CHAR_FLAG;

        #ifdef DEBUG
            printf("Character %d\n", new_content->c);
        #endif
    }
    else
    {
        result = -1;
    }

    new_tail->ele_content = new_content;

    if (*head == NULL)
    {
        *head = new_tail;
    }
    else
    {
        current_element = *head;
        while (current_element->nxt_ele_ptr != NULL)
        {
            current_element = current_element->nxt_ele_ptr;
        }
        current_element->nxt_ele_ptr = new_tail;
    }

    return result;
}


int length_of(element_t *head)
{
    int length = 0;
    element_t *temp = NULL;

    while (head != NULL)
    {
        head = head->nxt_ele_ptr;
        length++;
    }

    return length;
}

void display_elements(element_t *head)
{
    int index = 0;

    while (head != NULL)
    {
        printf("%d  |  ", index);

        if (head->ele_flag == INT_FLAG)
        {
            printf("Integer Value: %d\n", head->ele_content->i_num);
        }
        else if (head->ele_flag == FLOAT_FLAG)
        {
            printf("Float Value: %.2f\n", head->ele_content->f_num);
        }
        else if (head->ele_flag == CHAR_FLAG)
        {
            printf("Charactor Value: %c\n", head->ele_content->c);
        }
        else
        {
            printf("ERROR\n");
        }

        head = head->nxt_ele_ptr;
        index++;
    }
}

int free_memory(element_t *head)
{
    /*
        This function is used at the end to free the memory of
        all elements in the linked list as well as the memory of
        the content.
     */
    element_t *to_be_removed = NULL;

    while (head != NULL)
    {
        to_be_removed = head;
        head = head->nxt_ele_ptr;

        /* Free the element contents' memory */
        free(to_be_removed->ele_content);

        /* Free the linked list elements' memory */
        free(to_be_removed);
    }

    return 0;
}
