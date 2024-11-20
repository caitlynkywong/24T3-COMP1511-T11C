// list_copy.c
// Written by Caitlyn Wong (z5360361) on April 2024
// This function takes in a linked list and makes a copy of it,
// freeing the old list and returning the head of the copy


struct node *list_copy(struct node *head) {
    // If the linked list is empty, return NULL
    if (head == NULL) {
        return head;
    }

    struct node *current = head; 
    struct node *new_head = NULL; 
    struct node *new_tail = NULL;
    struct node *node_copy;
    
    // Make a copy of the linked list
    while (current != NULL) {
        node_copy = malloc(sizeof(struct node));
        node_copy->data = current->data;
        node_copy->next = NULL;
        
        if (new_head == NULL) {
            new_head = node_copy;
            new_tail = node_copy;
        } else {
            new_tail->next = node_copy;
            new_tail = node_copy;
        }
        
        current = current->next;
    }
    
    // Free the old linked list
    current = head;
    struct node *temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    
    return new_head;
}