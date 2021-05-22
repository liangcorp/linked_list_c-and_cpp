#include <stdio.h>
#include "single_linked_list.h"

int main(void)
{
    element_t *head = NULL;
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

    printf("There are %d elements\n", length_of(head));
    display_elements(head);
    free_memory(head);

    return 0;
}