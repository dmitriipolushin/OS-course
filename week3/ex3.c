#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

void print_list(struct Node* n) 
{
    if (n->next == NULL) 
    {
        printf("%d", n->data);
        printf("\n");
        return;
    }
    else
    {
        printf("%d ", n->data);
        struct Node* next = n->next;
        print_list(next);
    }
}

void insert_node(struct Node* list, int data)
{
    struct Node* curr = list;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    struct Node* new;
    new = malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    curr->next = new;
}

/*
function to delete node by index
if index is in the list it will be delete
else it will be do nothing
*/
void delete_node(struct Node* list, int index) 
{
    struct Node* curr = list;
    for (int i = 0; i < index-1; i++)
    {
        if (curr->next != NULL)
            curr = curr->next;
    }
    if (curr->next != NULL)
    {
        struct Node* splittedNode = (curr->next)->next;
        curr->next = splittedNode;
    }
    else
    {
        curr = NULL;
    }
}

int main(int argc, char const *argv[])
{
    struct Node* list;
    list = malloc(sizeof(struct Node));
    list->data = 1;
    list->next = NULL;
    insert_node(list, 2);
    insert_node(list, 3);
    insert_node(list, 5);
    insert_node(list, 7);
    insert_node(list, 8);
    printf("list: \n");
    print_list(list);
    printf("delete element index 1: \n");
    delete_node(list, 1);
    print_list(list);
    printf("delete element index 3: \n");
    delete_node(list, 3);
    print_list(list);
    return 0;
}
