// list_evens.c
// Written by Caitlyn Wong (z5360361) on April 2024
// This function takes in two linked lists and checks if they contain
// at least one even number


int list_evens(struct node *head1, struct node *head2) {
    // Check if list 1 contains at least one even number
    int found1 = 0;
    struct node *current1 = head1;
    while (current1 != NULL) {
        if (current1->data % 2 == 0) {
            found1 = 1;
        }
        current1 = current1->next;
    }

    // Check if list 2 contains at least one even number
    int found2 = 0;
    struct node *current2 = head2;
    while (current2 != NULL) {
        if (current2->data % 2 == 0) {
            found2 = 1;
        }
        current2 = current2->next;
    }

    if (found1 && found2) {
        // Return -1 if both lists contain even numbers
        return -1;
    } else if (found1 || found2) {
        // Return 1 if one list contains even numbers but the other does not
        return 1;
    } else {
        // Return 0 if neither list contains even numbers
        return 0;
    }
}