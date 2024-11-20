// list_reverse.c
// Written by Caitlyn Wong (z5360361) on April 2024
// This function takes in a linked list and reverses the list,
// returning the new head of the list


struct node *list_reverse(struct node *head) {
    struct node *prev = NULL;
    struct node *current = head
    struct node *next = NULL;

    while (current != NULL) {
        // Store the address of the next node
        next = current->next;

        // Update the current node to point to the previous node
        current->next = prev;

        // Store the address of the current node
        prev = current;

        // Traverse to the original next node
        current = next;
    }
    
    return prev;
}