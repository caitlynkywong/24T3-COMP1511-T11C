// list_count_occurrences.c
// Written by Caitlyn Wong (z5360361) on April 2024
// This function takes in a linked list and a value, and counts the number
// of times that value appears in the list


int list_count_occurrences(struct node *head, int data) {
    int count = 0;

    struct node *current = head;
    while (current != NULL) {
        if (current->data == data) {
            count++;
        }
        current = current->next;
    }

    return count;
}