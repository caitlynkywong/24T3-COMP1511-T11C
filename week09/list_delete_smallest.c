// list_delete_smallest.c
// Written by Caitlyn Wong (z5360361) on April 2024
// This function takes in a linked list and removes the node with the
// smallest value from the linked list, returning the new head of the list


struct node *list_delete_smallest(struct node *head) {
    // If the linked list is empty, return NULL
    if (head == NULL) {
        return NULL;
    }

    // If the linked list has only one node, free the memory
    // allocated for the node and return NULL
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    
    // Find node immediately before smallest node
    struct node *current = head;
    struct node *prev_of_smallest = NULL;

    int smallest_data = head->data;
    
    while (current->next != NULL) {
        if (current->next->data < smallest_data) {
            smallest_data = current->next->data;
            prev_of_smallest = current;
        }
        current = current->next;
    }
    
    // Remove smallest node from linked list
    struct node *smallest = NULL;
    if (prev_of_smallest == NULL) {
        // The smallest node is the head of the list
        smallest = head;
        head = head->next;
    } else {
        smallest = prev_of_smallest->next;
        prev_of_smallest->next = smallest->next;
    }
    
    // Free smallest node
    free(smallest);
    
    return head;
}