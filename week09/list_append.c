// list_append.c
// Written by Caitlyn Wong (z5360361) on April 2024
// This function takes in two linked lists and appends the second list
// to the first list


struct node *list_append(struct node *head1, struct node *head2) {
    // If the first list is empty, return the head of the second list
    if (head1 == NULL) {
        return head2;
    }

    // Traverse the first list to find the last node
    struct node *current = head1;
    while (current->next != NULL) {
        current = current->next;
    }

    // Append the head of the second list to the tail of the first list
    current->next = head2;

    return head1;
}