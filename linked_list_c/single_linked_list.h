/* User flag to mark which element is active in the union */
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
