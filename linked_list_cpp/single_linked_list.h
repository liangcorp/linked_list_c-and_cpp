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

class SingleLinkedList
{
    private:
        typedef struct node
        {
            int num;
            struct node *next_node_ptr;
        } node_t;

        static int no_of_element;

    public:
        int add_first(node_t **head);
        int add_last(node_t **head);
        int add_at(node_t **head, int position);

        int delete_first(node_t **head);
        int delete_last(node_t **head);
        int delete_at(node_t **head, int position);

        int get_element(node_t **head, int position);

        int sort_des(node_t **head);
        int sort_aes(node_t **head);

        static int length_of();

        int free_memory(node_t **head);
};