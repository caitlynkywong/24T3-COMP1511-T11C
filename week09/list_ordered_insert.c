// list_ordered_insert.c
// Written by Caitlyn Wong (z5360361) on April 2024
// This function takes in a linked list that is ordered in ascending order
// and a value to insert, and inserts the value into its appropriate position
// in the list


struct node *list_ordered_insert(struct node *head, int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    
    // Traverse the linked list to find the two nodes the new node should be
    // placed between
    struct node *prev = NULL;
    struct node *current = head;
    while (current != NULL && current->data < value) {
        prev = current;
        current = current->next;
    }
    
    if (prev == NULL) {
        // All values in the existing list are larger than the given value
        new_node->next = head;
        // The new node becomes the new head of the list
        head = new_node;
    } else {
        prev->next = new_node;
        new_node->next = current;
    }
    
    return head;
}