/**
 * @file single_linked_list.h
 * @author Chen Liang (chen.liang.cn@outlook.com)
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

template <class T> class SingleLinkedList {
    private:
	typedef struct node {
		T *content;
		struct node *next_node_ptr;
	} node_t;

	node_t *head;

	int node_flag;

	static int no_of_nodes;

    public:
	SingleLinkedList();
	SingleLinkedList(T new_var, int node_flag);
	~SingleLinkedList();

	int add_first(T new_var, int node_flag);
	int add_last(T new_var, int node_flag);
	int insert_at(T new_var, int node_flag, int position);

	int delete_first();
	int delete_last();
	int delete_at(int position);

	T get_element(int position);

	int sort_des(); // @todo
	int sort_aes(); // @todo

	static int get_length();

	int get_node_flag();

	void display_nodes();

	int free_memory();
};
