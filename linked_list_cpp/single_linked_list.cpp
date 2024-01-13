/**
 * @file single_linked_list.cpp
 * @author Chen Liang (chen.liang.cn@outlook.com)
 * @brief Single linked list written in C++
 * @version 0.1
 * @date 2021-05-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include "single_linked_list.h"

using namespace std;

template <typename T> SingleLinkedList<T>::SingleLinkedList()
{
	this->head = nullptr;
	this->node_flag = -1;
	SingleLinkedList::no_of_nodes = 0;
}

template <typename T>
SingleLinkedList<T>::SingleLinkedList(T new_var, int node_flag)
{
	this->head = (node_t *)calloc(1, sizeof(node_t));
	this->head->content = (T *)calloc(1, sizeof(T));

	this->head->next_node_ptr = nullptr;

	*(this->head->content) = new_var;

	this->node_flag = node_flag;

	SingleLinkedList::no_of_nodes = 1;
}

template <typename T> SingleLinkedList<T>::~SingleLinkedList()
{
	// Destructor to free up memory
	this->free_memory();
}

template <typename T> int SingleLinkedList<T>::no_of_nodes = 0;

template <typename T>
int SingleLinkedList<T>::add_first(T new_var, int node_flag)
{
	int result = 0;
	node_t *new_node = nullptr;

	if (this->node_flag != node_flag && this->no_of_nodes != 0) {
		cout << "Incompatible variable type. "
		     << "Variable not added" << endl;
		result = -1;
	} else {
		if (this->no_of_nodes == 0)
			this->node_flag = node_flag;

		new_node = (node_t *)calloc(1, sizeof(node_t));
		new_node->content = (T *)calloc(1, sizeof(T));

		*(new_node->content) = new_var;

		new_node->next_node_ptr = this->head;
		this->head = new_node;

		SingleLinkedList::no_of_nodes++;
	}
	return result;
}

template <typename T>
int SingleLinkedList<T>::add_last(T new_var, int node_flag)
{
	int result = 0;

	node_t *last_node = nullptr;
	node_t *new_node = nullptr;

	if (this->node_flag != node_flag && this->no_of_nodes != 0) {
		result = -1;
	} else {
		new_node = (node_t *)calloc(1, sizeof(node_t));
		new_node->content = (T *)calloc(1, sizeof(T));
		*(new_node->content) = new_var;

		if (this->no_of_nodes == 0) {
			this->node_flag = node_flag;
			this->head = new_node;
		} else {
			last_node = this->head;

			while (last_node->next_node_ptr != NULL) {
				last_node = last_node->next_node_ptr;
			}
			last_node->next_node_ptr = new_node;
		}
		new_node->next_node_ptr = nullptr;

		SingleLinkedList::no_of_nodes++;
	}
	return result;
}

template <typename T>
int SingleLinkedList<T>::insert_at(T new_var, int node_flag, int position)
{
	int result = 0;
	int i = 0;

	node_t *new_node = nullptr;
	node_t *current_node = nullptr;
	node_t *prev_node = nullptr;

	if (this->no_of_nodes < position) {
#ifdef DEBUG
		cout << "Position doesn't exist" << endl;
#endif
		result = -1;
	} else if (this->node_flag != node_flag) {
#ifdef DEBUG
		cout << "Variable flag is different from linked list" << endl;
#endif
		result = -1;
	} else if (position == 0) {
		new_node = (node_t *)calloc(1, sizeof(node_t));
		new_node->content = (T *)calloc(1, sizeof(T));

		*(new_node->content) = new_var;

		new_node->next_node_ptr = this->head;
		this->head = new_node;

		SingleLinkedList::no_of_nodes++;
	} else {
		new_node = (node_t *)calloc(1, sizeof(node_t));
		new_node->content = (T *)calloc(1, sizeof(T));

		*(new_node->content) = new_var;

		current_node = this->head;

		while (current_node->next_node_ptr != nullptr && i < position) {
			prev_node = current_node;
			current_node = current_node->next_node_ptr;
			i++;
		}
		prev_node->next_node_ptr = new_node;
		new_node->next_node_ptr = current_node;

		SingleLinkedList::no_of_nodes++;
	}

	return result;
}

template <typename T> int SingleLinkedList<T>::delete_first()
{
	int result = 0;
	node_t *to_be_removed = nullptr;

	if (this->head == nullptr) {
#ifdef DEBUG
		cout << "Empty Linked List" << endl;
#endif
		result = -1;
	} else if (this->no_of_nodes == 1) {
		to_be_removed = this->head;
	} else {
		to_be_removed = this->head;
		this->head = this->head->next_node_ptr;
	}

	if (result != -1) {
		free(to_be_removed->content);
		free(to_be_removed);
		SingleLinkedList::no_of_nodes--;
	}
	return result;
}

template <typename T> int SingleLinkedList<T>::delete_last()
{
	int result = 0;
	int i = 0;
	node_t *to_be_removed = nullptr;

	if (this->head == nullptr) {
#ifdef DEBUG
		cout << "Empty Linked List" << endl;
#endif
		result = -1;
	} else if (this->head->next_node_ptr == nullptr) {
		to_be_removed = this->head;
	} else {
		to_be_removed = this->head;
		while (to_be_removed->next_node_ptr != nullptr) {
			to_be_removed = to_be_removed->next_node_ptr;
		}
	}

	if (result != -1) {
		free(to_be_removed->content);
		free(to_be_removed);
		SingleLinkedList::no_of_nodes--;
	}

	return result;
}

template <typename T> int SingleLinkedList<T>::delete_at(int position)
{
	int result = 0;
	int i = 0;

	node_t *prev_node = nullptr;
	node_t *to_be_removed = nullptr;
	node_t *next_node = nullptr;

	if (this->head == nullptr) {
#ifdef DEBUG
		cout << "Empty linked list" << endl;
#endif
		result = -1;
	} else if (position == 0) {
		to_be_removed = this->head;
		this->head = this->head->next_node_ptr;
	} else if (position > SingleLinkedList::no_of_nodes) {
#ifdef DEBUG
		cout << "Not enough nodes" << endl;
#endif
		result = -1;
	} else if (this->head->next_node_ptr == nullptr) {
		to_be_removed = this->head;
	} else {
		to_be_removed = this->head;
		for (i = 0; i < position; i++) {
			prev_node = to_be_removed;
			to_be_removed = to_be_removed->next_node_ptr;
			next_node = to_be_removed->next_node_ptr;
		}
		prev_node->next_node_ptr = to_be_removed->next_node_ptr;
	}

	if (result != -1) {
		free(to_be_removed->content);
		free(to_be_removed);
		SingleLinkedList::no_of_nodes--;
	}

	return result;
}

template <typename T> int SingleLinkedList<T>::sort_aes()
{
	int i = 0;
	int result = 0;

	T temp = 0;

	node_t *current_node = nullptr;

	if (this->head == nullptr) {
		result = -1;
	}

	current_node = this->head;

	for (i = 0; i < this->no_of_nodes; i++) {
		while (current_node->next_node_ptr != nullptr) {
			if (*(current_node->content) >
			    *(current_node->next_node_ptr->content)) {
				temp = *(current_node->content);
				*(current_node->content) =
					*(current_node->next_node_ptr->content);
				*(current_node->next_node_ptr->content) = temp;
			}

			current_node = current_node->next_node_ptr;
		}
		current_node = this->head;
	}

	return result;
}

template <typename T> int SingleLinkedList<T>::sort_des()
{
	int i = 0;
	int result = 0;

	T temp = 0;

	node_t *current_node = nullptr;

	if (this->head == nullptr) {
		result = -1;
	}

	current_node = this->head;

	for (i = 0; i < this->no_of_nodes; i++) {
		while (current_node->next_node_ptr != nullptr) {
			if (*(current_node->content) <
			    *(current_node->next_node_ptr->content)) {
				temp = *(current_node->content);
				*(current_node->content) =
					*(current_node->next_node_ptr->content);
				*(current_node->next_node_ptr->content) = temp;
			}

			current_node = current_node->next_node_ptr;
		}
		current_node = this->head;
	}

	return result;
}

template <typename T> int SingleLinkedList<T>::get_length()
{
	return SingleLinkedList::no_of_nodes;
}

template <typename T> int SingleLinkedList<T>::get_node_flag()
{
	return node_flag;
}

template <typename T> T SingleLinkedList<T>::get_element(int position)
{
	T result;
	node_t *current_node = nullptr;
	int i = 0;

	if (this->no_of_nodes > position) {
		current_node = this->head;
		for (i = 0; i < position; i++) {
			current_node = current_node->next_node_ptr;
		}
		result = *(current_node->content);
		cout << result << endl;
	} else {
		result = -1;
	}
	return result;
}

template <typename T> void SingleLinkedList<T>::display_nodes()
{
	node_t *current_node = nullptr;
	current_node = this->head;
	int i = 0;

	for (i = 0; i < this->no_of_nodes; i++) {
		cout << i << "  |  " << *(current_node->content) << endl;
		current_node = current_node->next_node_ptr;
	}
}

template <typename T> int SingleLinkedList<T>::free_memory()
{
	int result = 0;
	int i = 0;

	node_t *to_be_freed = nullptr;

	for (i = 0; i < this->no_of_nodes; i++) {
		to_be_freed = this->head;
		this->head = this->head->next_node_ptr;
		free(to_be_freed->content);
		free(to_be_freed);
	}

	return result;
}

int main(void)
{
	int i_num = 10;
	// SingleLinkedList<int> linked_list(10, INT_FLAG);
	SingleLinkedList<int> linked_list;
	linked_list.add_first(100, INT_FLAG);
	linked_list.add_last(1000, INT_FLAG);
	linked_list.add_last(10, INT_FLAG);
	linked_list.add_last(10, INT_FLAG);
	linked_list.insert_at(10000, INT_FLAG, 1);
	linked_list.insert_at(2, INT_FLAG, 3);
	linked_list.insert_at(166, INT_FLAG, 2);
	// linked_list.delete_first();
	// linked_list.delete_last();
	// linked_list.delete_at(3);
	linked_list.sort_aes();
	linked_list.sort_des();

	cout << "No of nodes is " << linked_list.get_length() << endl;

	linked_list.display_nodes();

	cout << "First element is " << linked_list.get_element(0) << endl;
	cout << "Second element is " << linked_list.get_element(1) << endl;

	return 0;
}
