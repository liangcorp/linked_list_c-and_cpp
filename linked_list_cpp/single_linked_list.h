/**
 * @file single_linked_list.h
 * @author Chen Liang (chen.liang.mail@protonmail.com)
 * @brief Header file for the single linked list written in C++
 * @version 0.1
 * @date 2021-05-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#define INT_FLAG 0
#define FLOAT_FLAG 1
#define CHAR_FLAG 2

class SingleLinkedList
{
    private:
        typedef union content
        {
            int i_num;
            float f_num;
            char c;
        } content_t;

        typedef struct node
        {
            content_t *content;
            struct node *next_node_ptr;
        } node_t;

        node_t *head;

        int node_flag;

        static int no_of_nodes;

    public:
        SingleLinkedList();
        SingleLinkedList(int node_flag);
        SingleLinkedList(void *new_var, int node_flag);

        int add_first(node_t **head);
        int add_last(node_t **head);
        int add_at(node_t **head, int position);

        int delete_first(node_t **head);
        int delete_last(node_t **head);
        int delete_at(node_t **head, int position);

        void * get_element(int position);

        int sort_des(node_t **head);
        int sort_aes(node_t **head);

        static int get_length();

        int get_node_flag();

        int free_memory();
};